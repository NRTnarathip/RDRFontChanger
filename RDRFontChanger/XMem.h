#pragma once
#include <cstdint>

namespace XMem {
	uintptr_t GetImageBase();
	uintptr_t GetRvaFromAddress(uintptr_t addr);
	uintptr_t GetRvaFromAddress(void* addr);
	void* GetAddressFromRva(int rva);
}
