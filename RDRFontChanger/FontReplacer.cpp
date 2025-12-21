#include "FontReplacer.h"
#include "Logger.h"
#include <unordered_map>
#include <unordered_set>
#include "../SDFontLib/SDFont.h"
#include "Rage.h"

std::unordered_map<swfFont*, CustomSwfFontBitmap*> g_fontBitmapWithSwfFontMap;
std::unordered_map<swfFont*, CustomSwfFontSDF*> g_fontSDFMap;

FontReplacer* FontReplacer::g_instance;

bool FontReplacer::Init()
{
	return true;
}

void RegisterReplaceTextureByFontPath(std::string fontpath, std::string textureKey) {
	// register texture replace to this font
	auto fspath = fs::path(fontpath);
	auto fontFilename = fspath.filename();
	auto dir = fspath.root_directory();
	auto fontTextureName = fontpath.substr(0, fontpath.size() - 4) + ".dds";
	auto textureReplacer = TextureReplacer::Instance();
	auto fontTexturePath = dir / fontTextureName;
	textureReplacer->RegisterReplaceTexture(
		textureKey,
		fontTexturePath.string());

}

std::string g_registerNarrowFontBitmapPath;
void FontReplacer::RegisterFontNarrowWithFontBitmap(std::string fontpath)
{
	cw("try register new narrow font bitmap: %s", fontpath.c_str());
	if (g_registerNarrowFontBitmapPath.empty() == false) {
		cw("already registered: %s",
			g_registerNarrowFontBitmapPath.c_str());
		return;
	}

	// ready
	g_registerNarrowFontBitmapPath = fontpath;
	RegisterReplaceTextureByFontPath(fontpath, "rdr2narrow.charset_0.dds");
}

std::string g_registerNarrowFontSDFPath;
void FontReplacer::RegisterFontNarrowWithFontSDF(std::string fontpath)
{
	cw("try register new narrow font sdf: %s", fontpath.c_str());
	if (g_registerNarrowFontSDFPath.empty() == false) {
		cw("already registered: %s", g_registerNarrowFontSDFPath.c_str());
		return;
	}

	if (fs::exists(fontpath) == false) {
		cw("error file font not found!");
		return;
	}

	// ready
	g_registerNarrowFontSDFPath = fontpath;
	// register texture replace to this font
	RegisterReplaceTextureByFontPath(fontpath, "rdr2narrow.charset_0.dds");
	cw("registed font %s!", fontpath.c_str());
}


CustomSwfFontBitmap* FontReplacer::TryReplaceFontNarrowWithBitmap(swfFont* originalFont) {
	cw("try replace font: %p", originalFont);

	if (g_registerNarrowFontBitmapPath.empty()) {
		cw("not register narrow font bitmap");
		return nullptr;
	}

	// check is registered?
	if (g_fontBitmapWithSwfFontMap.contains(originalFont))
		return g_fontBitmapWithSwfFontMap[originalFont];


	// create new custom font??
	// assert
	auto sheet = originalFont->sheet;
	if (sheet == nullptr) {
		cw("font sheet is null!");
		return nullptr;
	}

	// debug
	// support only main font!
	bool support = sheet->textureCount == 1
		&& sheet->DoesTextureExist("rdr2narrow.charset_0.dds");
	if (!support) {
		cw("not support this font texture! ");
		return nullptr;
	}


	BitmapFont* newBitmapFont = BitmapFont::TryLoad(g_registerNarrowFontBitmapPath);
	auto customFont = new CustomSwfFontBitmap(originalFont, newBitmapFont);
	g_fontBitmapWithSwfFontMap[originalFont] = customFont;

	cw("replaced original font: %p", originalFont);
	return customFont;
}

std::unordered_map<swfFont*, CustomSwfFontSDF*> g_fontSDFWithGameFontMap;
CustomSwfFontSDF* FontReplacer::TryReplaceFontNarrowWithSDF(swfFont* gameFont)
{
	cw("try replace font with sdf...");
	if (g_registerNarrowFontSDFPath.empty())
		return nullptr;


	// from cache
	if (g_fontSDFWithGameFontMap.contains(gameFont)) {
		return g_fontSDFWithGameFontMap[gameFont];
	}

	// assert
	auto sheet = gameFont->sheet;
	if (sheet == nullptr) {
		return nullptr;
	}

	// support only main font!
	bool support = sheet->textureCount == 1
		&& sheet->DoesTextureExist("rdr2narrow.charset_0.dds");
	if (!support) {
		return nullptr;
	}


	// ready create it!
	auto customFont = g_fontSDFWithGameFontMap[gameFont]
		= new CustomSwfFontSDF(gameFont, g_registerNarrowFontSDFPath);
	cw("replaced original font: %p", gameFont);
	return customFont;
}
