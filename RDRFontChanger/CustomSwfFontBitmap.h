#pragma once
#include "CustomFont.h"
#include "BitmapFont.h"

class CustomSwfFontBitmap : public CustomSwfFontAbstract {
public:
	BitmapFont* bitmapFont;
	CustomSwfFontBitmap(swfFont* gameFont, BitmapFont* newFont);
private:
	void ReplaceGlyph(const BitmapFont::Glyph& bitmapGlyph);
	void ReplaceTexture(int index, std::string newTextureFilePath);

};

