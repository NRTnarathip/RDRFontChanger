#include "CustomFontSDF.h"
#include <filesystem>
#include "Logger.h"
#include <algorithm>
#include <iostream>
#include "XMem.h"

namespace fs = std::filesystem;

CustomSwfFontSDF::CustomSwfFontSDF(swfFont* gameFont,
	std::string fontpath, float fontSize)
{
	cw("try create custom sdf font: %s", fontpath.c_str());

	this->originalGameFont = gameFont;
	this->fontSDF = new SDFont(fontpath);
	this->fontSize = fontSize;

	//float ascentMax = 0, descentMax = 0;
	//for (auto& item : fontSDF->charCodeToGlyphMap) {
	//	auto code = item.first;
	//	auto glyph = item.second;
	//	float topY = glyph->horizontalBearingY;
	//	if (topY > ascentMax)
	//		ascentMax = topY;

	//	float bottomY = topY - glyph->height;
	//	if (bottomY < 0.0f) {
	//		float distBelow = -bottomY;
	//		if (distBelow > descentMax)
	//			descentMax = distBelow;
	//	}
	//}

	//this->baselineNormalize = ascentMax;
	//this->lineHeightNormalize = ascentMax + descentMax;
//	cw("lineHeight: %.2f", lineHeightNormalize * fontSize);
	//this->originalGameFont->ascent = ascentMax * fontSize;
	//this->originalGameFont->descent = descentMax * fontSize;
	//this->originalGameFont->leading = (ascentMax + descentMax) * 0.30 * fontSize;

	gameFont->LogInfo();

	// Recalculate game glyph with 512x512 in left top 0,0
	RecalculateGlyphsForTexturePack2x2();

	// replace all glyphs
	// allocate memory for new glyphs

	m_addNewGlyphIndexCounter = gameFont->glyphCount - 1;
	auto sheet = gameFont->sheet;

	pn("try fetch sd font...");

	// fetch sdfont new glyphs{
	std::unordered_set<unsigned short> newSDFontCharCodes;
	std::unordered_set<unsigned short> gameFontCharCodes;
	for (int i = 0; i < gameFont->glyphCount;i++) {
		auto charCode = gameFont->glyphToCodeArray[i];
		gameFontCharCodes.insert(charCode);
	}
	pn("game font char codes: {}", gameFontCharCodes.size());

	for (auto& item : fontSDF->charCodeToGlyphMap) {
		auto code = item.first;
		if (gameFontCharCodes.contains(code))
			continue;

		newSDFontCharCodes.insert(code);
	}

	// allocate new array!

	{
		pn("try allocate new arary...");
		int oldGameFontGlyphCount = gameFont->glyphCount;
		int newGameFontGlyphCount = oldGameFontGlyphCount + newSDFontCharCodes.size();

		unsigned short* newGlyphIndexToCodeArray = (unsigned short*)XMem::Allocate(
			newGameFontGlyphCount * sizeof(unsigned short), sizeof(unsigned short));

		float* newAdvanceArray = (float*)XMem::Allocate(
			newGameFontGlyphCount * sizeof(float), sizeof(float));

		swfGlyph* newGlyphArray = (swfGlyph*)XMem::Allocate(
			newGameFontGlyphCount * sizeof(swfGlyph), sizeof(swfGlyph));


		// glyphIndexToCharCodeArray
		memcpy(newGlyphIndexToCodeArray, gameFont->glyphToCodeArray,
			oldGameFontGlyphCount * sizeof(unsigned short));

		// advanceXArray 
		memcpy(newAdvanceArray, gameFont->advanceArray,
			oldGameFontGlyphCount * sizeof(float));

		// glyph array!!
		memcpy(newGlyphArray, sheet->glyphArray,
			oldGameFontGlyphCount * sizeof(swfGlyph));

		// backup it!
		this->backupGlyphIndexToCodeArray = gameFont->glyphToCodeArray;
		this->backupAdanveArrayPtr = gameFont->advanceArray;
		this->backupGlyphArray = sheet->glyphArray;

		// assign to new array!!
		gameFont->glyphToCodeArray = newGlyphIndexToCodeArray;
		gameFont->advanceArray = newAdvanceArray;
		sheet->glyphArray = newGlyphArray;

		// update gameFont glyph count...
		gameFont->glyphCount = newGameFontGlyphCount;
		sheet->cellCount = newGameFontGlyphCount;

		// debug log
		pn("update game font glyph array!");
		pn("glyph count old: {}, new: {}",
			oldGameFontGlyphCount, gameFont->glyphCount);
		// next step you can update new glyph slot!
	}

	// ready!!
	for (auto code : newSDFontCharCodes) {
		auto glyph = fontSDF->charCodeToGlyphMap[code];
		AddNewGlyph(code, glyph);
	}
	pn("done new obj CustomSDFont!");
}


void CustomSwfFontSDF::AddNewGlyph(unsigned short charCode, SDFGlyph* glyph)
{
	//	cw("try replace glyph, name: %s", glyph->name);

	auto font = this->originalGameFont;
	auto sdf = this->fontSDF;

	// assert
	if (this->m_addNewGlyphIndexCounter >= font->sheet->cellCount) {
		// full glyph
		return;
	}

	auto sheet = font->sheet;
	// ready
	int glyphIndex = m_addNewGlyphIndexCounter;
	// cw("glyph index: %d", glyphIndex);

	// 700 size! on rdr2narrow sdf 
	const float imageSize = 1024;
	auto& sdfGlyph = *glyph;
	float spreadTexture = this->fontSDF->spreadTexture;
	// width, height pixel on texture dds
	float textureWidth = sdfGlyph.tw;
	float textureHeight = sdfGlyph.th;

	// Left, Top pixel on texture dds
	float textureLeft = sdfGlyph.tx;
	// invert Y from (down-up) to (up-down)
	float textureTop = 1.0 - sdfGlyph.ty;
	// convert local bottom to top
	textureTop = textureTop - textureHeight;

	// addition spread normalize unit
	textureLeft -= spreadTexture;
	textureTop -= spreadTexture;
	textureWidth += 2.0f * spreadTexture;
	textureHeight += 2.0f * spreadTexture;

	// finally convert (pixel normalize) to (texture size)
	textureTop *= imageSize;
	textureLeft *= imageSize;
	textureWidth *= imageSize;
	textureHeight *= imageSize;

	// we ues texture pack 2x2 or 4 sprite in dds texture
	// downscale into 512x512
	textureLeft /= 2;
	textureTop /= 2;
	textureWidth /= 2;
	textureHeight /= 2;
	// so we will add margin left start at x: 512
	textureLeft += 512;


	// log
	//cw("size:     %.2f - %.2f", textureWidth, textureHeight);
	//cw("left-top: %.2f - %.2f", textureLeft, textureTop);

	float xoffset = sdfGlyph.horizontalBearingX;
	float yoffset = sdfGlyph.horizontalBearingY;

	float spreadFontMetric = this->fontSDF->spreadFontMetric;
	float minX = xoffset;
	float maxX = xoffset + sdfGlyph.width;


	// debug
	float ascentNormalize = font->ascent / fontSize;
	float descentNormalize = font->descent / fontSize;
	float leadingNormalize = font->leading / fontSize;
	float pixelTop = yoffset;
	float pixelBottom = pixelTop - sdfGlyph.height;

	float minY = -pixelTop;
	float maxY = -pixelBottom;


	// final scale
	minX -= spreadFontMetric;
	maxX += spreadFontMetric;
	minY -= spreadFontMetric;
	maxY += spreadFontMetric;

	minX *= fontSize;
	maxX *= fontSize;
	minY *= fontSize;
	maxY *= fontSize;


	swfGlyph* g = &sheet->glyphArray[glyphIndex];
	g->left = textureLeft;
	g->top = textureTop;
	g->width = textureWidth;
	g->height = textureHeight;
	g->minX = minX;
	g->maxX = maxX;
	g->minY = minY;
	g->maxY = maxY;


	// update glyph advanceX array
	float advanceX = sdfGlyph.advanceX * fontSize;
	font->advanceArray[glyphIndex] = advanceX;
	// cw("advanceX: %.2f", advanceX);

	// update glyphToCode 
	font->glyphToCodeArray[glyphIndex] = charCode;
	this->m_addNewGlyphIndexCounter++;
	//cw("replace glyph index[%d] = charCode: %d", glyphIndex, charCode);
	//cw("info glyph: left:%d, top:%d, w:%d, h:%d", (int)g->left, (int)g->top, (int)g->width, (int)g->height);
	//cw("bound: minX:%.2f, maxX:%.2f, minY:%.2f, maxY:%.2f", g->minX, g->maxX, g->minY, g->maxY);

}

void CustomSwfFontSDF::RecalculateGlyphsForTexturePack2x2()
{
	pn("RecalculateGameFontGlyphs...");

	auto& font = *originalGameFont;
	auto glyphCount = font.glyphCount;
	pn("glyph count: {}", glyphCount);

	auto& sheet = *font.sheet;
	for (int i = 0;i < glyphCount;i++) {
		pn("try access glyph index: {}", i);
		swfGlyph& g = sheet.glyphArray[i];
		pn("glyph ready to read and write!");
		int texIndex = 0;

		// check if you have multiple textures
		if (sheet.textureGlyphIndexArray) {
			texIndex = sheet.textureGlyphIndexArray[i];
		}

		// pn("texture sprite index: {}", texIndex);
		// don't rescale if not texture index 0
		if (texIndex > 0) {
			continue;
		}

		// should rescale if this glyph is on texture index 0
		float& left = g.left;
		float& top = g.top;
		float& width = g.width;
		float& height = g.height;
		pn("[{}] glyph before rescale: x:{}, y:{}, w:{}, h:{}",
			i, left, top, width, height);
		left = left / 2;
		top = top / 2;
		width = width / 2;
		height = height / 2;
		pn("[{}] glyph after rescale: x:{}, y:{}, w:{}, h:{}",
			i, left, top, width, height);
	}

	pn("Done RecalculateGameFontGlyphs!");
}
