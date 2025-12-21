#pragma once
#include "CustomFont.h"
#include "../SDFontLib/SDFont.h"

class CustomSwfFontSDF : public CustomSwfFontAbstract
{
public:
	float baseline;
	float lineHeight;
	float fontUIScale = 800;
	SDFont* fontSDF;
	CustomSwfFontSDF(swfFont* gameFont, std::string fontpath);

private:
	void ReplaceGlyph(unsigned short charCode, SDFGlyph* glyph);
};

