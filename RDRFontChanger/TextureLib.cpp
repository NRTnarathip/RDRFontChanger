#include "TextureLib.h"
#include "Logger.h"
#include "grcImage.h"
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "DXLib.h"
#include <filesystem>
#include "HookLib.h"
#include <string>
#include "StringLib.h"
#include "Rage.h"
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "DirectXTex.h"
#include "ISystem.h"

namespace fs = std::filesystem;

void TrySaveTextureForCC0x32(grcTextureD11* tex) {
	cw("try save into png...");
	auto name = tex->GetName();
	cw("tex name: %s", name);

	bool support = true;
	cw("fourCC name: %s", DxgiFormatToString(tex->fourCC));
	// convert back to 0x3D
	if (tex->fourCC != 0x32)
		support = false;

	// check if support
	if (!support) {
		cw("not support this texture!");
		return;
	}


	auto width = tex->width;
	auto height = tex->height;
	std::string saveDir = "dump";
	auto saveFilePath = saveDir + "/" + name + ".png";
	cw("try save file to path: %s", saveFilePath.c_str());

	uint8_t* rawImage = (uint8_t*)tex->rawImage;
	if (rawImage == nullptr) {
		cw("raw image it's null");
		return;
	}

	std::vector<uint8_t> savePixels(width * height * 4);
	for (int i = 0; i < width * height; i++)
	{
		int dstIdx = i * 4;
		uint8_t r = rawImage[i];
		savePixels[dstIdx + 0] = r;   // R
		savePixels[dstIdx + 1] = r;   // G
		savePixels[dstIdx + 2] = r;   // B
		savePixels[dstIdx + 3] = 255; // A
	}

	stbi_write_png(saveFilePath.c_str(),
		width, height, // size
		4, // rgba
		savePixels.data(),// pixels
		width * 4 // stride
	);

	cw("saved path: %s", saveFilePath.c_str());
}

std::unordered_map<std::string, DirectX::ScratchImage> m_scratchImageMap;

grcTextureD11* TryLoadTextureD11(const char* path)
{
	cw("TryLoadTextureD11");
	cw("try to read file: %s", path);
	if (std::filesystem::exists(path) == false) {
		pn("failed load texture, file not found: {}", path);
		return nullptr;
	}

	auto instance = grcTextureFactoryD11::GetInstance();
	grcTextureD11* tex = instance->CreateTexture(path, 0);

	auto textureKey = tex->GetName();
	cw("texture key: %s", textureKey.c_str());

	DirectX::ScratchImage img;
	auto filePathSystem = fs::path(path);
	auto wFilePath = filePathSystem.wstring();
	HRESULT hr = DirectX::LoadFromDDSFile(
		wFilePath.data(),
		DirectX::DDS_FLAGS::DDS_FLAGS_NONE,
		nullptr, img);

	if (FAILED(hr)) {
		cw("error to LoadFromDDSFile");
		return nullptr;
	}

	// check image it match metadata
	auto meta = img.GetMetadata();
	// Todo: need to check fourCC and dxgi format this!
	bool isMatchMetadata =
		meta.mipLevels == tex->mipmap
		&& meta.width == tex->width
		&& meta.height == tex->height;

	cw("new texture meta info...");
	cw("size:   %d - %d", meta.width, meta.height);
	cw("mipmap: %d", meta.mipLevels);
	cw("format: 0x%x | name: %s", meta.format, DxgiFormatToString(meta.format));
	cw("and here your current texture info...");
	tex->LogInfo();


	// ready to change new raw data of dds file!!
	auto oldRawImage = tex->rawImage;
	auto newRawImage = img.GetPixels();
	tex->rawImage = newRawImage;
	cw("set rawImage!! old: %p, new: %p!!", oldRawImage, newRawImage);

	// add to cache
	pn("try call CreateFromBackingStore...");
	HookLib::InvokeRva<void*, grcTextureD11*>(0x1543c0, tex);
	tex->rawImage = 0;
	pn("done CreateFromBackingStore!!");
	tex->LogInfo();
	m_scratchImageMap.emplace(textureKey, std::move(img));
	return tex;
}

