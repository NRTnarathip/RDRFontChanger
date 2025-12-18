#include "grcImage.h"
#include "XMem.h"
#include "Logger.h"
#include "HookLib.h"
#include "StringLib.h"

using namespace XMem;

grcTextureFactoryD11* grcTextureFactoryD11::GetInstance()
{
	return *(grcTextureFactoryD11**)GetAddressFromRva(0x2ac0a28);
}

void grcImage::LogInfo()
{
	cw("grcImage::LogInfo: %p", this);
	cw("size: %d - %d", width, height);
	cw("format: 0x%x", format);
	cw("stride %d, depth: %d", stride, depth);
	cw("pixels: %p", pixels);
	cw("next: %p, layer: %p", next, layer);
}

std::string MagicToString(uint32_t magic)
{
	char s[5];
	s[0] = (char)(magic & 0xFF);
	s[1] = (char)((magic >> 8) & 0xFF);
	s[2] = (char)((magic >> 16) & 0xFF);
	s[3] = (char)((magic >> 24) & 0xFF);
	s[4] = '\0';
	return std::string(s);
}

void grcTextureD11::LogInfo()
{
	cw("grcTextureD11::LogInfo: %p", this);
	// crash some object!!
	std::string name = GetName();
	cw("name: %s", name.c_str());
	cw("size: %d - %d", width, height);
	auto magicString = MagicToString(fourCC);
	cw("fourCC: name: %s, hex: 0x%x", magicString.c_str(), fourCC);
	cw("img type: %d", type);
	cw("stride: %d, mips: %d, type: %d", stride, mipmap, type);
	cw("raw image: %p", rawImage);
	cw("texture resource: %p", textureResource);
	if (textureResource) {
		textureResource->LogInfo();
	}
}

void grcTextureD11::CreateFromBackingStore()
{
	HookLib::Invoke<void*, void*>(vftable[0x20], this);
}

std::string grcTextureD11::GetName()
{
	return name;
}

void grcTextureD11::BeforeCreateFromBackingStore()
{
	cw("before call HK_grcTextureD11_CreateFromBackingStore");
	LogInfo();

	// callback
}

void grcTextureD11::AfterCreateFromBackingStore()
{
	cw("after call HK_grcTextureD11_CreateFromBackingStore");
	LogInfo();
}

void TextureResource::LogInfo()
{
	cw("TextureResource::LogInfo: %p", this);
	cw("name: %s", name);
	cw("size: %d - %d", width, height);
	cw("x68: %d, x6a: %d, x6c: %d", x68, x6a, x6c);
}
