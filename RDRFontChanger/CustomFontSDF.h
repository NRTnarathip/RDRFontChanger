#pragma once
#include "../SDFontLib/SDFont.h"
#include "SWFTypes.h"
#include <unordered_set>

class CustomFontSDF
{
public:
	swfFont* originalGameFont;
	float* backupAdanveArrayPtr;
	swfGlyph* backupGlyphArray;
	unsigned short* backupGlyphIndexToCodeArray;
	// rdr2narrow sheet size = 700
	float fontSize;
	SDFont* fontSDF;
	CustomFontSDF(swfFont* gameFont, std::string fontpath, float fontSize);

private:
	int m_oldGameFontGlyphCount;
	int m_newGameFontGlyphCount;
	std::unordered_set<unsigned short> m_newSDFontCharCodes;
	std::unordered_set<unsigned short> m_gameFontCharCodes;
	void AddNewGlyph(int index, unsigned short charCode, SDFGlyph* glyph);
	void RecalculateGameFontGlyphsBaseTexture2x2();
};

