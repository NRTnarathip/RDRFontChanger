#include "FontReplacer.h"
#include "Logger.h"
#include <unordered_map>
#include <unordered_set>
#include "../SDFontLib/SDFont.h"
#include "Rage.h"

std::unordered_map<swfFont*, CustomSwfFontAbstract*> g_registeredFonts;

FontReplacer* FontReplacer::g_instance;
const char* k_fontsDir = "mods/fonts";

std::unordered_map<std::string, BitmapFont*> g_bitmapFontCacheMap;
BitmapFont* LoadBitmapFont(std::string filename)
{
	auto fspath = fs::path(k_fontsDir) / filename;
	auto path = SafePath(fspath);

	if (g_bitmapFontCacheMap.contains(path))
		return g_bitmapFontCacheMap[path];

	BitmapFont* font = new BitmapFont();
	font->Load(path);
	g_bitmapFontCacheMap[path] = font;
	return font;
}

bool FontReplacer::Init()
{
	return true;
}

std::string g_registerNewNarrowFontBitmap;
void FontReplacer::RegisterFontNarrowWithFontBitmap(std::string newFontName)
{
	if (g_registerNewNarrowFontBitmap.empty() == false) {
		cw("already registered main narrow font!, current: %s",
			g_registerNewNarrowFontBitmap.c_str());
		return;
	}

	g_registerNewNarrowFontBitmap = newFontName;
	auto fontTextureName = newFontName.substr(0, newFontName.size() - 4) + ".dds";
	auto textureReplacer = TextureReplacer::Instance();
	auto fontsDir = fs::path(k_fontsDir);
	auto fontTexturePath = fontsDir / fontTextureName;
	// register texture replace to this font
	textureReplacer->RegisterReplaceTexture(
		"rdr2narrow.charset_0.dds",
		fontTexturePath.string());
}

bool IsCanRegisterNewFont(swfFont* gameFont) {
	return g_registeredFonts.contains(gameFont) == false;
}

CustomSwfFontAbstract* FontReplacer::TryReplaceFontNarrow(swfFont* originalFont) {
	cw("try replace font: %p", originalFont);

	if (g_registerNewNarrowFontBitmap.empty()) {
		return nullptr;
	}

	// check is registered?
	if (g_registeredFonts.contains(originalFont))
		return g_registeredFonts[originalFont];


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
		&& sheet->DoesTextureExist("RDR2Narrow.charset_0.dds");
	if (!support)
		return nullptr;


	BitmapFont* newBitmapFont = LoadBitmapFont(g_registerNewNarrowFontBitmap);

	auto customFont = new CustomSwfFontBitmap(originalFont, newBitmapFont);
	customFont->Init();
	g_registeredFonts[originalFont] = customFont;

	logFormat("replaced original font: %p", originalFont);
	return customFont;
}

//Custom* FontReplacer::TryReplaceToThaiSDFFont(swfFont* originalFont)
//{
	//cw("try replace font: %p", originalFont);
	//// check is registered?
	//if (g_registeredFonts.contains(originalFont))
	//	return g_registeredFonts[originalFont];

	//// assert
	//auto sheet = originalFont->sheet;
	//if (sheet == nullptr) {
	//	cw("font sheet is null!");
	//	return nullptr;
	//}

	//// debug
	//// support only main font!
	//bool support = sheet->textureCount == 1
	//	&& sheet->DoesTextureExist("RDR2Narrow.charset_0.dds");
	//if (!support)
	//	return nullptr;

	//// ready
	//auto thaiFont = GetThaiFontSDF();
	//auto customFont = new Custom(originalFont, thaiFont);
	//g_registeredFonts[originalFont] = customFont;


	//logFormat("replaced original font: %p", originalFont);
	//return customFont;
//}

