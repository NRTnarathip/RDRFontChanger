#pragma once
#include "../SDFontLib/SDFont.h"
#include "SWFTypes.h"
#include <unordered_set>

class CustomFontSDF
{
public:
	swfFont* originalGameFont;
	// rdr2narrow sheet size = 700
	float fontSize;
	SDFont* fontSDF;
	CustomFontSDF(swfFont* gameFont, std::string fontpath, float fontSize);
	void RecalculateFontSDFScale();
private:
	int m_oldGameFontGlyphTotal;
	int m_newGameFontGlyphTotal;
	std::unordered_set<unsigned short> m_newSDFontCharCodes;
	std::unordered_set<unsigned short> m_gameFontCharCodes;
	void AddNewGlyph(int index, unsigned short charCode, SDFGlyph* glyph);
	void RecalculateGameFontGlyphsBaseTexture2x2();
};

