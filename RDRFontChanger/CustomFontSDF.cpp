#include "CustomFontSDF.h"
#include <filesystem>
#include "Logger.h"
#include <algorithm>
#include <iostream>
#include "XMem.h"

namespace fs = std::filesystem;

CustomFontSDF::CustomFontSDF(swfFont* gameFont,
	std::string fontpath, float fontSize)
{
	cw("try create custom sdf font: %s", fontpath.c_str());
	gameFont->LogInfo();

	// initialize data
	this->originalGameFont = gameFont;
	this->fontSDF = new SDFont(fontpath);
	this->fontSize = fontSize;
	// fetch sdfont new glyphs{
	for (int i = 0; i < gameFont->glyphCount;i++) {
		this->m_gameFontCharCodes.insert(gameFont->glyphToCodeArray[i]);
	}
	pn("game font char codes: {}", m_gameFontCharCodes.size());

	for (auto& item : fontSDF->charCodeToGlyphMap) {
		auto code = item.first;
		if (m_gameFontCharCodes.contains(code))
			continue;

		m_newSDFontCharCodes.insert(code);
	}
	m_oldGameFontGlyphCount = gameFont->glyphCount;
	m_newGameFontGlyphCount = m_oldGameFontGlyphCount + m_newSDFontCharCodes.size();

	// Recalculate game glyph with 512x512 in left top 0,0
	RecalculateGameFontGlyphsBaseTexture2x2();


	// allocate memory for new glyphs
	auto sheet = gameFont->sheet;
	// allocate new array!
	{
		pn("try allocate new arary...");

		// glyphIndexToCharCodeArray
		cw("gameFont glyphToCodeArray: %p", gameFont->glyphToCodeArray);
		auto newGlyphIndexToCodeArray = (unsigned short*)XMem::Allocate(
			m_newGameFontGlyphCount * sizeof(unsigned short), sizeof(unsigned short));
		memcpy(newGlyphIndexToCodeArray, gameFont->glyphToCodeArray,
			m_oldGameFontGlyphCount * sizeof(unsigned short));
		pn("clone newGlyphIndexToCodeArray");

		// advanceXArray 
		cw("gameFont advnaceArray: %p", gameFont->advanceArray);
		auto newAdvanceArray = (float*)XMem::Allocate(
			m_newGameFontGlyphCount * sizeof(float), sizeof(float));
		if (gameFont->advanceArray) {
			memcpy(newAdvanceArray, gameFont->advanceArray,
				m_oldGameFontGlyphCount * sizeof(float));
			pn("clone newAdvanceArray");
		}
		else {
			cw("no need to clone advance array!");
		}
		gameFont->advanceArray = newAdvanceArray;

		// glyph array!!
		auto newGlyphArray = (swfGlyph*)XMem::Allocate(
			m_newGameFontGlyphCount * sizeof(swfGlyph), sizeof(swfGlyph));
		memcpy(newGlyphArray, sheet->glyphArray,
			m_oldGameFontGlyphCount * sizeof(swfGlyph));
		pn("clone newGlyphArray");

		// backup it!
		this->backupGlyphIndexToCodeArray = gameFont->glyphToCodeArray;
		this->backupAdanveArrayPtr = gameFont->advanceArray;
		this->backupGlyphArray = sheet->glyphArray;

		// assign to new array!!
		gameFont->glyphToCodeArray = newGlyphIndexToCodeArray;
		sheet->glyphArray = newGlyphArray;

		// update gameFont glyph count...
		gameFont->glyphCount = m_newGameFontGlyphCount;
		sheet->cellCount = m_newGameFontGlyphCount;

		// resize texture glyph index
		if (sheet->textureGlyphIndexArray)
		{
			auto newTextureGlyphIndexArray = (unsigned short*)XMem::Allocate(
				m_newGameFontGlyphCount * sizeof(unsigned short), sizeof(unsigned short));
			memcpy(newTextureGlyphIndexArray, sheet->textureGlyphIndexArray,
				m_oldGameFontGlyphCount * sizeof(unsigned short));
			sheet->textureGlyphIndexArray = newTextureGlyphIndexArray;
			pn("clone textureGlyphIndexArray");
		}

		// debug log
		pn("update game font glyph array!");
		pn("glyph count old: {}, new: {}",
			m_oldGameFontGlyphCount, gameFont->glyphCount);
		// next step you can update new glyph slot!
	}

	// ready to add new glyphs !!
	{
		// start at end
		int myGlyphIndexCounter = m_oldGameFontGlyphCount;
		for (auto code : m_newSDFontCharCodes) {
			auto glyph = fontSDF->charCodeToGlyphMap[code];
			AddNewGlyph(myGlyphIndexCounter, code, glyph);
			myGlyphIndexCounter++;
		}
	}
	pn("done new obj CustomSDFont!");
}


void CustomFontSDF::AddNewGlyph(int glyphIndex, unsigned short charCode, SDFGlyph* glyph)
{
	//	cw("try replace glyph, name: %s", glyph->name);

	auto font = this->originalGameFont;
	auto sdf = this->fontSDF;

	// assert
	if (glyphIndex >= font->sheet->cellCount) {
		// full glyph
		return;
	}

	auto sheet = font->sheet;
	// ready
	// cw("glyph index: %d", glyphIndex);

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
	{
		const float imageSize = 512;
		textureTop *= imageSize;
		textureLeft *= imageSize;
		textureWidth *= imageSize;
		textureHeight *= imageSize;
		// we ues texture pack 2x2 or 4 sprite in dds texture
		// downscale into 512x512
		// so we will add margin left start at x: 512
		textureLeft += imageSize;
	}



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
	if (font->advanceArray) {
		float advanceX = sdfGlyph.advanceX * fontSize;
		font->advanceArray[glyphIndex] = advanceX;
	}
	else {
		cw("warning!!, this font don't have advance array!!");
	}
	// cw("advanceX: %.2f", advanceX);

// update glyphToCode 
	font->glyphToCodeArray[glyphIndex] = charCode;

	// check is need update textureGlyphIndenx
	// fixed firist index!
	if (sheet->textureGlyphIndexArray)
		sheet->textureGlyphIndexArray[glyphIndex] = 0;

	// debug log
	//cw("replace glyph index[%d] = charCode: %d", glyphIndex, charCode);
	//cw("info glyph: left:%d, top:%d, w:%d, h:%d", (int)g->left, (int)g->top, (int)g->width, (int)g->height);
	//cw("bound: minX:%.2f, maxX:%.2f, minY:%.2f, maxY:%.2f", g->minX, g->maxX, g->minY, g->maxY);
}

void CustomFontSDF::RecalculateGameFontGlyphsBaseTexture2x2()
{
	pn("RecalculateGameFontGlyphs...");

	auto font = originalGameFont;
	auto sheet = font->sheet;
	auto glyphCount = font->glyphCount;
	pn("font->glyphCount: {}", font->glyphCount);
	pn("sheet->cellCount: {}", sheet->cellCount);

	for (int i = 0;i < glyphCount;i++) {
		swfGlyph& g = sheet->glyphArray[i];
		unsigned short charCode = font->glyphToCodeArray[i];
		pn("[{}] glyph, charCode: {}", i, charCode);
		//pn("glyph ready to read and write!");

		// check if you have multiple textures
		if (sheet->textureGlyphIndexArray &&
			sheet->textureGlyphIndexArray[i] > 0)
			continue;

		// should rescale if this glyph is on texture index 0
		pn("[{}] glyph before rescale: x:{}, y:{}, w:{}, h:{}",
			i, g.left, g.top, g.width, g.height);

		g.left /= 2;
		g.top /= 2;
		g.width /= 2;
		g.height /= 2;

		pn("[{}] glyph after rescale: x:{}, y:{}, w:{}, h:{}",
			i, g.left, g.top, g.width, g.height);

		// update
		sheet->glyphArray[i] = g;
	}

	pn("Done RecalculateGameFontGlyphs!");
}
