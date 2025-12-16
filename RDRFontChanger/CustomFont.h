#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "SWFTypes.h"



class BitmapFont {
public:
	struct Glyph {
		int id;         // 106 - character code
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
	void ParseGlyph(const std::string& line, BitmapFont::Glyph& g);
	bool isLoaded;
	void Load(std::string path);
};

class CustomFont
{
public:
	CustomFont(swfFont* font);
	swfFont* font;

	// base on calling ReplaceTexture(); !!!
	std::vector<grcTextureD11*> backupTextureArray;
	std::vector<const char*> backupTextureNameArray;
	std::vector<grcTextureD11*> newTextures;
	std::vector<std::string> newTextureFileNames;

	static BitmapFont* GetThaiFont();
	int replaceGlyphCount;

	// glyphs count per font
	static std::unordered_map<swfFont*, CustomFont*> g_registeredFonts;
	void ReplaceGlyph(swfFont* font, const BitmapFont::Glyph& bitmapGlyph);
	void ReplaceTexture(int index, std::string newTextureFilePath);
	static void TryReplaceSwfFontToThaiFont(swfFont* font);
};


struct Fonttext {
public:
	// float Version;
	char unk[0x50];
	int CharHeight;  // 0x50
	int CharSpacing; // 0x54
	int SpaceWidth; // 0x58
	int MonospaceWidth; // 0x5C
	int MaxAscent; // 0x60
	int MaxDescent;
	int ShadowLeft;
	int ShadowRight;
	int ShadowTop; // 70
	int ShadowBottom;
	int unk0x78;
	int unk0x7C; // 7C
	uint64_t unk0x80; // 80
	uint64_t unk0x88; // 88
	uint64_t unk0x90; // 90
	int NumGlyphs;
	void* Glyphs;
	int NumTextures;
	int* GlyphsPerTexture;
};

static_assert(offsetof(Fonttext, CharHeight) == 0x50, "assert");
static_assert(offsetof(Fonttext, NumGlyphs) == 0x98, "assert");

void TryDumpSwfFont(swfFont* font, const char* prefixFileName);
