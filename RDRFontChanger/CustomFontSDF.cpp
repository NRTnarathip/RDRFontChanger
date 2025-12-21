#include "CustomFontSDF.h"
#include <filesystem>
#include "Logger.h"

namespace fs = std::filesystem;

CustomSwfFontSDF::CustomSwfFontSDF(swfFont* gameFont, std::string fontpath)
{
	this->originalGameFont = gameFont;
	this->newGameFont = gameFont->Clone();
	this->fontSDF = new SDFont(fontpath);


	float ascentMax = 0, descentMax = 0;
	for (auto& item : fontSDF->charCodeToGlyphMap) {
		auto code = item.first;
		auto glyph = item.second;

		float aboveBaselineY = max(0.0f, glyph->horizontalBearingY);
		float belowBaselineY = max(0.0f, glyph->height - glyph->horizontalBearingY);
		float ascentNow = aboveBaselineY;
		float descentNow = belowBaselineY;

		cw("ascent now: %.2f", ascentNow);
		ascentMax = max(ascentMax, ascentNow);
		descentMax = max(descentMax, descentNow);
	}

	this->baseline = ascentMax;
	this->lineHeight = ascentMax + descentMax;
	this->newGameFont->ascent = ascentMax * fontUIScale;
	this->newGameFont->descent = descentMax * fontUIScale;
	this->newGameFont->leading = 0.0f;

	cw("ascent: %.2f", ascentMax);
	cw("descent: %.2f", descentMax);


	// replace font glyphs
	for (auto& item : fontSDF->charCodeToGlyphMap) {
		auto code = item.first;
		auto glyph = item.second;
		ReplaceGlyph(code, glyph);
	}
}

void CustomSwfFontSDF::ReplaceGlyph(unsigned short charCode, SDFGlyph* glyph)
{
	cw("try replace glyph, name: %s", glyph->name);

	auto gameFont = this->newGameFont;
	auto sdf = this->fontSDF;

	// assert
	if (charCode < 0 || charCode > 0xFFFF) {
		cw("bitmap glyph charCode overflow unsigned short");
		return;
	}
	if (this->replaceGlyphCount >= gameFont->sheet->cellCount) {
		// full glyph
		return;
	}

	auto sheet = gameFont->sheet;
	// ready
	int glyphIndex = replaceGlyphCount;

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


	// log
	cw("size:     %d - %d", textureWidth, textureHeight);
	cw("left-top: %d - %d", (int)textureLeft, (int)textureTop);

	float xoffset = sdfGlyph.horizontalBearingX;
	float yoffset = sdfGlyph.horizontalBearingY;
	float glyphWidth = sdfGlyph.width;
	float glyphHeight = sdfGlyph.height;

	float minX = xoffset;
	float maxX = xoffset + glyphWidth;

	float pixelTop = baseline - yoffset;
	float pixelBottom = pixelTop - glyphHeight;
	float minY = -pixelTop;
	float maxY = -pixelBottom;

	// spread
	float spreadVertex = this->fontSDF->spreadFontMetric;
	minX -= spreadVertex;
	maxX += spreadVertex;
	minY -= spreadVertex;
	maxY += spreadVertex;

	// final scale
	minX *= fontUIScale;
	maxX *= fontUIScale;

	minY *= fontUIScale;
	maxY *= fontUIScale;


	swfGlyph* g = sheet->cellArrayPtr + glyphIndex;
	g->left = textureLeft;
	g->top = textureTop;
	g->width = textureWidth;
	g->height = textureHeight;
	g->minX = minX;
	g->minY = minY;
	g->maxX = maxX;
	g->maxY = maxY;

	// update glyph advanceX array
	float advanceX = sdfGlyph.advanceX * fontUIScale;
	gameFont->advanceFirstItem[glyphIndex] = advanceX;
	cw("advanceX: %.2f", advanceX);

	// update glyphToCode 
	gameFont->glyphToCodeArrayFirstItem[glyphIndex] = charCode;
	this->replaceGlyphCount++;
	cw("replace glyph index[%d] = charCode: %d", glyphIndex, charCode);

	cw("info glyph: left:%d, top:%d, w:%d, h:%d", (int)g->left, (int)g->top, (int)g->width, (int)g->height);
	cw("bound: minX:%.2f, maxX:%.2f, minY:%.2f, maxY:%.2f", g->minX, g->maxX, g->minY, g->maxY);

}
