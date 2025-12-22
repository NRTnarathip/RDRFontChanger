#include "FontReplacer.h"
#include "Logger.h"
#include <unordered_map>
#include <unordered_set>
#include "../SDFontLib/SDFont.h"
#include "Rage.h"
#include "HookLib.h"
#include "FileLib.h"
#include "StringLib.h"
using namespace HookLib;

// variables
std::unordered_map<swfFont*, CustomSwfFontSDF*> g_fontSDFMap;
FontReplacer* FontReplacer::g_instance;
std::vector<swfFont*> FontReplacer::g_gameFonts;
std::unordered_map<std::string, std::string> g_registerGameFontMap;
std::unordered_map<swfFont*, CustomSwfFontSDF*> g_gameFontMapWithFontSDF;


// utils
std::string MakeGameFontNameKey(std::string gameFontName) {
	static std::unordered_map<std::string, std::string> g_cache;
	if (g_cache.contains(gameFontName))
		return g_cache[gameFontName];

	return g_cache[gameFontName] = StringRemove(ToLower(gameFontName), " ");
}


// hooks
swfFont* (*fn_FindFont)(swfFile* file, const char* findName);
swfFont* HK_FindFont(swfFile* file, const char* findName) {
	cw("BeginHook HK_FindFont");
	auto result = fn_FindFont(file, findName);
	// try replace font here
	cw("HK_FindFont result: %p", result);
	cw("EndHook HK_FindFont");
	return result;
}

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
	font->LogInfo();
	FontReplacer::g_gameFonts.push_back(font);

	cw("EndHook HK_SwfFont_VF16_Rader");
	return result;
}


// class functions
bool FontReplacer::Init()
{
	// HookRva(0x1b72550, HK_FindFont, &fn_FindFont);
	// crash here if you enter in game
	// HookRva(0x183160, HK_UnkSwfFont, &fn_UnkSwfFont);
	HookRva(0x19b3b0, HK_SwfFont_VF16_Rader, &fn_SwfFont_VF16_Rader);

	return true;
}

// key: font name | value: new font sdf path
void FontReplacer::RegisterFontWithFontSDF(
	std::string gameFontNameKey, std::string newFontPath)
{
	// normalize it!!
	gameFontNameKey = MakeGameFontNameKey(gameFontNameKey);

	// regular
	pn("try register game font: {}, new font: {}",
		gameFontNameKey, newFontPath);

	// already 
	if (g_registerGameFontMap.contains(gameFontNameKey)) {
		pn("already register game font: {}", gameFontNameKey);
		return;
	}

	// file not found
	if (fs::exists(newFontPath) == false) {
		pn("new font path not found!, {}", newFontPath);
		return;
	}

	// register texture replace to this font
	auto fontFileInfo = fs::path(newFontPath);
	auto fontFilenameNoExt = StringFileNoExt(newFontPath);
	pn("font file name no ext: {}", fontFilenameNoExt);
	auto fontDir = fontFileInfo.parent_path().string();
	pn("font dir: {}", fontDir);
	auto textureReplacer = TextureReplacer::Instance();

	// max texture count at 3!
	for (int indedx = 0; indedx < 3;indedx++) {
		// regular
		{
			auto gameTextureRegular = std::format("{}.charset_{}.dds", gameFontNameKey, indedx);
			auto ddstextureRegularPath = fs::path(fontDir) / gameTextureRegular;
			textureReplacer->RegisterReplaceTexture(gameTextureRegular,
				ddstextureRegularPath.string());
		}

		// bold
		{
			auto gameTextureBold = std::format("{}.charset_b_{}.dds", gameFontNameKey, indedx);
			auto ddstextureBoldPath = fs::path(fontDir) / gameTextureBold;
			textureReplacer->RegisterReplaceTexture(gameTextureBold,
				ddstextureBoldPath.string());
		}
	}

	g_registerGameFontMap[gameFontNameKey] = newFontPath;
	pn("registed game font: {}, new font: {}",
		gameFontNameKey, newFontPath);
}

bool IsBold(swfFont* font) {
	if (font->sheet == nullptr)
		return false;

	static std::unordered_map<swfFont*, bool> g_fontBoldmap;
	if (g_fontBoldmap.contains(font))
		return g_fontBoldmap[font];

	return g_fontBoldmap[font] = font->sheet->DoesTextureContains("_b_0.dds");
}

CustomSwfFontSDF* FontReplacer::TryReplaceFont(swfFont* gameFont)
{
	cw("try replace new font sdf...");

	// don't have any font
	if (g_registerGameFontMap.empty())
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
	auto fontName = MakeGameFontNameKey(gameFont->name());
	cw("font name: %s", fontName);
	if (g_registerGameFontMap.contains(fontName) == false)
		return nullptr;

	std::string fontPath = g_registerGameFontMap[fontName];
	auto fontDir = fs::path(fontPath).parent_path().string();

	cw("font path: %s", fontPath.c_str());
	float fontSize = sheet->size;
	cw("font size: %.2f", fontSize);
	bool isBold = IsBold(gameFont);
	if (isBold) {
		// redirect into bold font 
		fontPath = std::format("{}/{}_bold{}", fontDir, fontName, FontFileExtName);
		pn("redirect to font bold: {}", fontPath);
	}

	if (fs::exists(fontPath) == false) {
		return nullptr;
	}

	// ready create it!
	auto customFont = g_gameFontMapWithFontSDF[gameFont]
		= new CustomSwfFontSDF(gameFont, fontPath, fontSize);
	cw("replaced original font: %p", gameFont);
	return customFont;
}

void FontReplacer::RegisterFontFromDir(std::string dir)
{
	std::vector<std::string> files;
	GetFiles(dir, files);
	for (auto file : files) {
		auto path = fs::path(file);
		if (path.extension() != FontFileExtName)
			continue;

		auto gameFontName = StringFileNoExt(file);
		RegisterFontWithFontSDF(gameFontName, file);

	}
}
