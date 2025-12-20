#include "CustomSwfFontBitmap.h"
#include "Logger.h"

float to1024Units(float pixels, float fontSize) {
	return (pixels * 1024.0f) / fontSize;
}

CustomSwfFontBitmap::CustomSwfFontBitmap(swfFont* gameFont, BitmapFont* newFont)
{
	this->originalFont = gameFont;
	this->newFont = newFont;

	//// replace all glyph
	this->backupGlyphToCode = gameFont->glyphToCodeArrayFirstItem;
	this->backupGlyphCount = gameFont->glyphCount;

	//auto sheet = gameFont->sheet;

	// ready to replace
	cw("try replace all glyph...");
	for (int i = 0;i < newFont->glyphs.size();i++) {
		auto& newGlyph = newFont->glyphs[i];
		ReplaceGlyph(gameFont, *newFont, newGlyph);
	}
}

void CustomSwfFontBitmap::ReplaceGlyph(swfFont* font,
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

void CustomSwfFontBitmap::Init()
{

}

