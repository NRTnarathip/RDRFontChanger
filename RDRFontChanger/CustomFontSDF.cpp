#include "CustomFontSDF.h"
#include <filesystem>
#include "Logger.h"
#include <algorithm>
#include <iostream>
#include "XMem.h"
#include "FontConfig.h"

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
	m_oldGameFontGlyphTotal = gameFont->glyphCount;
	m_newGameFontGlyphTotal = m_oldGameFontGlyphTotal + m_newSDFontCharCodes.size();

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
			m_newGameFontGlyphTotal * sizeof(unsigned short), sizeof(unsigned short));
		memcpy(newGlyphIndexToCodeArray, gameFont->glyphToCodeArray,
			m_oldGameFontGlyphTotal * sizeof(unsigned short));
		pn("clone newGlyphIndexToCodeArray");
		gameFont->glyphToCodeArray = newGlyphIndexToCodeArray;

		// advanceXArray 
		cw("gameFont advnaceArray: %p", gameFont->advanceArray);
		auto newAdvanceArray = (float*)XMem::Allocate(
			m_newGameFontGlyphTotal * sizeof(float), sizeof(float));
		if (gameFont->advanceArray) {
			memcpy(newAdvanceArray, gameFont->advanceArray,
				m_oldGameFontGlyphTotal * sizeof(float));
			pn("clone newAdvanceArray");
		}
		else {
			cw("no need to clone advance array!");
		}
		gameFont->advanceArray = newAdvanceArray;

		// glyph array!!
		auto newGlyphArray = (swfGlyph*)XMem::Allocate(
			m_newGameFontGlyphTotal * sizeof(swfGlyph), sizeof(swfGlyph));
		memcpy(newGlyphArray, sheet->glyphArray,
			m_oldGameFontGlyphTotal * sizeof(swfGlyph));
		pn("clone newGlyphArray");
		sheet->glyphArray = newGlyphArray;

		// update gameFont glyph count...
		gameFont->glyphCount = m_newGameFontGlyphTotal;
		sheet->cellCount = m_newGameFontGlyphTotal;

		// resize texture glyph index
		if (sheet->textureGlyphIndexArray)
		{
			auto newTextureGlyphIndexArray = (unsigned short*)XMem::Allocate(
				m_newGameFontGlyphTotal * sizeof(unsigned short), sizeof(unsigned short));
			memcpy(newTextureGlyphIndexArray, sheet->textureGlyphIndexArray,
				m_oldGameFontGlyphTotal * sizeof(unsigned short));
			sheet->textureGlyphIndexArray = newTextureGlyphIndexArray;
			pn("clone textureGlyphIndexArray");
		}

		// debug log
		pn("update game font glyph array!");
		pn("glyph count old: {}, new: {}",
			m_oldGameFontGlyphTotal, gameFont->glyphCount);
		// next step you can update new glyph slot!
	}

	// ready to add new glyphs !!
	{
		// start at end
		int myGlyphIndexCounter = m_oldGameFontGlyphTotal;
		for (auto code : m_newSDFontCharCodes) {
			auto glyph = fontSDF->charCodeToGlyphMap[code];
			AddNewGlyph(myGlyphIndexCounter, code, glyph);
			myGlyphIndexCounter++;
		}

		RecalculateFontSDFScale();
		// fix sdf font glyph scale match to game font!
	}
	pn("done new obj CustomSDFont!");
}

void CustomFontSDF::RecalculateFontSDFScale()
{
	float rescale = -1;

	auto fontConfig = FontConfig::Instance();
	auto fontName = originalGameFont->name();
	if (fontName == "RDR2 Narrow")
		rescale = fontConfig->narrowSDFontScale;
	else if (fontName == "RDR2 Narrow_OL1")
		rescale = fontConfig->narrowOL1SDFontScale;
	else if (fontName == "Redemption")
		rescale = fontConfig->redemptionSDFontScale;

	// any rescale?
	if (rescale <= 0 || rescale == 1)
		return;

	cw("try rescale sdf glyphs to: %.2f", rescale);
	cw("font name: %s", fontName.c_str());

	int startIndex = m_oldGameFontGlyphTotal;
	for (int i = startIndex;i < m_newGameFontGlyphTotal;i++) {
		auto& g = originalGameFont->sheet->glyphArray[i];
		g.minX *= rescale;
		g.maxX *= rescale;
		g.minY *= rescale;
		g.maxY *= rescale;
		if (originalGameFont->advanceArray) {
			auto& advance = originalGameFont->advanceArray[i];
			advance *= rescale;
		}
	}
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
	// fixed first index!
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
		// pn("[{}] glyph, charCode: {}", i, charCode);
		//pn("glyph ready to read and write!");

		// check if you have multiple textures
		if (sheet->textureGlyphIndexArray &&
			sheet->textureGlyphIndexArray[i] > 0)
			continue;

		// should rescale if this glyph is on texture index 0
		//pn("[{}] glyph before rescale: x:{}, y:{}, w:{}, h:{}",
		//	i, g.left, g.top, g.width, g.height);

		g.left /= 2;
		g.top /= 2;
		g.width /= 2;
		g.height /= 2;

		//pn("[{}] glyph after rescale: x:{}, y:{}, w:{}, h:{}",
		//	i, g.left, g.top, g.width, g.height);

		// update
		sheet->glyphArray[i] = g;
	}

	pn("Done RecalculateGameFontGlyphs!");
}
