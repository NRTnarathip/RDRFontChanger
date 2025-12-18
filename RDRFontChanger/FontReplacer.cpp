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

void FontReplacer::TryReplaceMainFontToThai(swfFont* font) {
	cw("try replace font: %p", font);
	// assert
	auto sheet = font->sheetArrayPtr;
	if (sheet == nullptr) {
		cw("font sheet is null!");
		return;
	}

	// debug
	// support only main font!
	if (sheet->DoesTextureExist("RDR2Narrow.charset_0.dds") == false)
		return;

	// check is registered?
	if (g_registeredFonts.contains(font))
		return;

	// create new custom font
	auto customFont = new CustomFont(font);
	g_registeredFonts[font] = customFont;

	auto& thaiFont = *GetThaiFont();

	// replace all glyph
	cw("try replace all glyph...");
	for (int i = 0;i < thaiFont.glyphs.size();i++) {
		auto& newGlyph = thaiFont.glyphs[i];
		customFont->ReplaceGlyph(font, thaiFont, newGlyph);
	}

	logFormat("registered font all glyph for: %p", font);
}

