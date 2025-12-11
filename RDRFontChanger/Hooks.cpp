#include "Hooks.h"
#include "script.h"
#include "MinHook.h"
#pragma comment(lib, "libMinHook.x64.lib")
#include <unordered_map>
#include "Logger.h"
#include <string>
#define logFormat logIt
#include <stacktrace>

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
struct SWFLAYOUT {

};
struct SWFGLYPH {

};
struct ALIGNZONE {};
struct FONTUSAGE {};
struct GLYPH {
	float xOffset;
	float yOffset;
	float width;
	float height;
	float unk0x10;
	float unk0x14;
	float unk0x18;
	float unk0x1C;
};
static_assert(sizeof(GLYPH) == 0x20, "Assert Size");
struct Sheet {
	void* unk0x0;
	void* glyphArrayPtr;
};
struct SWFFONT
{
	void** vftable; // 0x0 -> 0x8
	void* _0x8;
	void* _0x10;
	void* _0x18; // 0x18 -> 0x20
	USHORT* glyphToCode; //0x20 - > 0x28
	void* advance;
	void* codeToGlyph; // 0x30 -> 0x38
	char _0x38_0xB0[0x78];
	short sheetCount;
	short ascent;
	short desent;
	short leading;
	unsigned short glyphCount;
	unsigned char flags;
	unsigned char langCode;
	Sheet* sheetArrayPtr;
};

static_assert(offsetof(SWFFONT, glyphToCode) == 0x20, "Assert It");
static_assert(offsetof(SWFFONT, sheetCount) == 0xb0, "Assert It");
static_assert(offsetof(SWFFONT, glyphCount) == 0xb8, "Assert It");
static_assert(offsetof(SWFFONT, langCode) == 0xbb, "Assert It");
static_assert(offsetof(SWFFONT, sheetArrayPtr) == 0xc0, "Assert It");
static_assert(offsetof(SWFFONT, codeToGlyph) == 0x30, "Assert It");

typedef  int (*GetGlyphFromChar_Fn)(SWFFONT* p1_font, unsigned char p2_char);
GetGlyphFromChar_Fn backup_GetGlyphFromChar;
int HK_GetGlyphFromChar(SWFFONT* p1_font, unsigned short p2_char) {
	logFormat("GetGlyphFromChar()!!");
	logFormat("p1 font: %p", p1_font);
	logFormat("p2 char: %d", p2_char);
	auto result = backup_GetGlyphFromChar(p1_font, p2_char);
	logFormat("result: %d", result);
	return result;
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

	auto font = (SWFFONT*)obj;
	if (font->vftable == nullptr)
		return false;

	uintptr_t vf0 = Hooks::GetRvaFromAddress((uintptr_t)font->vftable[0]);
	return vf0 == 0x195980;
}

uint GetGlyphFromChar(SWFFONT* font, USHORT p1_char)
{
	// not sure!!
	if (p1_char < 0x80 && font->codeToGlyph != nullptr) {
		return(ULONG) * (byte*)((long)&font->codeToGlyph + (ULONG)p1_char);
	}

	if (font->glyphCount > 0) {
		uint index = 0;
		do {
			//logFormat("try check glyph To code, current index: %d", index);
			if (*(USHORT*)((long long)font->glyphToCode + (long long)index * 2) == p1_char) {
				//	logFormat("found glyph To code at index: %d", index);
				return index;
			}

			index = index + 1;
		} while (font->glyphCount != index);
	}

	return 0;
}

typedef void (*HK_DrawTextWithFont_TypeDef)(
	swfEDITFONT* p1, const char* p2, SWFFONT* p3, LONGLONG p4,
	LONGLONG p5, LONGLONG p6, LONGLONG p7);
HK_DrawTextWithFont_TypeDef backup_DrawTextWithFont;
static void HK_DrawTextWithFont(
	swfEDITFONT* p1, const char* p2_text, SWFFONT* p3_font, LONGLONG p4,
	LONGLONG p5, LONGLONG p6, LONGLONG p7) {
	logFormat("HK_DrawTextWithFont!!");
	logFormat("draw text: %s", (const char*)p2_text);
	logFormat("font: %p", p3_font);
	//logFormat("p4: %p", (void*)p4);
	//logFormat("p5: %p", (void*)p5);
	//logFormat("p6: %p", (void*)p6);
	//logFormat("p7: %p", (void*)p7);

	logFormat("font info...");
	logFormat("p3->glyphCount: %d", p3_font->glyphCount);
	logFormat("p3->codeToGlyph: %p", p3_font->codeToGlyph);
	logFormat("p3->glyphToCode: %p", p3_font->glyphToCode);
	logFormat("p3->langCode: %d", p3_font->langCode);
	logFormat("p3->sheetCount: %d", p3_font->sheetCount);

	// debug glyph all
	//for (int i = 0; i < p3_font->glyphCount;i++) {
	//GLYPH* g = GetGlyphFromChar(p3_font, 0x0);
	auto font = p3_font;

	char* fontName = (char*)(font + 1);
	logFormat("font name: %s", fontName);

	char charCode = 'Q';
	logFormat("charCode: %d", charCode);
	//auto index = GetGlyphFromChar(p3_font, charCode);
	// logFormat("g index: %d", index);
	backup_GetGlyphFromChar = (GetGlyphFromChar_Fn)GetAddressFromRva(0x196860);
	uint glyphIndex = backup_GetGlyphFromChar(p3_font, charCode);
	logFormat("glyph index: %d", glyphIndex);
	logFormat("sheet array ptr: %p", font->sheetArrayPtr);
	auto sheet = font->sheetArrayPtr;
	logFormat("sheet ptr: %p", sheet);
	logFormat("sheet glyph array ptr: %p", sheet->glyphArrayPtr);

	auto g = (GLYPH*)((uintptr_t)sheet->glyphArrayPtr + glyphIndex * 0x20);
	logFormat("glyph ptr: %p", g);
	logFormat("x: %.2f", g->xOffset);
	logFormat("y: %.2f", g->yOffset);
	logFormat("width: %.2f", g->width);
	logFormat("height: %.2f", g->height);
	logFormat("0x10: %.2f", g->unk0x10);
	logFormat("0x14: %.2f", g->unk0x14);
	logFormat("0x18: %.2f", g->unk0x18);
	logFormat("0x1C: %.2f", g->unk0x1C);

	uintptr_t fontDtorRva = Hooks::GetRvaFromAddress((uintptr_t)p3_font->vftable[0]);
	logFormat("font vf0 rva: 0x%x", fontDtorRva);



	std::string replaceString = "Empty Text";
	if (p2_text != nullptr)
		replaceString = p2_text;

	if (replaceString.contains("Play")) {
		// replaceString = "สวัสดีครับ นี่คือมอด!!";
		// replaceString = "Play With Mods!";
	}

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


