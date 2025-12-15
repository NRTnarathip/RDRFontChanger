#include "Hooks.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stacktrace>
#include <sstream>
#include <cstdint>

#include "CustomFont.h"
#include "SWFTypes.h"
#include "XMem.h"
#include "HookLib.h"
#include "Logger.h"
#include "StringHooks.h"
#include "FileSystemHook.h"


using namespace XMem;
using namespace HookLib;


std::vector<swfFile*> g_swfFiles;

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

typedef uint32_t(*GetGlyphFromChar_Fn)(swfFont* p1_font, unsigned char p2_char);
GetGlyphFromChar_Fn backup_GetGlyphFromChar;
uint32_t HK_GetGlyphFromChar(swfFont* font, unsigned short charCode) {
	logFormat("GetGlyphFromChar()!!");
	logFormat("font: %p", font);
	logFormat("char code: %d", charCode);

	if (backup_GetGlyphFromChar == 0)
		backup_GetGlyphFromChar = (GetGlyphFromChar_Fn)GetAddressFromRva(0x196860);

	auto result = backup_GetGlyphFromChar(font, charCode);
	logFormat("result: %d", result);
	return result;
}


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
	swfEditText* p1, const char* p2, swfFont* p3, int p4,
	uint32_t p5, byte p6_align, void* p7);
HK_DrawTextWithFont_TypeDef backup_DrawTextWithFont;
static void HK_DrawTextWithFont(
	swfEditText* self, const char* p2_text, swfFont* font, int p4_fontHeight,
	uint32_t p5_drawColorInt, byte p6_align, void* p7) {
	logFormat("HK_DrawTextWithFont!!");
	logFormat("draw text: %s", (const char*)p2_text);
	cw("font: %p", font);
	cw("font height: %d", p4_fontHeight);
	auto color = swfEditTextDrawColor::Decode(p5_drawColorInt);
	cw("draw color: r:%d g:%d b:%d a:%d", color.r, color.g, color.b, color.a);

	cw("editText fontID: %d", self->fontID);
	cw("editText string size: %d", self->stringSize);
	cw("editText string: %s", self->string);
	cw("editText varName: %s", self->varName);
	cw("editText leading: %d", self->leading);
	cw("editText width: %.2f, height: %.2f", self->width, self->height);
	cw("editText offsetX: %.2f, offsetY: %.2f", self->offsetX, self->offsetY);
	auto bound = self->GetBound();
	cw("boundX: %.2f, boundY: %.2f", bound.x, bound.y);
	cw("bound width: %.2f, height: %.2f", bound.width, bound.height);
	CustomFont::TryReplaceSwfFontToThaiFont(font);


	auto sheet = font->sheetArrayPtr;
	cw("sheet: %p", sheet);
	cw("size: %d", sheet->size);
	cw("cell count: %d", sheet->cellCount);
	cw("texture count: %d", sheet->textureCount);
	cw("sheet cell array ptr: %p", sheet->cellArray);
	cw("font glyph array ptr: %p", font->glyphToCodeArrayFirstItem);

	TryDumpSwfFont(font, "onDrawText");

	//cw("total swf files: %d", g_swfFiles.size());
	//for (int i = 0;i < g_swfFiles.size();i++) {
	//	auto file = g_swfFiles[i];
	//	cw("[%d] file: %p", i, file);
	//	cw("name: %s", file->name);
	//}

	std::string replaceString = "";
	if (p2_text != nullptr)
		replaceString = p2_text;


	// replace font glyphs
	//if (replaceString.empty() == false)
	//	replaceString = TranslateThaiText(font, replaceString);


	backup_DrawTextWithFont(self, replaceString.c_str(), font, p4_fontHeight, p5_drawColorInt, p6_align, p7);
}

typedef void* (*LoadFlashFile_Fn)(const char* p1);
LoadFlashFile_Fn backup_LoadFlashFile;
void* LoadFlashFile(const char* p1) {
	logFormat("Hook LoadFlashFile, path: %s", p1);
	auto result = backup_LoadFlashFile(p1);
	logFormat("loaded flash file: result: %p", result);
	// PrintStackRva();
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
	TryDumpSwfFont(self, "swfFontDeclareStructAfter");
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

void* (*fnGrcImageCreate)(void*, void*, void*);
void* HK_GrcImageCreate(void* p1, void* p2, void* p3) {
	addTab();
	cw("BeginHook HK_GrcImageCreate");
	cw("p1: %p, p3: %p", p1, p3);
	cw("img name: %s", (char*)p2);
	auto r = fnGrcImageCreate(p1, p2, p3);
	cw("result: %p", r);
	cw("EndHook HK_GrcImageCreate");
	unTab();
	return r;
}

void* (*backup_swfSomeFactory)(int p1);
void* HK_swfSomeFactory(int p1) {
	addTab();
	logFormat("HK_swfSomeFactory");


	int fileType = p1;
	logFormat("file type: %s", GetSWFTypeName(p1));

	auto result = backup_swfSomeFactory(p1);
	logFormat("result: %p", result);
	//if (fileType == SWFTypeEnum::Font) {
	//	auto font = (swfFont*)result;
	//	TryDumpSwfFont(font, "swfObjFactory");
	//}

	logFormat("EndHook: HK_swfSomeFactory");

	unTab();
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
	cw("result= %p", r);

	DumpPackFile(self);

	cw("EndHook HK_PackFile_c");
	return r;
}


void* (*fn_swfFileNew)(void* p1, void* p2);
void* HK_swfFileNew(void* p1, void* p2) {
	addTab();
	cw("BeginHook HK_swfFileNew");
	cw("p1: %p, p2: %p", p1, p2);
	auto r = fn_swfFileNew(p1, p2);
	cw("result= %p", r);
	cw("recheck p1: %p, p2: %p", p1, p2);
	auto file = (swfFile*)r;
	g_swfFiles.push_back(file);
	cw("EndHook HK_swfFileNew");
	unTab();
	return r;
}

uint64_t(*fnHash)(void* data, uint64_t len, uint64_t seed);
uint64_t HK_Hash(void* data, uint64_t len, uint64_t seed) {
	cw("BeginHook HK_Hash");
	std::string str = (char*)data;
	if (str.size() >= 5)
		cw("data str: %s", str.c_str());

	auto r = fnHash(data, len, seed);
	cw("EndHook HK_Hash");
	return r;
}


void Hooks::OnDetachDLL() {
	HookLib::DisableHooks();
}

void Hooks::SetupHooks()
{
	HookLib::Init();

	HookFuncRva(0x1979c0, HK_DrawTextWithFont, &backup_DrawTextWithFont);
	// HookFuncRva(0x1fced0, LoadFlashFile, &backup_LoadFlashFile);
	// HookFuncRva(0xc7510, rage_swfCONTEXT_GetGlobal, &backup_rage_swfCONTEXT_GetGlobal);
	// HookFuncRva(0x19b9e0, swfFontDeclareStruct, &backup_swfFontDeclareStruct);
	// HookFuncRva(0x196860, HK_GetGlyphFromChar, &backup_GetGlyphFromChar);
	// HookFuncRva(0x195980, HK_swfFont_VF0, &backup_swfFont_VF0);
	HookFuncRva(0x194d10, HK_swfSomeFactory, &backup_swfSomeFactory);
	// HookFuncRva(0xc95c0, PushFolder, &backup_PushFolder);
	// HookFuncRva(0xc9140, fiAssetManager_Open, &backup_fiAssetManager_Open);
	// HookFuncRva(0xc98b0, fiAssetManager_Open2, &backup_fiAssetManager_Open2);
	// HookFuncRva(0xeae740, PackFileInit, &backup_PackFileInit);
	// HookFuncRva(0x60e080, CreateAndMountRedemptionPackfile, &g_CreateAndMountRedemptionPackfile);
	// HookFuncRva(0x88fb70, txtFontTex_Load, &backup_txtFontTex_Load);
	// HookFuncRva(0x11a000, HK_GetMovieID, &backup_GetMovieID);
	// HookFuncRva(0xeae5a0, HK_PackFile_c, &backup_PackFile_c);
	// SetupStringHooks();
	HookFuncRva(0x183eb0, HK_swfFileNew, &fn_swfFileNew);
	HookFuncRva(0x157480, HK_GrcImageCreate, &fnGrcImageCreate);
	SetupFileSystemHook();
	//HookFuncRva(0xeb6730, HK_Hash, &fnHash);
}
