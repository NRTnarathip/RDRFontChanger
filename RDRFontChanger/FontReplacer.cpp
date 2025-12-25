#include "FontReplacer.h"
#include "Logger.h"
#include <unordered_map>
#include <unordered_set>
#include "../SDFontLib/SDFont.h"
#include "Rage.h"
#include "HookLib.h"
#include "FileLib.h"
#include "StringLib.h"
#include "TextureLib.h"
#include "TextureChanger.h"

using namespace HookLib;


// variables
std::unordered_map<swfFont*, CustomFontSDF*> g_fontSDFMap;
FontReplacer* FontReplacer::g_instance;
std::vector<swfFont*> FontReplacer::g_gameFonts;
std::unordered_map<std::string, std::string> g_registerGameFontMap;
std::unordered_map<swfFont*, CustomFontSDF*> g_gameFontMapWithCustomFont;


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

void* (*fn_UnkSwfReader)(void* ctx, void* reader);
void* HK_UnkSwfReader(void* ctx, void* reader) {
	cw("BeginHook HK_UnkSwfReader");
	cw("ctx: %p", ctx);
	cw("reader: %p", reader);
	auto result = fn_UnkSwfReader(ctx, reader);
	cw("HK_UnkSwfReader result: %p", result);

	// try replace font here

	cw("EndHook HK_UnkSwfReader");

	return result;
}

void* (*fn_SwfFont_VF16_Reader)(swfFont* font, void* reader);
void* HK_SwfFont_VF16_Reader(swfFont* font, void* reader) {
	cw("BeginHook HK_SwfFont_VF16_Reader");
	cw("font: %p", font);
	cw("reader: %p", reader);
	auto result = fn_SwfFont_VF16_Reader(font, reader);
	cw("HK_SwfFont_VF16_Rader result: %p", result);
	font->LogInfo();
	FontReplacer::g_gameFonts.push_back(font);

	cw("EndHook HK_SwfFont_VF16_Reader");
	return result;
}


void* (*fn_swfContext_Place)(swfContext* self, void* param_2);
void* HK_swfContext_Place(swfContext* self, void* p2) {
	cw("BeginHook HK_swfContext_Place");
	cw("self: %p", self);
	cw("p2: %p", p2);
	auto r = fn_swfContext_Place(self, p2);
	cw("HK_swfContext_Place result: %p", r);

	cw("EndHook HK_swfContext_Place");
	return r;
}

void* (*fn_swfContext_Place2)(swfContext* self, void* param_2, void* p3);
void* HK_swfContext_Place2(swfContext* self, void* p2, void* p3) {
	cw("BeginHook HK_swfContext_Place2");
	cw("self: %p", self);
	cw("p2: %p", p2);
	cw("p3: %p", p3);
	cw("try call fn_swfContext_Place2...");
	auto r = fn_swfContext_Place2(self, p2, p3);
	cw("HK_swfContext_Place2 result: %p", r);

	auto fontReplacer = FontReplacer::Instance();
	for (swfFont* font : FontReplacer::g_gameFonts) {
		fontReplacer->TryLoadCustomFont(font);
	}

	cw("EndHook HK_swfContext_Place2");
	return r;
}

// class functions
bool FontReplacer::Init()
{
	// HookRva(0x1b72550, HK_FindFont, &fn_FindFont);
	// HookRva(0x183160, HK_UnkSwfReader, &fn_UnkSwfReader);
	HookRva(0x19b3b0, HK_SwfFont_VF16_Reader, &fn_SwfFont_VF16_Reader);
	// HookRva(0x11bb80, HK_swfContext_Place, &fn_swfContext_Place);
	// HookRva(0x1150c0, HK_swfContext_Place2, &fn_swfContext_Place2);

	return true;
}

// key: font name | value: new font sdf path
void FontReplacer::RegisterFontWithFontSDF(
	std::string gameFontName, std::string newFontPath)
{
	// normalize it!!
	gameFontName = MakeGameFontNameKey(gameFontName);

	// regular
	pn("try register game font: {}, new font: {}",
		gameFontName, newFontPath);

	// already 
	if (g_registerGameFontMap.contains(gameFontName)) {
		pn("already register game font: {}", gameFontName);
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

	const char* k_Pack2x2DDSNameSuffix = ".pack2x2.dds";
	// regular
	{
		auto ddsFilename = std::format("{}{}", gameFontName, k_Pack2x2DDSNameSuffix);
		auto ddspath = fs::path(fontDir) / ddsFilename;
		textureReplacer->RegisterReplaceTexture(
			std::format("{}.charset_0.dds", gameFontName),
			ddspath.string());
	}

	// bold
	{
		auto fontBoldSDFFilename = std::format("{}_bold{}", gameFontName, k_SDFontFileExtName);
		// check is have a bold sdffont file??
		if (fs::exists(fs::path(fontDir) / fontBoldSDFFilename)) {
			auto ddsFilename = std::format("{}_bold{}", gameFontName, k_Pack2x2DDSNameSuffix);
			auto ddspath = fs::path(fontDir) / ddsFilename;
			textureReplacer->RegisterReplaceTexture(
				std::format("{}.charset_b_0.dds", gameFontName),
				ddspath.string());
		}
	}

	g_registerGameFontMap[gameFontName] = newFontPath;
	pn("registed game font: {}, new font: {}",
		gameFontName, newFontPath);
}


void DebugFonts() {
	cw("try dump all font...");
	int index = 0;
	for (auto font : FontReplacer::g_gameFonts) {
		cw("[%d] font info...", index);
		font->LogInfo();

		auto sheet = font->sheet;
		for (int i = 0;i < sheet->textureCount;i++) {
			auto tex = sheet->textureArray[i];
			auto texName = tex->GetName();
			cw("texture[%d]", i, texName.c_str());
		}
		index++;
	}
}

CustomFontSDF* FontReplacer::TryLoadCustomFont(swfFont* gameFont)
{
	cw("try replace new font sdf...");
	//	gameFont->LogInfo();

		// don't have any font
	if (g_registerGameFontMap.empty())
		return nullptr;


	// from cache
	if (g_gameFontMapWithCustomFont.contains(gameFont)) {
		return g_gameFontMapWithCustomFont[gameFont];
	}

	// assert
	auto sheet = gameFont->sheet;
	if (sheet == nullptr) {
		return nullptr;
	}

	// debug

	// check if font narrow regular - bold
	auto fontName = MakeGameFontNameKey(gameFont->name());
	cw("font name: %s", fontName);
	if (g_registerGameFontMap.contains(fontName) == false)
		return nullptr;

	std::string fontPath = g_registerGameFontMap[fontName];
	cw("font path: %s", fontPath.c_str());
	auto fontDir = fs::path(fontPath).parent_path().string();
	float fontSize = sheet->size;
	bool isBold = gameFont->IsBold();
	if (isBold) {
		// redirect into bold font 
		fontPath = std::format("{}/{}_bold{}", fontDir, fontName, k_SDFontFileExtName);
		pn("redirect to font bold: {}", fontPath);
	}

	if (fs::exists(fontPath) == false) {
		return nullptr;
	}

	// ready create it!
	auto customFont = g_gameFontMapWithCustomFont[gameFont]
		= new CustomFontSDF(gameFont, fontPath, fontSize);
	cw("replaced original font: %p", gameFont);

	return customFont;
}

CustomFontSDF* FontReplacer::TryGetCustomFont(swfFont* font)
{
	if (g_gameFontMapWithCustomFont.contains(font))
		return g_gameFontMapWithCustomFont[font];
	return nullptr;
}

void FontReplacer::RegisterFontFromDir(std::string dir)
{
	std::vector<std::string> files;
	GetFiles(dir, files);
	std::unordered_set<std::string> g_gameFontNames = {
			"rdr2narrow_ol1",
			"rdr2narrow",
			"rdr2narrowbig",
			"redemption",
			"rdr2lucid",
			"redemption_ol1",
			"redemption_shadow",
			"redemptionbig",
			"rdr2narrowbigol1",
			"redemptionstagger",
			"redemptionstaggershadow",
	};

	for (auto file : files) {
		auto path = fs::path(file);
		if (path.extension() != k_SDFontFileExtName)
			continue;

		auto filename = path.filename().string();
		auto gameFontName = MakeGameFontNameKey(StringFileNoExt(filename));
		if (g_gameFontNames.contains(gameFontName) == false)
			continue;

		RegisterFontWithFontSDF(gameFontName, file);
	}
}
