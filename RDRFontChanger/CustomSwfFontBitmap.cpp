#include "CustomSwfFontBitmap.h"
#include "Logger.h"


CustomSwfFontBitmap::CustomSwfFontBitmap(swfFont* gameFont, BitmapFont* newFont)
{
	this->originalGameFont = gameFont;
	//this->newGameFont = gameFont->Clone();
	this->bitmapFont = newFont;

	// ready to replace
	cw("try replace all glyph...");
	for (int i = 0;i < newFont->glyphs.size();i++) {
		auto& newGlyph = newFont->glyphs[i];
		ReplaceGlyph(newGlyph);
	}
}

void CustomSwfFontBitmap::ReplaceGlyph(const BitmapFont::Glyph& glyph)
{
	cw("try replace glyph id: %d", glyph.charCode);

	// assert
	if (glyph.charCode < 0 || glyph.charCode > 0xFFFF) {
		cw("bitmap glyph charCode overflow unsigned short");
		return;
	}

	auto font = this->originalGameFont;
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
	float fontSize = this->bitmapFont->size;
	float minX = toUnitSheetSize(glyph.xoffset, fontSize);
	float maxX = toUnitSheetSize(glyph.xoffset + glyph.width, fontSize);

	float baseline = bitmapFont->baseline;
	float lineHeight = bitmapFont->lineHeight;
	float pixelTop = baseline - yoffset;
	float pixelBottom = baseline - yoffset - glyph.height;
	float minY = toUnitSheetSize(-pixelTop, fontSize);
	float maxY = toUnitSheetSize(-pixelBottom, fontSize);

	font->ascent = toUnitSheetSize(baseline, fontSize);
	font->descent = toUnitSheetSize(lineHeight - baseline, fontSize);
	font->leading = toUnitSheetSize(0.0f, fontSize);


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
	float advanceX = toUnitSheetSize(glyph.xadvance, fontSize);
	font->advanceFirstItem[glyphIndex] = advanceX;
	cw("advanceX: %.2f", advanceX);

	//// update glyphToCode 
	font->glyphToCodeArrayFirstItem[glyphIndex] = (unsigned short)glyph.charCode;
	cw("replace glyph index[%d] = charCode: %d", glyphIndex, glyph.charCode);

	cw("info glyph: x:%d, y:%d, w:%d, h:%d", (int)g->left, (int)g->top, (int)g->width, (int)g->height);
	cw("bound: minX:%.2f, minY:%.2f, maxX:%.2f, maxY:%.2f", g->minX, g->minY, g->maxX, g->maxY);
}
