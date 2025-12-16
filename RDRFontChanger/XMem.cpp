#include "XMem.h"
#include <Windows.h>

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
