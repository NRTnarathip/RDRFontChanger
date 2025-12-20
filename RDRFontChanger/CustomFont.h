#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "SWFTypes.h"
#include "TextureChanger.h"
#include "ISystem.h"

class FontAbstract {
public:

};


class CustomSwfFontAbstract {
public:
	swfFont* originalFont;
	int backupGlyphCount;
	void* backupGlyphToCode;
	void* backupSheetCellArray;

	void virtual Init() = 0;

	// base on calling ReplaceTexture(); !!!
	std::vector<grcTextureD11*> backupTextureArray;
	std::vector<const char*> backupTextureNameArray;
	std::vector<grcTextureD11*> newTextures;
	std::vector<std::string> newTextureFileNames;
	int replaceGlyphCount;
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

void DumpSwfFont(swfFont* font, const char* prefixFileName);
