#include "XMem.h"
#include <Windows.h>
#include "HookLib.h"

using namespace HookLib;


void* g_allocatorInstance;

void* (*fn_AllocateInternal)(void* self, uint64_t param_1, uint64_t param_2);
void* HK_AllocateInternal(void* self, uint64_t p1, uint64_t p2) {
	// pn("BeginHook HK_AllocateInternal, self: {}", self);
	//uintptr_t selfRva = GetRvaFromAddress(self);
	//pn("selfRva: 0x{:x}", selfRva);
	//pn("p1: {:x}", (int)p1);
	//pn("p2: {:x}", (int)p2);

	g_allocatorInstance = self;

	auto r = fn_AllocateInternal(self, p1, p2);
	//if (p1 == 0x3100 && p2 == 4
	//	|| p1 == 0x3160 && p2 == 4) {
	//	pn("HK_AllocateInternal result: {}", r);
	//}

	//	cw("EndHook HK_AllocateInternal");
	return r;
}

uintptr_t XMem::GetImageBase() {
	static uintptr_t g_imageBase = 0;
	if (g_imageBase == NULL)
		g_imageBase = (uintptr_t)GetModuleHandleA(NULL);
	return g_imageBase;
}

uintptr_t XMem::GetRvaFromAddress(uintptr_t addr)
{
	return (uintptr_t)(addr - GetImageBase());
}

uintptr_t XMem::GetRvaFromAddress(void* addr)
{
	return (uintptr_t)addr - GetImageBase();
}

void* XMem::GetAddressFromRva(int rva) {
	return (void*)(GetImageBase() + rva);
}

bool XMem::IsPointerReadable(void* ptr, size_t size) {
	__try {
		volatile char active_read = *(char*)ptr;
		return !IsBadReadPtr(ptr, size);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return false;
	}
}

void* XMem::Allocate(int bytes, int alignBytes)
{
	return HookLib::InvokeRva<void*, void*, int, int>(0xaa9a0, g_allocatorInstance, bytes, alignBytes);
}

bool XMemSystem::Init()
{
	HookLib::HookRva(0xaa9a0, HK_AllocateInternal, &fn_AllocateInternal);
	return true;
}
