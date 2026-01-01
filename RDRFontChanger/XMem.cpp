#include "XMem.h"
#include <Windows.h>
#include "HookLib.h"

using namespace HookLib;

void* GetAllocator() {
	static void* instance;
	if (instance == nullptr)
		instance = InvokeRva<void*>(0x7fd70);
	return instance;
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

void* XMem::New(int bytes, int alignBytes)
{
	void* instance = GetAllocator();
	return HookLib::InvokeRva<void*, void*, int, int>(0xaa9a0, instance, bytes, alignBytes);
}

void XMem::Delete(void* objectPtr)
{
	void* instance = GetAllocator();
	InvokeVTable<void, void*>(instance, 4, objectPtr);
}

bool XMemSystem::Init()
{
	return true;
}
