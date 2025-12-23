#include "CustomFont.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <filesystem>
#include "grcImage.h"
#include "SystemManager.h"

#include "SWFTypes.h"
#include "HookLib.h"
#include "Logger.h"

using namespace HookLib;

static std::unordered_set<std::string> g_dumpFonts;
void DumpSwfFont(swfFont* font, const char* prefixFileName) {
	// dump font
	std::string fileNameStr = std::format("{}_{}.txt", prefixFileName, (void*)font);
	if (g_dumpFonts.contains(fileNameStr))
		return;

	g_dumpFonts.insert(fileNameStr);
	logFormat("try dump font to file: %s", fileNameStr.c_str());

	std::ofstream stream(fileNameStr.c_str(), std::ios::out | std::ios::trunc);
	logFormat("open stream file!");

	auto sheet = font->sheet;
	cw("sheet: %p", sheet);
	if (sheet == nullptr) {
		cw("sheet is null!");
		stream.close();
		return;
	}

	stream << std::format("font address={}\n", (void*)font);
	stream << std::format("sheet size= {}\n", font->sheet->size);
	stream << std::format("ascent= {}, decent= {}, leading= {}\n",
		font->ascent, font->descent, font->leading);
	stream << std::format("sheet cell count= {}\n", sheet->cellCount);
	stream << std::format("sheet texture count= {}\n", sheet->textureCount);

	auto glyphArrayFirstElement = (swfGlyph**)sheet->glyphArray;

	for (int i = 0;i < font->glyphCount;i++)
	{
		unsigned short currentCode = font->glyphToCodeArrayFirstItem[i];
		auto gAddress = (uintptr_t)glyphArrayFirstElement + i * sizeof(swfGlyph);
		auto g = (swfGlyph*)gAddress;
		auto line = std::format(
			"index={}, char={}, left={:.2f}, top={:.2f}, width={:.2f}, height={:.2f}",
			i, currentCode, g->left, g->top, g->width, g->height);

		float minX = g->minX;
		float minY = g->minY;
		float maxX = g->maxX;
		float maxY = g->maxY;
		float advance = *((float*)font->advanceArray + i);
		line += std::format(
			", minX={:.2f}, minY={:.2f}, maxX={:.2f}, maxY={:.2f}, advance={:.2f}",
			minX, minY, maxX, maxY, advance);

		stream << line.c_str() << "\n";
	}
	stream.close();
	logFormat("dump success for font file name: %s", fileNameStr.c_str());
}

float toUnitSheetSize(float pixels, float fontSize) {
	return (pixels * 1024.0f) / fontSize;
}


grcTextureD11* rage_grcTextureD11Create(const char* assetName)
{
	auto instance = grcTextureFactoryD11::GetInstance();
	return instance->CreateTexture(assetName, nullptr);
}
