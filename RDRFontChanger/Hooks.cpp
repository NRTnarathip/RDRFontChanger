#include "Hooks.h"
#include "script.h"
#include "MinHook.h"
#pragma comment(lib, "libMinHook.x64.lib")
#include <unordered_map>
#include "Logger.h"
#define logFormat logIt


uintptr_t GetImageBase() {
	static uintptr_t g_imageBase = (uintptr_t)GetModuleHandleA(NULL);
	if (g_imageBase == NULL)
		g_imageBase = (uintptr_t)GetModuleHandleA(NULL);
	return g_imageBase;
}

struct HookInfo {
	void* target;
	void* detour;
	void* backup;
};
std::unordered_map<void*, HookInfo*> g_hookMap;
bool HookFuncAddr(void* targetFunc, void* detour, void* ppBackupFunc) {
	auto it = g_hookMap.find(targetFunc);
	// already hooked at target func
	if (it != g_hookMap.end()) {
		auto hook = it->second;
		if (detour != hook->detour) {
			MessageBoxA(NULL, "Failed to hook. different detour at same target func", "Error", MB_OK | MB_ICONERROR);
			return false;
		}

		*(void**)ppBackupFunc = hook->backup;
		//log("already hook: %p", targetFunc);
		//log("detour: %p", hook->detour);
		//log("backup: %p", hook->backup);
		return true;
	}

	if (MH_CreateHook(targetFunc, detour, (void**)ppBackupFunc) != MH_OK) {
		MessageBoxA(NULL, "Failed to create hook", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	if (MH_EnableHook(targetFunc) != MH_OK)
	{
		MessageBoxA(NULL, "Failed to enable hook", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	auto hook = new HookInfo();
	hook->target = targetFunc;
	hook->backup = *(void**)ppBackupFunc;
	hook->detour = detour;
	g_hookMap[targetFunc] = hook;
	logFormat("hooked func addr: 0x%llx", (uintptr_t)targetFunc);
	logFormat("  detour: %p", hook->detour);
	logFormat("  backup: %p", hook->backup);
	return true;
}

void* GetAddressFromRva(int rva) {
	return (void*)(GetImageBase() + rva);
}
bool HookFuncRva(uintptr_t funcRva, void* detour, void* ppBackup) {
	return HookFuncAddr(GetAddressFromRva(funcRva), detour, ppBackup);
}
bool HookFuncVTable(void* obj, int index, LPVOID detour, void* ppBackup) {
	void** vtable = *(void***)obj;
	return HookFuncAddr(vtable[index], detour, ppBackup);
}

typedef unsigned char U8;
typedef unsigned short U16;
struct SWFLAYOUT {

};
struct SWFGLYPH {

};
struct ALIGNZONE {};
struct FONTUSAGE {};
struct SWFFONT
{
	//int		id; // -1 = not set
	//U8		version; // 0 = not set, 1 = definefont, 2 = definefont2, 3 = definefont3
	//U8* name;
	//SWFLAYOUT* layout;
	//int           numchars;
	//int           maxascii; // highest mapped ascii/unicode value

	//U8		style;
	//U8		encoding;

	//U16* glyph2ascii;
	//int* ascii2glyph;
	//int* glyph2glyph; // only if the font is resorted
	//SWFGLYPH* glyph;
	//ALIGNZONE* alignzones;
	//U8            alignzone_flags;
	//U8		language;
	//char** glyphnames;
	//FONTUSAGE* use;
	char off0xB0[0xb0];
	short sheetCount;
	short ascent;
	short desent;
	short leading;
	unsigned short glyphCount;
	unsigned char flags;
	unsigned char langCode;
	struct Sheet {

	};
	Sheet** sheet;
};

static_assert(offsetof(SWFFONT, sheetCount) == 0xb0, "Assert It");
static_assert(offsetof(SWFFONT, glyphCount) == 0xb8, "Assert It");
static_assert(offsetof(SWFFONT, langCode) == 0xbb, "Assert It");
static_assert(offsetof(SWFFONT, sheet) == 0xc0, "Assert It");


struct swfEDITFONT {
	void* offset1;
	void* offset2;
	void* offset3;
	// 0x18
	const char* string;
	const char* varName;
	int64_t stringSize;
};

typedef void (*HK_DrawTextWithFont_TypeDef)(
	swfEDITFONT* p1, const char* p2, SWFFONT* p3, LONGLONG p4,
	LONGLONG p5, LONGLONG p6, LONGLONG p7);
HK_DrawTextWithFont_TypeDef backup_DrawTextWithFont;
static void HK_DrawTextWithFont(
	swfEDITFONT* p1, const char* p2, SWFFONT* p3, LONGLONG p4,
	LONGLONG p5, LONGLONG p6, LONGLONG p7) {
	logFormat("HK_DrawTextWithFont!!");
	logFormat("draw text: %s", (const char*)p2);
	logFormat("self: %p", (void*)p1);
	logFormat("string: %p", (void*)p2);
	logFormat("font: %p", p3);
	logFormat("p4: %p", (void*)p4);
	logFormat("p5: %p", (void*)p5);
	logFormat("p6: %p", (void*)p6);
	logFormat("p7: %p", (void*)p7);

	logFormat("font info...");
	logFormat("p3->glyphCount: %d", p3->glyphCount);
	logFormat("p3->langCode: %d", p3->langCode);
	logFormat("p3->sheetCount: %d", p3->sheetCount);
	//logFormat("p3 + 0x60: %s", (char*)p3 + 0x60);
	//logFormat("p3 + 0x30: %s", (char*)p3 + 0x30);

	backup_DrawTextWithFont(p1, p2, p3, p4, p5, p6, p7);
	logFormat("called original function!");
}

typedef void* (*LoadFlashFile_Fn)(const char* p1);
LoadFlashFile_Fn backup_LoadFlashFile;
void* LoadFlashFile(const char* p1) {
	logFormat("Hook LoadFlashFile, path: %s", *((char**)p1 + 0x8));
	logFormat("p1: %p", (void*)p1);
	auto result = backup_LoadFlashFile(p1);
	logFormat("loaded flash file: result: %p", result);
	return result;
}


typedef LONGLONG(*rage_swfCONTEXT_GetGlobal_FuncType)(const char* param_1, LONGLONG param_2);
rage_swfCONTEXT_GetGlobal_FuncType backup_rage_swfCONTEXT_GetGlobal;
static LONGLONG rage_swfCONTEXT_GetGlobal(const char* param_1, LONGLONG param_2) {
	logFormat("Hook rage_swfCONTEXT_GetGlobal!!");
	logFormat("p1: %s", param_1);
	auto result = backup_rage_swfCONTEXT_GetGlobal(param_1, param_2);
	logFormat("result: %lld", result);
	return result;
}

typedef void* (*swfFontDeclareStruct_Fn)(SWFFONT* self, void* p1);
swfFontDeclareStruct_Fn backup_swfFontDeclareStruct;
void* swfFontDeclareStruct(SWFFONT* self, void* p1) {
	logFormat("Hook swfFontDeclareStruct");
	logFormat("self: %p", self);
	logFormat("p1: %p", p1);
	auto result = backup_swfFontDeclareStruct(self, p1);
	logFormat("result: %p", result);
	return result;
}


void Hooks::SetupHooks()
{
	// hooks
	if (MH_Initialize() != MH_OK) {
		logFormat("minhook initialization failed");
	}

	HookFuncRva(0x1979c0, HK_DrawTextWithFont, &backup_DrawTextWithFont);
	HookFuncRva(0x1fced0, LoadFlashFile, &backup_LoadFlashFile);
	//HookFuncRva(0xc7510, rage_swfCONTEXT_GetGlobal, &backup_rage_swfCONTEXT_GetGlobal);
	HookFuncRva(0x19b9e0, swfFontDeclareStruct, &backup_swfFontDeclareStruct);
}
