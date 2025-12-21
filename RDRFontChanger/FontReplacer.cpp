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

std::string g_registerNarrowSDFRegularFontPath;
std::string g_registerNarrowSDFBoldFontPath;
void FontReplacer::RegisterFontNarrowWithFontSDF(
	std::string fontRegularPath, std::string fontBoldPath)
{
	// regular
	cw("try register new narrow font regular sdf: %s", fontRegularPath.c_str());
	if (g_registerNarrowSDFRegularFontPath.empty()) {
		if (fs::exists(fontRegularPath)) {
			g_registerNarrowSDFRegularFontPath = fontRegularPath;
			RegisterReplaceTextureByFontPath(fontRegularPath, "rdr2narrow.charset_0.dds");
			cw("registed regular font %s!", fontRegularPath.c_str());
		}
	}

	// bold
	cw("try register new narrow font bold sdf: %s", fontBoldPath.c_str());
	if (g_registerNarrowSDFBoldFontPath.empty()) {
		if (fs::exists(fontBoldPath)) {
			g_registerNarrowSDFBoldFontPath = fontBoldPath;
			RegisterReplaceTextureByFontPath(fontBoldPath, "rdr2narrow.charset_b_0.dds");
			cw("registed bold font %s!", fontBoldPath.c_str());
		}
	}
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

bool TryGetFontNarrowInfo(swfFont* gameFont, bool& isBold) {
	static std::unordered_map<swfFont*, bool> g_isNarrowFontCache;
	static std::unordered_map<swfFont*, bool> g_isNarrowFontBoldCache;

	if (g_isNarrowFontCache.contains(gameFont)) {
		// found but is not narrow font
		if (g_isNarrowFontCache[gameFont] == false)
			return false;

		// found, get bold font!
		isBold = g_isNarrowFontBoldCache[gameFont];
		return true;
	}

	// we can't check at this time
	auto sheet = gameFont->sheet;
	if (sheet == nullptr) {
		return false;
	}

	// mark default value
	g_isNarrowFontCache[gameFont] = false;
	g_isNarrowFontBoldCache[gameFont] = false;

	// check if font narrow regular - bold
	if (sheet->textureCount > 0) {
		// no overhead safe too call loop find
		if (sheet->DoesTextureExist("rdr2narrow.charset_0.dds")) {
			g_isNarrowFontCache[gameFont] = true;
			g_isNarrowFontBoldCache[gameFont] = false;
		}
		else if (sheet->DoesTextureExist("rdr2narrow.charset_b_0.dds")) {
			g_isNarrowFontCache[gameFont] = true;
			g_isNarrowFontBoldCache[gameFont] = true;
		}
	}

	// return it
	isBold = g_isNarrowFontBoldCache[gameFont];
	return g_isNarrowFontCache[gameFont];
}

std::unordered_map<swfFont*, CustomSwfFontSDF*> g_gameFontMapWithFontSDF;
CustomSwfFontSDF* FontReplacer::TryReplaceFontNarrowWithSDF(swfFont* gameFont) {
	static std::unordered_set<swfFont*> g_isNarrowFontMap;
	auto customFont = TryReplaceFontNarrowWithSDFInternal(gameFont);
	if (customFont != nullptr) {
		g_isNarrowFontMap.insert(gameFont);
	}
}
CustomSwfFontSDF* FontReplacer::TryReplaceFontNarrowWithSDFInternal(swfFont* gameFont)
{
	cw("try replace font with sdf...");

	// don't have any font
	if (g_registerNarrowSDFRegularFontPath.empty()
		&& g_registerNarrowSDFBoldFontPath.empty())
		return nullptr;


	// from cache
	if (g_gameFontMapWithFontSDF.contains(gameFont)) {
		return g_gameFontMapWithFontSDF[gameFont];
	}

	// assert
	auto sheet = gameFont->sheet;
	if (sheet == nullptr) {
		return nullptr;
	}

	// check if font narrow regular - bold
	bool isBold;
	if (TryGetFontNarrowInfo(gameFont, isBold) == false) {
		return nullptr;
	}

	float fontSize = sheet->size;
	cw("font size: %.2f", fontSize);
	cw("is bold: %s", isBold ? "yes" : "no");
	std::string sdfFontPath = g_registerNarrowSDFRegularFontPath;
	if (isBold)
		sdfFontPath = g_registerNarrowSDFBoldFontPath;

	// ready create it!
	auto customFont = g_gameFontMapWithFontSDF[gameFont]
		= new CustomSwfFontSDF(gameFont, sdfFontPath, fontSize);
	cw("replaced original font: %p", gameFont);
	return customFont;
}
