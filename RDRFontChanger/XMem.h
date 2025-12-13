#pragma once
#include <cstdint>

namespace XMem {
	uintptr_t GetImageBase();
	uintptr_t GetRvaFromAddress(uintptr_t addr);
	void* GetAddressFromRva(int rva);
}
