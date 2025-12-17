#pragma once
#include <cstdint>
#include "AssetLib.h"
#include "DXLib.h"

enum grcImageFormat : uint16_t {

};
struct grcImage {
	uint16_t width; // x0 -> x2
	uint16_t height; // x2 -> x4
	grcImageFormat format; // rage engine format
	int x8; // -> x8 -> xc
	unsigned short stride; // xc
	unsigned short depth; // xe
	void* pixels; //x10
	void* x18;
	grcImage* next;
	grcImage** layer;

	void LogInfo();
};
CHECK_OFFSET(grcImage, pixels, 0x10);
CHECK_OFFSET(grcImage, layer, 0x28);


struct Resource_c {
	void** vftable;
	char* name;
};

// like base on Resource_c
struct TextureResource {
	void* x0; // x0
	char* name; // x8
	char x10[0x38];
	void** unk48; // like function ptr array
	int width, height; // x50 ++
	void* x58;
	void* x60;
	unsigned short x68;
	unsigned short x6a;
	unsigned short x6c; // x6c
	void LogInfo();
};

// size 0x38 android!!
struct TextureDesc_c {

};

CHECK_OFFSET(TextureResource, width, 0x50);
CHECK_OFFSET(TextureResource, height, 0x54);
CHECK_OFFSET(TextureResource, x6a, 0x6a);
CHECK_OFFSET(TextureResource, x6c, 0x6C);


// size 0x80 on android!!
// pc size 0x88!!
struct grcTextureD11 {
	/// <summary> 
	/// Vftable rva list
	/// x20 = 0x153f60
	/// </summary>
	void** vftable;
	void* x8;
	int x10, x14;
	char x18[0x18];
	void* x30; // x30
	TextureResource* textureResource; // x38
	unsigned short width, height; // x40 -> x44
	// magic like: 0x444e5243, 0x55534142, x32 ...
	int fourCC; // x44 -> x48
	unsigned short stride; // x48 -> 4a
	byte type; // x4a
	byte mipmap; // x4b
	float colorExpR, colorExpG, colorExpB;
	float colorOfsR, colorOfsG, colorOfsB;

	void LogInfo();
};

CHECK_OFFSET(grcTextureD11, textureResource, 0x38);
CHECK_OFFSET(grcTextureD11, fourCC, 0x44);
CHECK_OFFSET(grcTextureD11, colorExpB, 0x54);
CHECK_OFFSET(grcTextureD11, colorOfsB, 0x60);


struct grcTextureFactoryD11 {
	virtual void* VF0() = 0;
	virtual void* VF1() = 0;
	virtual void* VF2() = 0;
	virtual void* VF3() = 0;
	virtual grcTextureD11* CreateTexture(const char* fileName, void* createParams) = 0;

	static grcTextureFactoryD11* GetInstance();
};


