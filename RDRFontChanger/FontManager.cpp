#include "FontManager.h"
#include "SWFTypes.h"
#include "Logger.h"
#include <unordered_set>
#include <unordered_map>
#include "HookLib.h"
#include "StringLib.h"

using namespace HookLib;


FontManager* g_instance;
std::unordered_set<swfFont*> g_gameFonts;


void* (*fn_SwfFont_VF16_Reader)(swfFont* font, void* reader);
void* HK_SwfFont_VF16_Reader(swfFont* font, void* reader) {
	cw("BeginHook HK_SwfFont_VF16_Reader");
	cw("font: %p", font);
	auto result = fn_SwfFont_VF16_Reader(font, reader);
	cw("HK_SwfFont_VF16_Rader result: %p", result);
	font->LogInfo();
	g_instance->InvokeOnCreateFont(font);

	cw("EndHook HK_SwfFont_VF16_Reader");
	return result;
}

void* (*fn_swfFont_Delete)(swfFont* font);
void* HK_swfFont_Delete(swfFont* font) {
	cw("BeginHook HK_swfFont_Delete");
	cw("font: %p", font);
	auto r = fn_swfFont_Delete(font);
	cw("HK_swfFont_Delete result: %p", r);
	g_instance->InvokeOnDeleteFont(font);

	cw("EndHook HK_swfFont_Delete");
	return r;
}



FontManager::FontManager()
{
	g_instance = this;
}
void FontManager::RegisterOnCreateFont(OnCreateFont fn)
{
	m_onCreateFontSet.insert(fn);
}
void FontManager::RegisterOnDeleteFont(OnDeleteFont fn)
{
	m_onDeleteFontSet.insert(fn);
}
void FontManager::InvokeOnCreateFont(swfFont* font)
{
	g_gameFonts.insert(font);

	for (auto& fn : m_onCreateFontSet) {
		fn(font);
	}
}
void FontManager::InvokeOnDeleteFont(swfFont* font)
{
	g_gameFonts.erase(font);

	for (auto& fn : m_onDeleteFontSet) {
		fn(font);
	}
}

FontManager* FontManager::Instance()
{
	return g_instance;
}

bool FontManager::Init()
{
	HookRva(0x19b3b0, HK_SwfFont_VF16_Reader, &fn_SwfFont_VF16_Reader);
	HookRva(0x195e80, HK_swfFont_Delete, &fn_swfFont_Delete);
	return true;
}

std::unordered_set<swfFont*> FontManager::GetFonts()
{
	return g_gameFonts;
}

std::string FontManager::MakeGameFontNameKey(std::string gameFontName)
{
	static std::unordered_map<std::string, std::string> g_cache;
	if (g_cache.contains(gameFontName))
		return g_cache[gameFontName];
	return g_cache[gameFontName] = StringRemove(ToLower(gameFontName), " ");
}


