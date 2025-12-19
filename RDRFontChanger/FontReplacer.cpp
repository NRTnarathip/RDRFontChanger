#include "FontReplacer.h"
#include "Logger.h"
#include <unordered_map>
#include <unordered_set>
#include "CustomFont.h"

std::unordered_map<swfFont*, CustomFont*> g_registeredFonts;

FontReplacer* FontReplacer::g_instance;

BitmapFont* GetThaiFont()
{
	static BitmapFont font;
	if (font.isLoaded == false)
		font.Load("mods/fonts/thai.fnt");

	return &font;
}


bool FontReplacer::Init()
{
	return true;
}

//CustomFont* FontReplacer::Register(swfFont* font, CustomFont* newFont)
//{
//	// check is registered?
//	if (g_registeredFonts.contains(font)) {
//		return g_registeredFonts[font];
//	}
//
//	// create new custom font
//	auto thaiFont = GetThaiFont();
//	auto customFont = new CustomFont(font, thaiFont);
//	g_registeredFonts[font] = customFont;
//	return nullptr;
//}

CustomFont* FontReplacer::TryReplaceToThaiFont(swfFont* originalFont) {
	cw("try replace font: %p", originalFont);
	// check is registered?
	if (g_registeredFonts.contains(originalFont))
		return g_registeredFonts[originalFont];

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

	// ready
	auto thaiFont = GetThaiFont();
	auto customFont = new CustomFont(originalFont, thaiFont);
	g_registeredFonts[originalFont] = customFont;


	logFormat("replaced original font: %p", originalFont);
	return customFont;
}

