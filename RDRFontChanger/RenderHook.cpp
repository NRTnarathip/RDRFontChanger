#include "RenderHook.h"
#include "HookLib.h"
#include "SWFTypes.h"	
#include "FontReplacer.h"
#include "TextTranslator.h"

using namespace HookLib;


typedef void* (*HK_DrawTextWithFont_TypeDef)(
	swfEditText* p1, const char* p2, swfFont* p3, uint64_t p4,
	uint64_t p5, uint64_t p6_align, void* p7, void* p8);
HK_DrawTextWithFont_TypeDef backup_DrawTextWithFont;
static void* HK_DrawTextWithFont(
	swfEditText* self, const char* p2_text, swfFont* p3_font, uint64_t p4_fontHeight,
	uint64_t p5_drawColorInt, uint64_t p6_align, void* p7_drawInfo, void* p8_drawCtx) {
	cw("HK_DrawTextWithFont!!");
	cw("draw text: %s", (const char*)p2_text);
	cw("p3_font: %p", p3_font);
	cw("p8_drawCtx: %p", p8_drawCtx);

	auto color = swfEditTextDrawColor::Decode(p5_drawColorInt);
	float rNorm = color.r / 255.0;
	float gNorm = color.g / 255.0;
	float bNorm = color.b / 255.0;
	float gray = (rNorm * 0.299) + (gNorm * 0.587) + (bNorm * 0.114);
	cw("color rgba: %d %d %d %d", color.r, color.g, color.b, color.a);
	cw("p6_align: %d", p6_align);

	if (p3_font)
		p3_font->LogInfo();


	// init patch all fonts!
	auto fontReplacer = FontReplacer::Instance();
	int totalFonts = FontReplacer::g_gameFonts.size();
	static int g_lastInitFontCount;
	cw("total game fonts: %d", totalFonts);
	if (g_lastInitFontCount != totalFonts) {
		int prevInitFontCount = g_lastInitFontCount;
		g_lastInitFontCount = totalFonts;

		cw("try init load all custom font...");
		for (int i = prevInitFontCount; i < totalFonts;i++) {
			auto font = FontReplacer::g_gameFonts[i];
			fontReplacer->TryLoadCustomFont(font);
		}
		cw("done loaded all custom font...");
	}


	// get it

	std::string drawTextString = p2_text ? p2_text : "";

	// we can translate text when font is support 
	auto customFont = fontReplacer->TryGetCustomFont(p3_font);
	if (customFont && drawTextString.size() >= 2) {
		// translate text with new font!
		TextTranslator::TryTranslate(drawTextString);
	}

	cw("try call backup_DrawTextWithFont");
	auto result = backup_DrawTextWithFont(self,
		drawTextString.c_str(), p3_font, p4_fontHeight,
		p5_drawColorInt, p6_align, p7_drawInfo, p8_drawCtx);

	cw("EndHook backup_DrawTextWithFont: result: %p", result);
	return result;
}


RenderHook* g_instance;
bool RenderHook::Init()
{
	g_instance = this;
	HookRva(0x1979c0, HK_DrawTextWithFont, &backup_DrawTextWithFont);
	return true;
}

RenderHook* RenderHook::Instance()
{
	return g_instance;
}

