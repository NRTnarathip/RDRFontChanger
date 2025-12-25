#pragma once
#include <iostream>
#include <cstddef>
#include "grcImage.h"
#include "AssetLib.h"

enum SWFTypeEnum {
	Shape = 1,
	Sprite = 2,
	Button = 3,
	Bitmap = 4,
	Font = 5,
	Text = 6,
	EditText = 7,
	MorphShape = 9,
};

struct swfEditText {
	void* _x0; // 0x0
	void* _x8; // 0x8
	void* _x10; // 0x10
	const char* string; // 0x18
	const char* varName; // x20
	unsigned short stringSize; // x28 -> x2a
	unsigned short leading; // x2a -> x2c
	uint32_t color; // x2c -> x30
	unsigned short fontID; // x30 -> x32
	unsigned short fontHeight; // x32 -> x34
	float width, height; // x34 -> x3c
	float offsetX, offsetY; // x3c -> x44
	unsigned char html, align; // x44 -> x46
	float boundX;// x48 -> x4c
	float boundY;// x4c -> x50
	float unkx50;
	struct Bound {
		float x, y, width, height;
	};
	Bound GetBound()
	{
		float scale = fontHeight / 1024.0f;
		float scaledOffsetX = offsetX * scale;
		Bound bounds;
		bounds.x = scaledOffsetX;
		bounds.y = 0;
		bounds.width = this->width * scale + scaledOffsetX;
		bounds.height = (this->height + (float)this->leading) * scale;
		return bounds;
	}
};

CHECK_OFFSET(swfEditText, fontID, 0x30);
CHECK_OFFSET(swfEditText, width, 0x34);
CHECK_OFFSET(swfEditText, align, 0x45);


struct SWFText {

};

void DumpSWFText(void* o);

const char* GetSWFTypeName(int e);


// size 0x181?
struct swfFile {
	void* x0;
	void* x8; // x8 -> x10
	uint32_t magic; // x10 -> x14
	char x14[0x1c];
	void* files; // x30
	byte version; // x38
	void* x40;
	int x48;//0x48 -> x4c
	char x4c[0x2];
	unsigned short totalFiles; // 0x4E
	void** objectMap;
	unsigned short objectMapCount;
};
CHECK_OFFSET(swfFile, files, 0x30);
CHECK_OFFSET(swfFile, totalFiles, 0x4e);
CHECK_OFFSET(swfFile, objectMap, 0x50);
CHECK_OFFSET(swfFile, objectMapCount, 0x58);


struct swfGlyph {
	// unit pixels base texture size
	float left;
	float top;
	float width;
	float height;

	float minX;
	float minY;
	float maxX;
	float maxY;
};
static_assert(sizeof(swfGlyph) == 0x20, "Assert Size");


struct swfSheet {
	grcTextureD11** textureArray;
	swfGlyph* glyphArray; // 0x8 -> 0x10
	unsigned short size; // 0x10
	unsigned short cellCount; // 0x12
	unsigned short* textureGlyphIndexArray; //x18
	const char** textureNameArray; // 0x20
	void* x28; //x28
	int textureCount;
	bool DoesTextureExist(std::string name);
	bool DoesTextureContains(std::string findName);
	int FindTextureIndexOf(std::string name);
};
CHECK_OFFSET(swfSheet, size, 0x10);
CHECK_OFFSET(swfSheet, cellCount, 0x12);
CHECK_OFFSET(swfSheet, textureCount, 0x30);


// size?>
struct swfFont
{
	void** vftable; // 0x0 -> 0x8
	void* _0x8;
	void* _0x10;
	void* _0x18; // 0x18 -> 0x20
	// glyph index to char code
	unsigned short* glyphToCodeArray; //0x20 - > 0x28
	float* advanceArray; // x28 -> x30
	char codeToGlyph[0x80]; // 0x30 -> 0xb0
	short sheetCount; // 0xb0
	short ascent;  // 0xb2
	short descent; // 0xb4
	short leading; // 0xb6
	unsigned short glyphCount;  // 0xb8
	unsigned char flags;
	unsigned char langCode;
	swfSheet* sheet; // xc0
	char xC8[0xb8]; // -> xc8 ++
	char nameBuffer[]; // -> 0x180 ++
	std::string name() {
		return (char*)&nameBuffer;
	}
	swfFont* Clone();
	void LogInfo();
	bool IsBold();
};
CHECK_OFFSET(swfFont, glyphToCodeArray, 0x20);
CHECK_OFFSET(swfFont, sheetCount, 0xb0);
CHECK_OFFSET(swfFont, glyphCount, 0xb8);
CHECK_OFFSET(swfFont, langCode, 0xbb);
CHECK_OFFSET(swfFont, sheet, 0xc0);
CHECK_OFFSET(swfFont, codeToGlyph, 0x30);
CHECK_OFFSET(swfFont, xC8, 0xC8);
CHECK_OFFSET(swfFont, nameBuffer, 0x180);


struct swfEditTextDrawColor {
	unsigned char r, g, b, a;

	static	swfEditTextDrawColor Decode(uint32_t value) {
		swfEditTextDrawColor newColor;
		newColor.a = (value >> 24) & 0xFF;
		newColor.r = (value >> 16) & 0xFF;
		newColor.g = (value >> 8) & 0xFF;
		newColor.b = (value >> 0) & 0xFF;
		return newColor;
	}

	static uint32_t Encode(swfEditTextDrawColor c) {
		uint32_t result =
			(uint32_t(c.a) << 24) |
			(uint32_t(c.r) << 16) |
			(uint32_t(c.g) << 8) |
			(uint32_t(c.b));
		return result;
	}
};



// size 0x298!
struct swfContext {
	char _0x48[0x48];
	swfFile* file; // 0x48 -> x50
	char x50[0x220];
	const char* fileName;
};
CHECK_OFFSET(swfContext, file, 0x48);
CHECK_OFFSET(swfContext, fileName, 0x270);


// size 0x68!
struct fuiMovie {
	char x48[0x48];
	swfContext* ctx;
};

CHECK_OFFSET(fuiMovie, ctx, 0x48);

struct FlashManager {
	char _0x30[0x30];
	void* movieArray; // x30 -> x38
	void* x38;
	void* x40;
	swfContext* fontFileCtx; // 0x48
	void* unk0x50;
	char pad2[0x128];
	int movieCount; // 0x180
	int _x184_x188; // 184 -> 188
	void* _x188_x190;
	char* langName; // x190
};
CHECK_OFFSET(FlashManager, fontFileCtx, 0x48);
CHECK_OFFSET(FlashManager, movieCount, 0x180);
CHECK_OFFSET(FlashManager, langName, 0x190);

FlashManager* GetFlashManager();
void* FindFont(swfFile* mainFile, const char* p1_fontName);
fuiMovie* TryGetMovieFromID(FlashManager* mgr, uint8_t id);


struct PackFileProperty {
	uint32_t v0;
	uint32_t v1;
	uint32_t v2;
};

struct PackFilePropertyKeyPair {
	uint32_t key;        // +0x00  (fileHash)
	PackFileProperty value;  // +0x04  PackfileFileProperties_s
	uint32_t hash;       // +0x10  (key & 0xfffffffd)
};
static_assert(sizeof(PackFilePropertyKeyPair) == 0x14, "");


// size 0x10?
struct PackFileEntryHashMap {
	PackFilePropertyKeyPair* data; // x0 -> x8
	int count; // x8 -> c
	int capacity; // xc -> x10

	PackFilePropertyKeyPair* Find(uint32_t key);
};
CHECK_OFFSET(PackFileEntryHashMap, capacity, 0xc);


// confirm size x60 android
// pc size 0x60?
struct PackFileIndex_c {
	const char* packFileName;
	char pad1[0x28];
	uint32_t* fileHashVector; // x30 -> x38
	int totalFiles; // x38 -> x3C
	int fileHashCapacity; //x3C -> x40
	PackFileEntryHashMap hashMap; // x40 -> x50
	void* unkStringx50;
	void* unkStringx58;
};

CHECK_OFFSET(PackFileIndex_c, packFileName, 0x0);
CHECK_OFFSET(PackFileIndex_c, fileHashVector, 0x30);
CHECK_OFFSET(PackFileIndex_c, totalFiles, 0x38);
CHECK_OFFSET(PackFileIndex_c, fileHashCapacity, 0x3C);
CHECK_OFFSET(PackFileIndex_c, hashMap, 0x40);


// size 0x30?
struct PackFile_c {
	char x20[0x20];
	PackFileIndex_c* fileIndex; // 0x20
};

CHECK_OFFSET(PackFile_c, fileIndex, 0x20);


void DumpPackFile(PackFile_c* packfile);
void DumpSWFContext(swfContext* ctx);

// default seed for hash
#define FNV_OFFSET_BASIS_32 0x811C9DC5
uint32_t RageHashFNV(const void* data, size_t len);

// lang code
// error = -1
// en = 1
// fr = 2
// de = 3
// it = 4
// ja = 5
// 6 -> 12
// ko, pl, pt, pt-br, ru, es, es-mx

