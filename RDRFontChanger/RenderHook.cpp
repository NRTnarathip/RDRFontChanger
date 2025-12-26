#include "RenderHook.h"
#include "HookLib.h"
#include "SWFTypes.h"	
#include "FontReplacer.h"
#include "TextTranslator.h"

using namespace HookLib;


typedef void (*HK_DrawTextWithFont_TypeDef)(
	swfEditText* p1, const char* p2, swfFont* p3, uint64_t p4,
	uint64_t p5, uint64_t p6_align, void* p7);
HK_DrawTextWithFont_TypeDef backup_DrawTextWithFont;
static void HK_DrawTextWithFont(
	swfEditText* self, const char* p2_text, swfFont* p3_font, uint64_t p4_fontHeight,
	uint64_t p5_drawColorInt, uint64_t p6_align, void* p7_drawInfo) {
	cw("Begin HK_DrawTextWithFont!!");
	cw("p2_text: %s", (const char*)p2_text);
	cw("p3_font: %p", p3_font);

	auto color = swfEditTextDrawColor::Decode(p5_drawColorInt);
	float rNorm = color.r / 255.0;
	float gNorm = color.g / 255.0;
	float bNorm = color.b / 255.0;
	cw("color rgba: %d %d %d %d", color.r, color.g, color.b, color.a);

	if (p3_font)
		p3_font->LogInfo();

	static std::string drawTextString;
	drawTextString = p2_text ? p2_text : "";

	auto fontReplacer = FontReplacer::Instance();
	auto customFont = fontReplacer->TryGetCustomFont(p3_font);
	if (customFont && drawTextString.size() >= 2) {
		if (TextTranslator::TryTranslate(drawTextString)) {
			p2_text = drawTextString.c_str();
		}
	}

	cw("try call backup_DrawTextWithFont");
	__try {
		backup_DrawTextWithFont(self,
			p2_text, p3_font, p4_fontHeight,
			p5_drawColorInt, p6_align, p7_drawInfo);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		cw("crash in backup_DrawTextWithFont");
	}

	cw("End HK_DrawTextWithFont");
}


LONG WINAPI MyVEH(EXCEPTION_POINTERS* ep)
{
	auto code = ep->ExceptionRecord->ExceptionCode;
	auto rip = ep->ContextRecord->Rip;
	auto rva = XMem::GetRvaFromAddress(rip);
	cw("RenderHook::VectoredException code=%08X RIP= %p, RVA: 0x%x",
		code, (void*)rip, rva);
	return EXCEPTION_CONTINUE_SEARCH;
}

RenderHook* g_instance;
bool RenderHook::Init()
{
	g_instance = this;
	HookRva(0x1979c0, HK_DrawTextWithFont, &backup_DrawTextWithFont);
	AddVectoredExceptionHandler(1, MyVEH);
	return true;
}

RenderHook* RenderHook::Instance()
{
	return g_instance;
}

