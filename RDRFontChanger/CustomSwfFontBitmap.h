#pragma once
#include "CustomFont.h"
#include "BitmapFont.h"

class CustomSwfFontBitmap : public CustomSwfFontAbstract {
public:
	BitmapFont* newFont;
	CustomSwfFontBitmap(swfFont* gameFont, BitmapFont* newFont);
	void Init() override;

private:
	void ReplaceGlyph(swfFont* font, const BitmapFont& thaiFont, const BitmapFont::Glyph& bitmapGlyph);
	void ReplaceTexture(int index, std::string newTextureFilePath);

};

