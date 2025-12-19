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

float to1024Units(float pixels, float fontSize) {
	return (pixels * 1024.0f) / fontSize;
}


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

	auto glyphArrayFirstElement = (swfGlyph**)sheet->cellArrayPtr;

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
		float advance = *((float*)font->advanceFirstItem + i);
		line += std::format(
			", minX={:.2f}, minY={:.2f}, maxX={:.2f}, maxY={:.2f}, advance={:.2f}",
			minX, minY, maxX, maxY, advance);

		stream << line.c_str() << "\n";
	}
	stream.close();
	logFormat("dump success for font file name: %s", fileNameStr.c_str());
}

CustomFont::CustomFont(swfFont* gameFont, BitmapFont* bitmapFont)
{
	this->bitmapFont = bitmapFont;
	this->originalFont = gameFont;
	DumpSwfFont(originalFont, "MainFont");

	// replace all glyph
	cw("try replace all glyph...");
	this->backupGlyphToCode = gameFont->glyphToCodeArrayFirstItem;
	this->backupGlyphCount = gameFont->glyphCount;

	auto sheet = gameFont->sheet;

	// ready to replace
	for (int i = 0;i < bitmapFont->glyphs.size();i++) {
		auto& newGlyph = bitmapFont->glyphs[i];
		ReplaceGlyph(gameFont, *bitmapFont, newGlyph);
	}

}

void CustomFont::ReplaceGlyph(swfFont* font,
	const BitmapFont& bitmapFont, const BitmapFont::Glyph& glyph)
{
	cw("try replace glyph id: %d", glyph.id);

	// assert
	if (glyph.id < 0 || glyph.id > 0xFFFF) {
		cw("bitmap glyph charCode overflow unsigned short");
		return;
	}

	auto sheet = font->sheet;

	auto glyphIndex = this->replaceGlyphCount;
	if (glyphIndex == font->glyphCount - 1) {
		cw("glyph count is full!");
		return;
	}

	// counter glyph replace!
	this->replaceGlyphCount++;
	cw("sheet size: %d", sheet->size);

	// setup min, max bound on swf font size em
	float xoffset = glyph.xoffset;
	float yoffset = glyph.yoffset;

	// X
	float fontSize = bitmapFont.size;
	float minX = to1024Units(glyph.xoffset, fontSize);
	float maxX = to1024Units(glyph.xoffset + glyph.width, fontSize);

	float baseline = bitmapFont.baseline;
	float lineHeight = bitmapFont.lineHeight;
	float pixelTop = baseline - yoffset;
	float pixelBottom = baseline - yoffset - glyph.height;
	float minY = to1024Units(-pixelTop, fontSize);
	float maxY = to1024Units(-pixelBottom, fontSize);

	font->ascent = to1024Units(baseline, fontSize);
	font->descent = to1024Units(lineHeight - baseline, fontSize);
	font->leading = to1024Units(0.0f, fontSize);


	// change it!
	swfGlyph* g = sheet->cellArrayPtr + glyphIndex;
	g->left = glyph.x;
	g->top = glyph.y;
	g->width = glyph.width;
	g->height = glyph.height;
	g->minX = minX;
	g->minY = minY;
	g->maxX = maxX;
	g->maxY = maxY;


	// update glyph advanceX array
	float advanceX = to1024Units(glyph.xadvance, fontSize);
	font->advanceFirstItem[glyphIndex] = advanceX;
	cw("advanceX: %.2f", advanceX);

	//// update glyphToCode 
	font->glyphToCodeArrayFirstItem[glyphIndex] = (unsigned short)glyph.id;
	cw("replace glyph index[%d] = charCode: %d", glyphIndex, glyph.id);



	cw("info glyph: x:%d, y:%d, w:%d, h:%d", (int)g->left, (int)g->top, (int)g->width, (int)g->height);
	cw("bound: minX:%.2f, minY:%.2f, maxX:%.2f, maxY:%.2f", g->minX, g->minY, g->maxX, g->maxY);
}

grcTextureD11* rage_grcTextureD11Create(const char* assetName)
{
	auto instance = grcTextureFactoryD11::GetInstance();
	return instance->CreateTexture(assetName, nullptr);
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
			auto& glyph = this->glyphs.emplace_back(Glyph{});
			ParseGlyph(line, glyph);
			charIDToGlyph[glyph.id] = &glyph;
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
