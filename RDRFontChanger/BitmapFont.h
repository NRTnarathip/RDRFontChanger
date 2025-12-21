#pragma once

#include "CustomFont.h";

class BitmapFont : public FontAbstract {
public:
	struct Glyph {
		int charCode;         // 106 - character code
		int x, y;       // 577, 65 - texture position
		int width, height;  // 17, 54 - texture size
		int xoffset, yoffset;  // -5, 25 - render offset
		int xadvance;   // 12 - cursor advance
		int page;       // 0 - texture page
		int chnl;       // 15 - channel
	};
	char face[256];
	std::string fontName;
	int size, bold, italic;
	int lineHeight, baseline, scaleW, scaleH;

	std::vector<Glyph> glyphs;
	std::unordered_map<USHORT, Glyph*> charIDToGlyph;

	BitmapFont(std::string path);
	void ParseGlyph(const std::string& line, BitmapFont::Glyph& g);
	static BitmapFont* TryLoad(std::string path);
};
