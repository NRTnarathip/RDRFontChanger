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
void TryDumpSwfFont(swfFont* font, const char* prefixFileName) {
	// dump font
	std::string fileNameStr = std::format("{}_{}.txt", prefixFileName, (void*)font);
	if (g_dumpFonts.contains(fileNameStr))
		return;

	g_dumpFonts.insert(fileNameStr);
	logFormat("try dump font to file: %s", fileNameStr.c_str());

	std::ofstream stream(fileNameStr.c_str(), std::ios::out | std::ios::trunc);
	logFormat("open stream file!");

	stream << std::format("font address={}\n", (void*)font);

	auto sheet = font->sheetArrayPtr;
	cw("sheet: %p", sheet);
	if (sheet == nullptr) {
		cw("sheet is null!");
		stream.close();
		return;
	}

	cw("cell count: 5d", sheet->cellCount);
	stream << std::format("sheet size count= {}\n", sheet->size);
	stream << std::format("sheet cell count= {}\n", sheet->cellCount);
	stream << std::format("sheet texture count= {}\n", sheet->textureCount);

	auto glyphArrayFirstElement = (swfGlyph**)sheet->cellArray;

	for (int i = 0;i < font->glyphCount;i++)
	{
		unsigned short currentCode = font->glyphToCodeArrayFirstItem[i];
		auto gAddress = (uintptr_t)glyphArrayFirstElement + i * sizeof(swfGlyph);
		auto g = (swfGlyph*)gAddress;
		auto line = std::format(
			"index={}, char={}, left={:.2f}, top={:.2f}, width={:.2f}, height={:.2f}",
			i, currentCode, g->left, g->top, g->width, g->height);

		line += std::format(
			", minX={:.2f}, minY={:.2f}, maxX={:.2f}, maxY={:.2f}",
			g->minX, g->minY, g->maxX, g->maxY);

		stream << line.c_str() << "\n";

		float advance = *((float*)font->advanceFirstItem + i);
		auto line2 = std::format("advance={}\n", advance);
		stream << line2;
	}
	stream.close();
	logFormat("dump success for font file name: %s", fileNameStr.c_str());
}

const float k_swfFontUnitSize = 1024.0f;

CustomFont::CustomFont(swfFont* font)
{
	this->font = font;
}

void CustomFont::ReplaceGlyph(swfFont* font,
	const BitmapFont& thaiFont, const BitmapFont::Glyph& newGlyph)
{
	cw("try replace glyph id: %d", newGlyph.id);

	// assert
	if (newGlyph.id < 0 || newGlyph.id > 0xFFFF) {
		cw("bitmap glyph charCode overflow unsigned short");
		return;
	}

	auto sheet = font->sheetArrayPtr;
	if (sheet == nullptr) {
		cw("sheet font is null!");
		return;
	}

	auto glyphIndex = this->replaceGlyphCount;
	if (glyphIndex == font->glyphCount - 1) {
		cw("glyph count is full!");
		return;
	}

	int fontHeight = sheet->size; // or font height size
	cw("sheet size: %d", sheet->size);

	float fontScaleEM = k_swfFontUnitSize / thaiFont.size;
	cw("font scale em: %.2f", fontScaleEM);

	// setup min, max bound on swf font size em
	float xoffset = newGlyph.xoffset;
	float yoffset = newGlyph.yoffset;

	float minX = newGlyph.xoffset * fontScaleEM;
	float maxX = (newGlyph.xoffset + newGlyph.width) * fontScaleEM;

	float minY = -(yoffset + newGlyph.height) * fontScaleEM;
	float maxY = -yoffset * fontScaleEM;


	// change it!
	swfGlyph* glyphArray = (swfGlyph*)sheet->cellArray;
	swfGlyph* g = glyphArray + glyphIndex;
	g->left = newGlyph.x;
	g->top = newGlyph.y;
	g->width = newGlyph.width;
	g->height = newGlyph.height;
	g->minX = minX;
	g->minY = minY;
	g->maxX = maxX;
	g->maxY = maxY;


	// update glyph advanceX array
	float advanceX = newGlyph.xadvance * fontScaleEM;
	float* advanceArray = (float*)font->advanceFirstItem;
	advanceArray[glyphIndex] = advanceX;
	cw("advanceX: %.2f", advanceX);

	// update glyphToCode 
	unsigned short* glyphToCodeArray = font->glyphToCodeArrayFirstItem;
	glyphToCodeArray[glyphIndex] = (unsigned short)newGlyph.id;

	// counter glyph replace!
	this->replaceGlyphCount++;


	cw("info: x:%d, y:%d, w:%d, h:%d", (int)g->left, (int)g->top, (int)g->width, (int)g->height);
	cw("bound: minX:%.2f, minY:%.2f, maxX:%.2f, maxY:%.2f", g->minX, g->minY, g->maxX, g->maxY);
	cw("Registered replace font: %p", font);

}

grcTextureD11* rage_grcTextureD11Create(const char* assetName)
{
	auto instance = grcTextureFactoryD11::GetInstance();
	return instance->CreateTexture(assetName, nullptr);
}

void CustomFont::ReplaceTexture(int replaceTextureIndex, std::string newTextureFilePath)
{
	cw("try ReplaceTexture index: %d, path: %s", replaceTextureIndex, newTextureFilePath.c_str());
	auto sheet = font->sheetArrayPtr;
	if (replaceTextureIndex < 0
		|| replaceTextureIndex >= sheet->textureCount) {
		cw("texture index is over than texture count");
		return;
	}

	auto i = replaceTextureIndex;
	grcTextureD11* originalTexture = sheet->textureArray[i];
	const char* originalName = sheet->textureNameArray[i];
	// backup it before change!
	this->backupTextureArray.push_back(originalTexture);
	this->backupTextureNameArray.push_back(originalName);
	cw("texture original: %p, name: %s", originalTexture, originalName);

	// change it!!
	auto imgFactory = grcTextureFactoryD11::GetInstance();
	grcTextureD11* newTexture = rage_grcTextureD11Create(newTextureFilePath.c_str());
	cw("create new texture: %p", newTexture);

	this->newTextures.push_back(newTexture);
	this->newTextureFileNames.push_back(newTextureFilePath);
	sheet->textureArray[i] = newTexture;
	auto newTextureNameObj = &this->newTextureFileNames[i];
	sheet->textureNameArray[i] = newTextureNameObj->c_str();
	cw("texture after replace: %p, name: %s",
		sheet->textureArray[i],
		sheet->textureNameArray[i]);


	// check index
	cw("sheet index array: %p", sheet->indexArray);
}

void BitmapFont::ParseGlyph(const std::string& line, BitmapFont::Glyph& g) {
	auto lineCstr = line.c_str();
	sscanf(lineCstr, "char id=%d x=%d y=%d width=%d height=%d xoffset=%d yoffset=%d xadvance=%d page=%d chnl=%d",
		&g.id, &g.x, &g.y, &g.width, &g.height,
		&g.xoffset, &g.yoffset, &g.xadvance, &g.page, &g.chnl);
}

void BitmapFont::Load(std::string path)
{
	if (isLoaded)
		return;
	isLoaded = true;

	std::ifstream file(path);
	std::string line;

	while (std::getline(file, line)) {
		auto lineCstr = line.c_str();
		// parse line
		if (line.find("char id=") == 0) {
			Glyph g;
			ParseGlyph(line, g);
			this->glyphs.push_back(g);
		}
		else if (line.find("common") == 0) {
			sscanf(lineCstr, "common lineHeight=%d base=%d scaleW=%d scaleH=%d",
				&lineHeight, &baseline, &scaleW, &scaleH);
		}
		else if (line.find("info") == 0) {
			sscanf(lineCstr, "info face=\"%[^\"]\" size=%d bold=%d italic=%d",
				face, &size, &bold, &italic);
			fontName = face;
		}
	}
	logFormat("loaded bitmap font name: %s, size: %d", fontName, size);
}
