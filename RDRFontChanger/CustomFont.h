#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct swfGlyph {
	float left;
	float top;
	float width;
	float height;
	float u0x10;
	float u0x14;
	float u0x18;
	float u0x1C;
};
static_assert(sizeof(swfGlyph) == 0x20, "Assert Size");
struct swfSheet {
	void* unk0x0;
	swfGlyph* glyphArrayFirstItem;
};
struct swfFont
{
	void** vftable; // 0x0 -> 0x8
	void* _0x8;
	void* _0x10;
	void* _0x18; // 0x18 -> 0x20
	unsigned short* glyphToCodeArrayFirstItem; //0x20 - > 0x28
	void* advanceFirstItem;
	char codeToGlyph[0x80]; // 0x30 -> 0xb0
	short sheetCount; // 0xb0
	short ascent;  // 0xb2
	short desent; // 0xb4
	short leading; // 0xb6
	unsigned short glyphCount;  // 0xb8
	unsigned char flags;
	unsigned char langCode;
	swfSheet* sheetArrayPtr;
};

static_assert(offsetof(swfFont, glyphToCodeArrayFirstItem) == 0x20, "Assert It");
static_assert(offsetof(swfFont, sheetCount) == 0xb0, "Assert It");
static_assert(offsetof(swfFont, glyphCount) == 0xb8, "Assert It");
static_assert(offsetof(swfFont, langCode) == 0xbb, "Assert It");
static_assert(offsetof(swfFont, sheetArrayPtr) == 0xc0, "Assert It");
static_assert(offsetof(swfFont, codeToGlyph) == 0x30, "Assert It");


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
	// glyphs count per font
	static std::unordered_map<void*, int> g_registeredFontGlyphs;
	static void RegisterGlyph(swfFont* font, BitmapFont& bitmapFont, BitmapFont::Glyph& bitmapGlyph);
	static void TryRegisterThaiFontGlyphs(swfFont* font);
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
