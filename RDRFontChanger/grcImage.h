#pragma once
#include <cstdint>
#include <iostream>
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
	void** vftable;
	void* x8;
	int x10, x14; //x10 -> x18
	char x18[0x18]; //x18 ++
	const char* name; // x30
	TextureResource* textureResource; // x38
	unsigned short width, height; // x40 -> x44
	DXGI_FORMAT fourCC; // x44 -> x48
	unsigned short stride; // x48 -> 4a
	byte type; // x4a
	byte mipmap; // x4b
	float colorExpR, colorExpG, colorExpB;
	float colorOfsR, colorOfsG, colorOfsB;
	int x64;
	void* x68;
	void* x70;
	void* rawImage; //x78

	void LogInfo();
	void CreateFromBackingStore();
	std::string GetName();

	// hook
	void BeforeCreateFromBackingStore();
	void AfterCreateFromBackingStore();
};

CHECK_OFFSET(grcTextureD11, textureResource, 0x38);
CHECK_OFFSET(grcTextureD11, rawImage, 0x78);
CHECK_OFFSET(grcTextureD11, fourCC, 0x44);
CHECK_OFFSET(grcTextureD11, stride, 0x48);
CHECK_OFFSET(grcTextureD11, type, 0x4a);
CHECK_OFFSET(grcTextureD11, mipmap, 0x4b);


struct grcTextureFactoryD11 {
	virtual void* VF0() = 0;
	virtual void* VF1() = 0;
	virtual void* VF2() = 0;
	virtual void* VF3() = 0;
	virtual grcTextureD11* CreateTexture(const char* fileName, void* createParams) = 0;

	static grcTextureFactoryD11* GetInstance();
};


