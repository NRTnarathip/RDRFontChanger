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
#include "FontManager.h"

using namespace HookLib;


// variables
std::unordered_map<swfFont*, CustomFontSDF*> g_fontSDFMap;
FontReplacer* FontReplacer::g_instance;
std::unordered_map<std::string, std::string> g_registerGameFontMap;
// std::unordered_map<swfFont*, CustomFontSDF*> g_gameFontMapWithCustomFont;


void OnCreateFont(swfFont* font) {
	auto name = font->name();
	cw("font replacer, OnCreateFont: %s", name.c_str());
	auto instance = FontReplacer::Instance();
	instance->TryLoadCustomFont(font);
}

void OnDeleteFont(swfFont* font) {
	cw("font replacer, OnDeleteFont: %p", font);
}

// class functions
bool FontReplacer::Init()
{
	auto fontMgr = FontManager::Instance();
	fontMgr->RegisterOnCreateFont(OnCreateFont);
	fontMgr->RegisterOnDeleteFont(OnDeleteFont);
	return true;
}

// key: font name | value: new font sdf path
void FontReplacer::RegisterFontWithFontSDF(
	std::string gameFontName, std::string newFontPath)
{
	// normalize it!!
	gameFontName = FontManager::MakeGameFontNameKey(gameFontName);

	// normalize 
	newFontPath = fs::path(newFontPath).generic_string();

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
	auto fontMgr = FontManager::Instance();
	auto fonts = fontMgr->GetFonts();
	for (auto font : fonts) {
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
	cw("game font: %p", gameFont);
	gameFont->LogInfo();

	// don't have any font
	if (g_registerGameFontMap.empty())
		return nullptr;


	// from cache
	//if (g_gameFontMapWithCustomFont.contains(gameFont)) {
	//	cw("get it from cache!: %p", gameFont);
	//	return g_gameFontMapWithCustomFont[gameFont];
	//}

	// assert
	auto sheet = gameFont->sheet;
	if (sheet == nullptr) {
		return nullptr;
	}

	// debug

	// check if font narrow regular - bold
	auto fontName = FontManager::MakeGameFontNameKey(gameFont->name());
	cw("font name: %s", fontName.c_str());
	if (g_registerGameFontMap.contains(fontName) == false) {
		cw("this font name have't register!");
		return nullptr;
	}

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
		cw("font path not found!: %s", fontPath);
		return nullptr;
	}

	// ready create it!
	cw("try create custom game font with sdf!");
	//auto customFont = g_gameFontMapWithCustomFont[gameFont]
	auto customFont = new CustomFontSDF(gameFont, fontPath, fontSize);
	cw("replaced original font: %p", gameFont);

	return customFont;
}

CustomFontSDF* FontReplacer::TryGetCustomFont(swfFont* font)
{
	//if (g_gameFontMapWithCustomFont.contains(font))
	//	return g_gameFontMapWithCustomFont[font];
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
		auto gameFontName = FontManager::MakeGameFontNameKey(StringFileNoExt(filename));
		if (g_gameFontNames.contains(gameFontName) == false)
			continue;

		RegisterFontWithFontSDF(gameFontName, file);
	}
}
