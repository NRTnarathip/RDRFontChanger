#include "CustomFontSDF.h"
#include <filesystem>
#include "Logger.h"

namespace fs = std::filesystem;

CustomSwfFontSDF::CustomSwfFontSDF(swfFont* gameFont,
	std::string fontpath, float fontSize)
{
	cw("try create custom sdf font: %s", fontpath.c_str());

	this->originalGameFont = gameFont;
	this->fontSDF = new SDFont(fontpath);
	this->fontSize = fontSize;

	float ascentMax = 0, descentMax = 0;
	for (auto& item : fontSDF->charCodeToGlyphMap) {
		auto code = item.first;
		auto glyph = item.second;
		float topY = glyph->horizontalBearingY;
		if (topY > ascentMax)
			ascentMax = topY;

		float bottomY = topY - glyph->height;
		if (bottomY < 0.0f) {
			float distBelow = -bottomY;
			if (distBelow > descentMax)
				descentMax = distBelow;
		}
	}

	this->baselineNormalize = ascentMax;
	this->lineHeightNormalize = ascentMax + descentMax;
	this->originalGameFont->ascent = ascentMax * fontSize;
	this->originalGameFont->descent = descentMax * fontSize;
	this->originalGameFont->leading = (ascentMax + descentMax) * 0.30 * fontSize;

	cw("ascent: %d", originalGameFont->ascent);
	cw("descent: %d", originalGameFont->descent);
	cw("leading: %d", originalGameFont->leading);
	cw("lineHeight: %.2f", lineHeightNormalize * fontSize);

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

	auto font = this->originalGameFont;
	auto sdf = this->fontSDF;

	// assert
	if (this->replaceGlyphCount >= font->sheet->cellCount) {
		// full glyph
		return;
	}

	auto sheet = font->sheet;
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
	cw("size:     %.2f - %.2f", textureWidth, textureHeight);
	cw("left-top: %.2f - %.2f", textureLeft, textureTop);

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


	swfGlyph* g = sheet->cellArrayPtr + glyphIndex;
	g->left = textureLeft;
	g->top = textureTop;
	g->width = textureWidth;
	g->height = textureHeight;
	g->minX = minX;
	g->maxX = maxX;
	g->minY = minY;
	g->maxY = maxY;


	// update glyph advanceX array
	// cw("try access advanceFirstItem: %p", font->advanceFirstItem);
	if (font->advanceFirstItem == nullptr) {
		//	cw("try create advance array!");
		font->advanceFirstItem = new float[sheet->cellCount];
	}

	float advanceX = sdfGlyph.advanceX * fontSize;
	font->advanceFirstItem[glyphIndex] = advanceX;
	cw("advanceX: %.2f", advanceX);

	// update glyphToCode 
	font->glyphToCodeArrayFirstItem[glyphIndex] = charCode;
	this->replaceGlyphCount++;
	cw("replace glyph index[%d] = charCode: %d", glyphIndex, charCode);

	cw("info glyph: left:%d, top:%d, w:%d, h:%d", (int)g->left, (int)g->top, (int)g->width, (int)g->height);
	cw("bound: minX:%.2f, maxX:%.2f, minY:%.2f, maxY:%.2f", g->minX, g->maxX, g->minY, g->maxY);

}
