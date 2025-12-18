#include "StringHooks.h"
#include "HookLib.h"

using namespace HookLib;

void* (*fnString_c)(void* self, const char** p1);
void* String_c(void* self, const char** refString) {
	cw("BeginHook String_c");
	cw("self: %p, selfStr", self, *(char**)self);
	cw("string: %s", *refString);
	auto r = fnString_c(self, refString);
	cw("EndHook String_c");
	return r;
}

// String_c::operator=(void *param_1,char **p2)
void* (*fnString_c_operator1)(void* self, const char* p1);
void* String_c_operator1(void* self, const char* p1) {
	cw("BeginHook String_c_operator1");
	cw("self: %p, selfStr: %s", self, *(char**)self);
	cw("string: %s", p1);
	auto r = fnString_c_operator1(self, p1);
	cw("EndHook String_c_operator1");
	return r;
}

// longlong * String_c::operator+=(longlong *param_1,char *param_2)
void* (*fnString_c_operator2)(void* self, const char* p1);
void* String_c_operator2(void* self, const char* refString) {
	cw("BeginHook String_c_operator2");
	cw("self: %p, selfStr: %s", self, *(char**)self);
	cw("string: %s", refString);
	auto r = fnString_c_operator2(self, refString);
	cw("result: %s", *(const char**)r);
	cw("EndHook String_c_operator2");
	return r;
}


void* (*fn_operator_new)(uint64_t size);
void* operator_new(uint64_t size) {
	cw("BeginHook operator_new");
	cw("alloc size: 0x%x", size);
	auto r = fn_operator_new(size);
	cw("result: ptr: %p, end ptr: %p", r, (void*)((uintptr_t)r + size));
	cw("EndHook operator_new");
	// cw("try log font string address...");



	// debug 1c40cb8

	// this ptr: 7FF653F1DBC8 or rva: 0x2C8DBC8
	// access 7FF653F1E020 font rdr2narrow.fnt


	// offset 0x58 struct

	// this addr: 7FF653F1DC20 access that font
	// font2: 7FF653F1E070 rdr2narrow.fnt



	// size 0x58
	struct LanguageItem {
		void* unk; // 0x0 -> 0x8
		char x0[0x18]; // 0x8 -> 0x20
		const char* fontFileName;//0x20 -> 0x28
		char x28_x58[0x30];
	};

	const char* mainFont = (const char*)XMem::GetAddressFromRva(0x2C8E020);
	static bool isLogDone = false;
	if (strlen(mainFont) > 0 && isLogDone == false) {
		isLogDone = true;
		cw("try loop...");
		// first lang ptr: rva+2C8DBA8
		LanguageItem* langItem = (LanguageItem*)XMem::GetAddressFromRva(0x2C8DBA8);
		cw("unk ptr: %p", langItem);
		for (int i = 0; i < 13;i++) {
			cw("try dump at: %p", langItem);
			//cw("lang name: %s", langItem->langName);
			cw("fontPath: %s", langItem->fontFileName);
			langItem++;
		}
	}

	return r;
}

void SetupStringHooks()
{
	HookRva(0xeab3d0, String_c, &fnString_c);
	HookRva(0xeab570, String_c_operator1, &fnString_c_operator1);
	HookRva(0xeab680, String_c_operator2, &fnString_c_operator2);
	//HookFuncRva(0x7d6c0, operator_new, &fn_operator_new);
}
