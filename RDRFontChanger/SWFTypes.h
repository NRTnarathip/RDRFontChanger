#pragma once
#include <iostream>
#include <cstddef>

#define CHECK_OFFSET(type, field, offset) \
    static_assert(offsetof(type, field) == offset, "Bad offset")

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

struct swfEDITFONT {
	void* offset1;
	void* offset2;
	void* offset3;
	// 0x18
	const char* string;
	const char* varName;
	int64_t stringSize;
};


struct SWFText {

};

void DumpSWFText(void* o);

const char* GetSWFTypeName(int e);


// size 0x181?
struct swfFile {
	char x30[0x30];
	void* files; // x30
	void* x38;
	void* x40;
	int x48;//0x48 -> x4c
	char x4c[0x2];
	// unsigned short totalFiles; // 0x4E
	unsigned short unk0x4E;
	char x50[0x130];
	const char* name;
};
CHECK_OFFSET(swfFile, files, 0x30);
// CHECK_OFFSET(swfFile, totalFiles, 0x4e);
CHECK_OFFSET(swfFile, x50, 0x50);
CHECK_OFFSET(swfFile, name, 0x180);


// size 0x298!
struct swfContext {
	char _0x48[0x48];
	swfFile* file;
};
CHECK_OFFSET(swfContext, file, 0x48);

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


// size 0x30!!
struct PackFile_c {

};


