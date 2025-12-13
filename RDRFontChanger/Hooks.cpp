#include "Hooks.h"
#include "script.h"
#include "MinHook.h"
#pragma comment(lib, "libMinHook.x64.lib")
#include <unordered_map>
#include "Logger.h"
#include <string>
#include <stacktrace>
#include "CustomFont.h"
#include "SWFTypes.h"
#include "XMem.h"

using namespace XMem;

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

void PrintStackRva()
{
	std::stringstream ss;
	auto stack = std::stacktrace::current();
	ss << stack;
	auto stackString = ss.str();
	logFormat("Stack trace...");
	logFormat("image base: %llx", GetImageBase());
	logFormat("\n%s", stackString.c_str());
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
	//CustomFont::TryRegisterThaiFontGlyphs(font);

	//if (text.contains("Setttings"))
	//	text = "S";
	//else if (text.contains("Play"))
	//	text = "P";
	//else if (text.contains("Quit"))
	//	text = "Q";

	// not replace font yet
	return text;
}




int (*backup_GetMovieID)(void* p1, void* p2);
int HK_GetMovieID(FlashManager* p1, char* p2) {
	logFormat("BeginHook GetMovieID!!");
	cw("p1: %p", p1);
	cw("p2: %s", p2);
	auto result = backup_GetMovieID(p1, p2);
	cw("result: %d", result);

	cw("try dump all find font...");

	//int dumpMovies = 200;
	//for (int i = 0;i < dumpMovies;i++) {
	auto movie = TryGetMovieFromID(p1, result);
	cw("movie ptr: %p, index: %d", movie, result);

	if (movie) {
		auto movieCtx = movie->ctx;
		cw("movie ctx: %p", movieCtx);

		if (movieCtx) {
			auto file = movieCtx->file;
			cw("movie file: %p", file);

			if (file) {
				cw("movie file name: %s", file->name);
				//const char* fontName = "font_rdr2narrow";
				//auto mainFont = FindFont(file, fontName);
			}
		}
	}
	//}

	logFormat("EndHook GetMovieID!!");

	return result;
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
	cw("font: %p", p3_font);
	logFormat("p3->glyphCount: %d", p3_font->glyphCount);

	// check fui flash manager
	auto flashMgr = GetFlashManager();
	cw("flash mgr: %p", flashMgr);
	cw("langName: %s", flashMgr->langName);
	cw("movie id count: %d", flashMgr->movieCount);



	auto font = p3_font;

	std::string replaceString = "";
	if (p2_text != nullptr)
		replaceString = p2_text;


	// replace font glyphs
	//if (replaceString.empty() == false)
	//	replaceString = TranslateThaiText(font, replaceString);


	backup_DrawTextWithFont(p1, replaceString.c_str(), p3_font, p4, p5, p6, p7);
}

typedef void* (*LoadFlashFile_Fn)(const char* p1);
LoadFlashFile_Fn backup_LoadFlashFile;
void* LoadFlashFile(const char* p1) {
	logFormat("Hook LoadFlashFile, path: %s", *((char**)p1 + 0x8));
	logFormat("p1: %p", (void*)p1);
	auto result = backup_LoadFlashFile(p1);
	logFormat("loaded flash file: result: %p", result);
	PrintStackRva();
	logFormat("EndHook LoadFlashFile()!");
	return result;
}


// error!!
typedef void* (*rage_swfCONTEXT_GetGlobal_FuncType)(void* p1, void* param_2, void* p3, void* p4);
rage_swfCONTEXT_GetGlobal_FuncType backup_rage_swfCONTEXT_GetGlobal;
static void* rage_swfCONTEXT_GetGlobal(void* p1, void* p2, void* p3, void* p4) {
	cw("BeginHook rage_swfCONTEXT_GetGlobal ...");
	auto result = backup_rage_swfCONTEXT_GetGlobal(p1, p2, p3, p4);
	cw("result: %p", result);
	cw("EndHook rage_swfCONTEXT_GetGlobal!!");
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
	int fileType = p1;
	logFormat("file type: %s", GetSWFTypeName(p1));

	auto result = backup_swfSomeFactory(p1);
	logFormat("result: %p", result);

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
	//logFormat("res: %p", res);
	logFormat("EndHook fiAssetManager_Open");
	return res;
}

void* (*backup_fiAssetManager_Open2)(void* self, char* p1,
	char* p2, uint64_t p3, uint64_t p4);
void* fiAssetManager_Open2(void* self, char* p1, char* p2, uint64_t p3, uint64_t p4) {
	logFormat("BeginHook fiAssetManager_Open2");
	logFormat("path: %s", p1);
	logFormat("fileType: %s", p2);
	auto res = backup_fiAssetManager_Open2(self, p1, p2, p3, p4);
	//	logFormat("res: %p", res);
	logFormat("EndHook fiAssetManager_Open2");
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

void* (*backup_txtFontTex_Load)(void* self, char* p1_fontPath, bool p2, bool p3);
void* txtFontTex_Load(void* self, char* p1_fontPath, uint64_t p2, uint64_t p3) {
	cw("BeginHook txtFontTex_Load...");
	cw("self: %p", self);
	cw("font path: %s", p1_fontPath);
	cw("p2: %d", p2);
	cw("p3: %d", p3);
	auto result = backup_txtFontTex_Load(self, p1_fontPath, p2, p3);
	cw("result: %p", result);
	cw("try debug font...");

	Fonttext* fnt = (Fonttext*)self;
	cw("char height: %d", fnt->CharHeight);
	cw("NumGlyphs: %d", fnt->NumGlyphs);

	cw("EndHook txtFontTex_Load");
	return result;
}

void* (*backup_PackFile_c)(PackFile_c* self, void* p1, void* p2, void* p3);
void* HK_PackFile_c(PackFile_c* self, void* p1, void* p2, void* p3) {
	cw("BeginHook HK_PackFile_c");
	cw("self: %p", self);
	cw("file name: %s", p1);
	auto r = backup_PackFile_c(self, p1, p2, p3);
	cw("EndHook HK_PackFile_c");
	return r;
}

void Hooks::SetupHooks()
{
	// hooks
	if (MH_Initialize() != MH_OK) {
		logFormat("minhook initialization failed");
	}

	HookFuncRva(0x1979c0, HK_DrawTextWithFont, &backup_DrawTextWithFont);
	// HookFuncRva(0x1fced0, LoadFlashFile, &backup_LoadFlashFile);
	// HookFuncRva(0xc7510, rage_swfCONTEXT_GetGlobal, &backup_rage_swfCONTEXT_GetGlobal);
	//HookFuncRva(0x19b9e0, swfFontDeclareStruct, &backup_swfFontDeclareStruct);
	//HookFuncRva(0x196860, HK_GetGlyphFromChar, &backup_GetGlyphFromChar);
	//HookFuncRva(0x195980, HK_swfFont_VF0, &backup_swfFont_VF0);
	HookFuncRva(0x194d10, HK_swfSomeFactory, &backup_swfSomeFactory);
	// HookFuncRva(0xc95c0, PushFolder, &backup_PushFolder);
	// HookFuncRva(0xc9140, fiAssetManager_Open, &backup_fiAssetManager_Open);
	HookFuncRva(0xc98b0, fiAssetManager_Open2, &backup_fiAssetManager_Open2);
	//HookFuncRva(0xeae740, PackFileInit, &backup_PackFileInit);
	// HookFuncRva(0x60e080, CreateAndMountRedemptionPackfile, &g_CreateAndMountRedemptionPackfile);
	HookFuncRva(0x88fb70, txtFontTex_Load, &backup_txtFontTex_Load);
	HookFuncRva(0x11a000, HK_GetMovieID, &backup_GetMovieID);
	HookFuncRva(0xeae5a0, HK_PackFile_c, &backup_PackFile_c);
}
