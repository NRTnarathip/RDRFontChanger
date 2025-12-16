#pragma once
#include <cstdint>
#include "AssetLib.h"

struct grcImage {
	uint16_t width;
	uint16_t height;
	uint16_t format;
};


struct TexturePtr {
	void* x0;
	char x8[0x40];
	void* unk48;
	int width, height;
	char x58[0x14];
	int depth;
};

CHECK_OFFSET(TexturePtr, width, 0x50);
CHECK_OFFSET(TexturePtr, height, 0x54);
CHECK_OFFSET(TexturePtr, depth, 0x6C);

// size 0x80 on android
// pc size 0x88!!
struct grcTextureD11 {
	void** vftable;
	void* x8;
	int x10, x14;
	char x18[0x18];
	const char* name; // 
	TexturePtr* texturePtr; // x38
	int refCounter;
};

CHECK_OFFSET(grcTextureD11, texturePtr, 0x38);


struct grcTextureFactory {
	virtual void* VF0() = 0;
	virtual void* VF1() = 0;
	virtual void* VF2() = 0;
	virtual void* VF3() = 0;
	virtual grcTextureD11* CreateTexture(const char* fileName, void* createParams) = 0;

	static grcTextureFactory* GetInstance();
};


