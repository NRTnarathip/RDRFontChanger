#include "grcImage.h"
#include "XMem.h"
#include "Logger.h"

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
	cw("x30: %p", x30);
	cw("size: %d - %d", width, height);
	auto magicString = MagicToString(fourCC);
	cw("fourCC: name: %s, hex: 0x%x", magicString.c_str(), fourCC);
	cw("mips: %d, x4a: %d", mipmap, x4a);
	cw("texture resource: %p", textureResource);
	if (textureResource) {
		textureResource->LogInfo();
	}
}

void TextureResource::LogInfo()
{
	cw("TextureResource::LogInfo: %p", this);
	cw("name: %s", name);
	cw("size: %d - %d", width, height);
	cw("x68: %d, x6a: %d, x6c: %d", x68, x6a, x6c);

}
