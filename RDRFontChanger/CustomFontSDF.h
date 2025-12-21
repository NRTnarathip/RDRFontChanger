#pragma once
#include "CustomFont.h"
#include "../SDFontLib/SDFont.h"

class CustomSwfFontSDF : public CustomSwfFontAbstract
{
public:
	float baselineNormalize;
	float lineHeightNormalize;
	// rdr2narrow sheet size = 700
	float fontSize;
	SDFont* fontSDF;
	CustomSwfFontSDF(swfFont* gameFont, std::string fontpath, float fontSize);

private:
	void ReplaceGlyph(unsigned short charCode, SDFGlyph* glyph);
};

