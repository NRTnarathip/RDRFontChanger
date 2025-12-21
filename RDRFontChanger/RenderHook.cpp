#include "RenderHook.h"
#include "HookLib.h"
#include "SWFTypes.h"	
#include "FontReplacer.h"
#include "TextTranslator.h"

using namespace HookLib;

typedef void* (*HK_DrawTextWithFont_TypeDef)(
	swfEditText* p1, const char* p2, swfFont* p3, uint64_t p4,
	uint32_t p5, uint64_t p6_align, uint64_t p7);
HK_DrawTextWithFont_TypeDef backup_DrawTextWithFont;
static void* HK_DrawTextWithFont(
	swfEditText* self, const char* p2_text, swfFont* p3_font, uint64_t p4_fontHeight,
	uint32_t p5_drawColorInt, uint64_t p6_align, uint64_t p7) {
	cw("HK_DrawTextWithFont!!");
	cw("draw text: %s", (const char*)p2_text);
	// cw("font: %p", p3_font);

	// try get font bitmap and sdf
	auto fontReplacer = FontReplacer::Instance();

	auto newCustomFont = fontReplacer->TryReplaceFontNarrowWithSDF(p3_font);
	if (newCustomFont) {

	}

	std::string drawTextString = p2_text ? p2_text : "";
	if (drawTextString.empty() == false) {
		// translate text with new font!
		TextTranslator::TryTranslate(drawTextString);
	}


	// cw("try call backup_DrawTextWithFont");
	auto result = backup_DrawTextWithFont(self, drawTextString.c_str(), p3_font, p4_fontHeight, p5_drawColorInt, p6_align, p7);

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

