#include "FontReplacer.h"
#include "Logger.h"
#include <unordered_map>
#include <unordered_set>
#include "../SDFontLib/SDFont.h"
#include "Rage.h"
#include "HookLib.h"
using namespace HookLib;

std::unordered_map<swfFont*, CustomSwfFontBitmap*> g_fontBitmapWithSwfFontMap;
std::unordered_map<swfFont*, CustomSwfFontSDF*> g_fontSDFMap;

FontReplacer* FontReplacer::g_instance;

swfFont* (*fn_FindFont)(swfFile* file, const char* findName);
swfFont* HK_FindFont(swfFile* file, const char* findName) {
	cw("BeginHook HK_FindFont");
	auto result = fn_FindFont(file, findName);
	// try replace font here
	cw("HK_FindFont result: %p", result);
	cw("EndHook HK_FindFont");
	return result;
}

std::vector<swfFont*> FontReplacer::g_gameFonts;

void* (*fn_UnkSwfFont)(void* ctx, void* reader);
void* HK_UnkSwfFont(void* ctx, void* reader) {
	cw("BeginHook HK_UnkSwfFont");
	cw("ctx: %p", ctx);
	cw("reader: %p", reader);
	auto result = fn_UnkSwfFont(ctx, reader);
	cw("HK_UnkSwfFont result: %p", result);

	// try replace font here
	//if (g_queueFontCreated.size() > 0) {
	//	for (swfFont* font : g_queueFontCreated) {
	//		auto fontReplacer = FontReplacer::Instance();
	//		fontReplacer->TryReplaceFontNarrowWithSDF(font);
	//	}
	//	g_queueFontCreated.clear();
	//}

	cw("EndHook HK_UnkSwfFont");

	return result;
}

void* (*fn_SwfFont_VF16_Rader)(swfFont* font, void* reader);
void* HK_SwfFont_VF16_Rader(swfFont* font, void* reader) {
	cw("BeginHook HK_SwfFont_VF16_Rader");
	cw("font: %p", font);
	cw("reader: %p", reader);
	auto result = fn_SwfFont_VF16_Rader(font, reader);
	cw("HK_SwfFont_VF16_Rader result: %p", result);
	// try replace font here
	//auto fontReplacer = FontReplacer::Instance();
	//fontReplacer->TryReplaceFontNarrowWithSDF(font);
	FontReplacer::g_gameFonts.push_back(font);

	cw("EndHook HK_SwfFont_VF16_Rader");
	return result;
}

bool FontReplacer::Init()
{
	// HookRva(0x1b72550, HK_FindFont, &fn_FindFont);
	// crash here if you enter in game
	// HookRva(0x183160, HK_UnkSwfFont, &fn_UnkSwfFont);
	HookRva(0x19b3b0, HK_SwfFont_VF16_Rader, &fn_SwfFont_VF16_Rader);

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
	auto customFont = TryReplaceFontNarrowWithSDFInternal(gameFont);
	return customFont;
}
CustomSwfFontSDF* FontReplacer::TryReplaceFontNarrowWithSDFInternal(swfFont* gameFont)
{
	cw("try replace new font sdf...");

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

	std::string fontPath = g_registerNarrowSDFRegularFontPath;
	if (isBold)
		fontPath = g_registerNarrowSDFBoldFontPath;

	cw("font path: %s", fontPath.c_str());
	float fontSize = sheet->size;
	cw("font size: %.2f", fontSize);
	cw("is bold: %s", isBold ? "yes" : "no");

	// ready create it!
	auto customFont = g_gameFontMapWithFontSDF[gameFont]
		= new CustomSwfFontSDF(gameFont, fontPath, fontSize);
	cw("replaced original font: %p", gameFont);
	return customFont;
}
