#include "Hooks.h"
#include "script.h"
#include "MinHook.h"
#pragma comment(lib, "libMinHook.x64.lib")
#include <unordered_map>
#include "Logger.h"
#include <string>
#define logFormat logIt
#include <stacktrace>
#include "CustomFont.h"

uintptr_t Hooks::GetImageBase() {
	static uintptr_t g_imageBase = (uintptr_t)GetModuleHandleA(NULL);
	if (g_imageBase == NULL)
		g_imageBase = (uintptr_t)GetModuleHandleA(NULL);
	return g_imageBase;
}

std::string GetModuleNameFromAddress(void* addr)
{
	MEMORY_BASIC_INFORMATION mbi{};
	if (!VirtualQuery(addr, &mbi, sizeof(mbi)))
		return "";

	HMODULE hMod = (HMODULE)mbi.AllocationBase;

	char path[MAX_PATH]{};
	if (!GetModuleFileNameA(hMod, path, sizeof(path)))
		return "";

	// ตัด path เหลือแค่ชื่อไฟล์
	const char* filename = strrchr(path, '\\');
	if (filename)
		return filename + 1;

	return path;
}
void Hooks::PrintStackRva()
{
	std::stringstream ss;
	auto stack = std::stacktrace::current();
	ss << stack;
	auto stackString = ss.str();
	logFormat("Stack trace...");
	logFormat("image base: %llx", GetImageBase());
	logFormat("\n%s", stackString.c_str());

	return;
	//void* stack[64];
	//const int maxFrames = 30;
	//USHORT frameCount = RtlCaptureStackBackTrace(0, maxFrames, stack, NULL);

	//// หา module base ของปัจจุบัน
	//uintptr_t base = GetImageBase();
	//logFormat("Stack Trace...");
	//for (USHORT i = 0; i < frameCount; i++)
	//{
	//	uintptr_t addr = (uintptr_t)stack[i] - 8;
	//	uintptr_t rva = addr - base;
	//	std::string moduleName = GetModuleNameFromAddress((void*)addr);
	//	logFormat("[#%-2d] VA = %p | RVA = 0x%llX | %s",
	//		i,
	//		(void*)addr,
	//		rva,
	//		moduleName.c_str()
	//	);
	//}
	//logFormat("End Stack Trace!");
}

uintptr_t Hooks::GetRvaFromAddress(uintptr_t addr)
{
	return (uintptr_t)(addr - GetImageBase());
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
	return (void*)(Hooks::GetImageBase() + rva);
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

typedef uint(*GetGlyphFromChar_Fn)(swfFont* p1_font, unsigned char p2_char);
GetGlyphFromChar_Fn backup_GetGlyphFromChar;
uint HK_GetGlyphFromChar(swfFont* font, unsigned short charCode) {
	logFormat("GetGlyphFromChar()!!");
	logFormat("font: %p", font);
	logFormat("char code: %d", charCode);

	if (backup_GetGlyphFromChar == 0)
		backup_GetGlyphFromChar = (GetGlyphFromChar_Fn)GetAddressFromRva(0x196860);

	auto result = backup_GetGlyphFromChar(font, charCode);
	logFormat("result: %d", result);
	return result;
}

#include <unordered_set>

std::string TranslateThaiText(swfFont* font, std::string text) {
	CustomFont::TryRegisterThaiFontGlyphs(font);

	// not replace font yet
	return text;
}



struct swfEDITFONT {
	void* offset1;
	void* offset2;
	void* offset3;
	// 0x18
	const char* string;
	const char* varName;
	int64_t stringSize;
};

bool IsFontObj(void* obj) {
	if (obj == nullptr)
		return false;

	auto font = (swfFont*)obj;
	if (font->vftable == nullptr)
		return false;

	uintptr_t vf0 = Hooks::GetRvaFromAddress((uintptr_t)font->vftable[0]);
	return vf0 == 0x195980;
}


typedef void (*HK_DrawTextWithFont_TypeDef)(
	swfEDITFONT* p1, const char* p2, swfFont* p3, LONGLONG p4,
	LONGLONG p5, LONGLONG p6, LONGLONG p7);
HK_DrawTextWithFont_TypeDef backup_DrawTextWithFont;
static void HK_DrawTextWithFont(
	swfEDITFONT* p1, const char* p2_text, swfFont* p3_font, LONGLONG p4,
	LONGLONG p5, LONGLONG p6, LONGLONG p7) {
	logFormat("HK_DrawTextWithFont!!");
	logFormat("draw text: %s", (const char*)p2_text);
	//logFormat("font: %p", p3_font);
	//logFormat("font info...");
	//logFormat("p3->glyphCount: %d", p3_font->glyphCount);
	//logFormat("p3->codeToGlyph: %p", p3_font->codeToGlyph);
	//logFormat("p3->glyphToCode: %p", p3_font->glyphToCode);
	//logFormat("p3->langCode: %d", p3_font->langCode);
	//logFormat("p3->sheetCount: %d", p3_font->sheetCount);

	// debug glyph all
	//for (int i = 0; i < p3_font->glyphCount;i++) {
	//GLYPH* g = GetGlyphFromChar(p3_font, 0x0);
	auto font = p3_font;
	//char* fontName = (char*)(font + 1);
	//logFormat("font name: %s", fontName);

	//char charCode = 'Q';
	//logFormat("charCode: %d", charCode);
	//auto index = GetGlyphFromChar(p3_font, charCode);
	// logFormat("g index: %d", index);
	//backup_GetGlyphFromChar = (GetGlyphFromChar_Fn)GetAddressFromRva(0x196860);
	//uint glyphIndex = backup_GetGlyphFromChar(p3_font, charCode);
	//logFormat("glyph index: %d", glyphIndex);
	//logFormat("sheet array ptr: %p", font->sheetArrayPtr);
	//auto sheet = font->sheetArrayPtr;
	//logFormat("sheet ptr: %p", sheet);
	//logFormat("sheet glyph array ptr: %p", sheet->glyphArrayPtr);

	//auto g = (GLYPH*)((uintptr_t)sheet->glyphArrayPtr + glyphIndex * 0x20);
	//logFormat("glyph ptr: %p", g);
	//logFormat("x: %.2f", g->left);
	//logFormat("y: %.2f", g->top);
	//logFormat("width: %.2f", g->width);
	//logFormat("height: %.2f", g->height);
	//logFormat("0x10: %.2f", g->unk0x10);
	//logFormat("0x14: %.2f", g->unk0x14);
	//logFormat("0x18: %.2f", g->unk0x18);
	//logFormat("0x1C: %.2f", g->unk0x1C);

	//uintptr_t fontDtorRva = Hooks::GetRvaFromAddress((uintptr_t)p3_font->vftable[0]);
	//logFormat("font vf0 rva: 0x%x", fontDtorRva);

	std::string replaceString = "";
	if (p2_text != nullptr)
		replaceString = p2_text;


	// replace font glyphs
	if (replaceString.empty() == false)
		replaceString = TranslateThaiText(font, replaceString);


	backup_DrawTextWithFont(p1, replaceString.c_str(), p3_font, p4, p5, p6, p7);
}

typedef void* (*LoadFlashFile_Fn)(const char* p1);
LoadFlashFile_Fn backup_LoadFlashFile;
void* LoadFlashFile(const char* p1) {
	logFormat("Hook LoadFlashFile, path: %s", *((char**)p1 + 0x8));
	logFormat("p1: %p", (void*)p1);
	auto result = backup_LoadFlashFile(p1);
	logFormat("loaded flash file: result: %p", result);
	Hooks::PrintStackRva();
	logFormat("EndHook LoadFlashFile()!");
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

typedef void* (*swfFontDeclareStruct_Fn)(swfFont* self, void* p1);
swfFontDeclareStruct_Fn backup_swfFontDeclareStruct;
void* swfFontDeclareStruct(swfFont* self, void* p1) {
	logFormat("Hook swfFontDeclareStruct");
	logFormat("self: %p", self);
	logFormat("p1: %p", p1);
	auto result = backup_swfFontDeclareStruct(self, p1);
	logFormat("result: %p", result);
	return result;
}

typedef void* (*HK_swfFont_VF0_Fn)(void* p1, void* p2);
HK_swfFont_VF0_Fn backup_swfFont_VF0;
void* HK_swfFont_VF0(void* p1, void* p2) {
	logFormat("HK_swfFont_VF0");
	logFormat("p1: %p", p1);
	logFormat("p2: %p", p2);
	auto result = backup_swfFont_VF0(p1, p2);
	logFormat("result: %p", result);
	return result;
}
void* (*backup_swfSomeFactory)(int p1);
void* HK_swfSomeFactory(int p1) {
	logFormat("HK_swfSomeFactory");
	logFormat("p1: %d", p1);
	auto result = backup_swfSomeFactory(p1);
	logFormat("result: %p", result);

	//create swfFont??
	if (IsFontObj(result)) {
		logFormat("this obj is swfFont: %p", result);
		logFormat("swfFont rva: %llx", Hooks::GetRvaFromAddress((uintptr_t)result));
		Hooks::PrintStackRva();
	}
	logFormat("EndHook: HK_swfSomeFactory");

	return result;
}


void* (*backup_PushFolder)(void* p1, const char* p2);
void* PushFolder(void* p1, const char* p2) {
	logFormat("Hook PushFolder");
	logFormat("p2: %s", p2);
	auto res = backup_PushFolder(p1, p2);
	//logFormat("EndHook PushFolder");
	return res;
}

void* (*backup_fiAssetManager_Open)(void* self, char* param_2,
	char* param_3, void* param_4, void* p5, void* p6);
void* fiAssetManager_Open(void* self, char* p2, char* p3, void* p4, void* p5, void* p6) {
	logFormat("Hook fiAssetManager_Open");
	std::string path1(p2);
	logFormat("path1: %s", path1.c_str());
	auto res = backup_fiAssetManager_Open(self, p2, p3, p4, p5, p6);
	logFormat("res: %p", res);
	logFormat("EndHook fiAssetManager_Open");
	return res;
}

void* (*backup_PackFileInit)(void* p1, void* p2, void* p3, void* p4);
void* PackFileInit(void* p1, char* p2, void* p3, void* p4) {
	logFormat("Hook PackFileInit");
	std::string fileName = p2;
	logFormat("packFileName: %s", fileName.c_str());
	auto res = backup_PackFileInit(p1, p2, p3, p4);
	logFormat("EndHook PackFileInit");
	return res;
}

void* (*g_CreateAndMountRedemptionPackfile)(char* p1);
void* CreateAndMountRedemptionPackfile(char* p1) {
	logFormat("Hook CreateAndMountRedemptionPackfile");
	std::string fileName = p1;
	logFormat("rpf name: %s", fileName.c_str());
	auto res = g_CreateAndMountRedemptionPackfile(p1);
	logFormat("EndHook CreateAndMountRedemptionPackfile");
	return res;
}

void Hooks::SetupHooks()
{
	// hooks
	if (MH_Initialize() != MH_OK) {
		logFormat("minhook initialization failed");
	}

	HookFuncRva(0x1979c0, HK_DrawTextWithFont, &backup_DrawTextWithFont);
	// HookFuncRva(0x1fced0, LoadFlashFile, &backup_LoadFlashFile);
	//HookFuncRva(0xc7510, rage_swfCONTEXT_GetGlobal, &backup_rage_swfCONTEXT_GetGlobal);
	//HookFuncRva(0x19b9e0, swfFontDeclareStruct, &backup_swfFontDeclareStruct);
	//HookFuncRva(0x196860, HK_GetGlyphFromChar, &backup_GetGlyphFromChar);
	//HookFuncRva(0x195980, HK_swfFont_VF0, &backup_swfFont_VF0);
	// HookFuncRva(0x194d10, HK_swfSomeFactory, &backup_swfSomeFactory);
	// HookFuncRva(0xc95c0, PushFolder, &backup_PushFolder);
	//HookFuncRva(0xc9140, fiAssetManager_Open, &backup_fiAssetManager_Open);
	//HookFuncRva(0xeae740, PackFileInit, &backup_PackFileInit);
	// HookFuncRva(0x60e080, CreateAndMountRedemptionPackfile, &g_CreateAndMountRedemptionPackfile);
}


