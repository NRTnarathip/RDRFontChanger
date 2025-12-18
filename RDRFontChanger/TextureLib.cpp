#include "TextureLib.h"
#include "Logger.h"
#include "grcImage.h"
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "DXLib.h"

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

