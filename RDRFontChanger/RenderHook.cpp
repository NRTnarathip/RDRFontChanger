#include "RenderHook.h"
#include "HookLib.h"
#include "SWFTypes.h"	
#include "FontReplacer.h"
#include "TextTranslator.h"
#include <iostream>
#include <stdexcept>
#include <stacktrace> 
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

using namespace HookLib;

void PrintStackTrace()
{
	void* stack[62];
	USHORT frames = CaptureStackBackTrace(0, 62, stack, nullptr);

	HANDLE process = GetCurrentProcess();
	SymInitialize(process, nullptr, TRUE);

	for (USHORT i = 0; i < frames; ++i)
	{
		DWORD64 address = (DWORD64)(stack[i]);

		char buffer[sizeof(SYMBOL_INFO) + 256] = { 0 };
		PSYMBOL_INFO symbol = (PSYMBOL_INFO)buffer;
		symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
		symbol->MaxNameLen = 255;

		DWORD64 displacement = 0;
		if (SymFromAddr(process, address, &displacement, symbol))
		{
			cw("[%d]frame : %s - 0x%x", frames - i - 1,
				symbol->Name, symbol->Address);
		}
		else
		{
			cw("[%d]frame : ??? - 0x%x", frames - i - 1, symbol->Address);
		}
	}

	SymCleanup(process);
}

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
	if (p3_font)
		p3_font->LogInfo();

	auto color = swfEditTextDrawColor::Decode(p5_drawColorInt);
	float rNorm = color.r / 255.0;
	float gNorm = color.g / 255.0;
	float bNorm = color.b / 255.0;
	cw("color rgba: %d %d %d %d", color.r, color.g, color.b, color.a);


	__try {
		//	cw("try call backup_DrawTextWithFont");
		backup_DrawTextWithFont(self,
			p2_text, p3_font, p4_fontHeight,
			p5_drawColorInt, p6_align, p7_drawInfo);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		cw("crash in backup_DrawTextWithFont");
		PrintStackTrace();
	}

	cw("End HK_DrawTextWithFont");
}


LONG WINAPI MyVEH(EXCEPTION_POINTERS* ep)
{
	auto code = ep->ExceptionRecord->ExceptionCode;
	auto rip = ep->ContextRecord->Rip;
	auto rva = XMem::GetRvaFromAddress(rip);
	cw("RenderHook::VectoredException code=0x%x RIP= %p, RVA: 0x%x",
		code, (void*)rip, rva);
	return EXCEPTION_CONTINUE_SEARCH;
}

RenderHook* g_instance;
bool RenderHook::Init()
{
	g_instance = this;
	// HookRva(0x1979c0, HK_DrawTextWithFont, &backup_DrawTextWithFont);
	// AddVectoredExceptionHandler(1, MyVEH);
	return true;
}

RenderHook* RenderHook::Instance()
{
	return g_instance;
}

