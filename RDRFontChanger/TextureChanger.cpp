#include "TextureChanger.h"
#include "HookLib.h"
#include "grcImage.h"
#include <filesystem>
#include <string>
#include <vector>
#include <string>
#include "StringLib.h"
#include "Rage.h"

namespace fs = std::filesystem;

using namespace HookLib;

TextureReplacer* TextureReplacer::g_instance;
const char* TextureReplacer::k_modsReplaceTeturesDir = "mods/replace_textures"; // default

void* (*fn_grcTextureD11_CreateFromBackingStore)(grcTextureD11* self);
void* HK_grcTextureD11_CreateFromBackingStore(grcTextureD11* self) {
	cw("BeginHook HK_grcTextureD11_CreateFromBackingStore, self: %p", self);

	self->BeforeCreateFromBackingStore();

	// replace here
	TextureReplacer::Instance()->OnBeforeCreateFromBackingStore(self);

	auto r = fn_grcTextureD11_CreateFromBackingStore(self);
	self->AfterCreateFromBackingStore();

	cw("EndHook HK_grcTextureD11_CreateFromBackingStore");
	return r;
}

TextureReplacer::TextureReplacer()
{
	g_instance = this;
}

bool TextureReplacer::Init()
{
	SetupHooks();
	LoadDefaultTextureFiles();
	return true;
}

void TextureReplacer::OnBeforeCreateFromBackingStore(grcTextureD11* tex)
{
	auto textureKey = tex->GetName();
	if (m_registerReplaceTextureMap.contains(textureKey) == false) {
		return;
	}

	auto redirectNewTexturePath = m_registerReplaceTextureMap[textureKey];
	cw("try replace texture: %s", textureKey.c_str());
	cw("try to read file: %s", redirectNewTexturePath.c_str());

	DirectX::ScratchImage img;
	auto filePathSystem = fs::path(redirectNewTexturePath);
	auto wFilePath = filePathSystem.wstring();
	HRESULT hr = DirectX::LoadFromDDSFile(
		wFilePath.data(),
		DirectX::DDS_FLAGS::DDS_FLAGS_NONE,
		nullptr, img);

	if (FAILED(hr)) {
		cw("error to LoadFromDDSFile");
		return;
	}

	// check image it match metadata
	auto meta = img.GetMetadata();
	// Todo: need to check fourCC and dxgi format this!
	bool isMatchMetadata =
		meta.mipLevels == tex->mipmap
		&& meta.width == tex->width
		&& meta.height == tex->height;

	if (!isMatchMetadata) {
		cw("error dds meta not match!");
		cw("new texture meta info...");
		cw("size:   %d - %d", meta.width, meta.height);
		cw("mipmap: %d", meta.mipLevels);
		cw("format: 0x%x | name: %s", meta.format, DxgiFormatToString(meta.format));
		cw("and here your current texture info...");
		tex->LogInfo();
		return;
	}


	// ready to change new raw data of dds file!!
	auto oldRawImage = tex->rawImage;
	auto newRawImage = img.GetPixels();
	tex->rawImage = newRawImage;
	cw("set rawImage!! old: %p, new: %p!!", oldRawImage, newRawImage);

	// add to cache
	m_scratchImageMap.emplace(textureKey, std::move(img));
}

void TextureReplacer::RegisterReplaceTexture(
	std::string textureKey, std::string path)
{
	textureKey = SafePath(textureKey);
	path = SafePath(path);

	cw("try register texture path: %s", path.c_str());
	if (fs::exists(path) == false) {
		cw("error file path not exist");
		return;
	}

	// ready
	m_registerReplaceTextureMap[textureKey] = path;

	// debug
	cw("registered texture key: %s with new path: %s",
		textureKey.c_str(), path.c_str());
}

std::unordered_set<std::string> GetAllTextureDDSFiles(std::string dirToLoad)
{
	std::unordered_set<std::string> files;

	if (fs::exists(dirToLoad) && fs::is_directory(dirToLoad)) {
		for (const auto& entry : fs::recursive_directory_iterator(dirToLoad)) {
			auto path = entry.path();
			auto filename = path.filename();
			if (fs::is_regular_file(entry) && path.extension() == ".dds") {
				auto pathString = path.string();
				files.insert(pathString);
			}
		}
	}

	return files;
}

void TextureReplacer::SetupHooks()
{
	// setup hooks
	HookRva(0x1543c0, HK_grcTextureD11_CreateFromBackingStore,
		&fn_grcTextureD11_CreateFromBackingStore);
}

void TextureReplacer::LoadDefaultTextureFiles()
{
	cw("try loading default texture replace files...");
	const char* modsDir = "mods";
	auto textureFiles = GetAllTextureDDSFiles(k_modsReplaceTeturesDir);
	cw("found replace texture name count: %d", textureFiles.size());
	for (auto& file : textureFiles) {
		auto textureKeyPath = fs::relative(file, k_modsReplaceTeturesDir);
		auto textureKey = textureKeyPath.string();
		RegisterReplaceTexture(textureKey, file);
	}
}

