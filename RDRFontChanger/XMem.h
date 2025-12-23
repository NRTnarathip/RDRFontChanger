#pragma once
#include <cstdint>
#include "ISystem.h"

namespace XMem {
	uintptr_t GetImageBase();
	uintptr_t GetRvaFromAddress(uintptr_t addr);
	uintptr_t GetRvaFromAddress(void* addr);
	void* GetAddressFromRva(int rva);
	bool IsPointerReadable(void* ptr, size_t size = 8);
	void* Allocate(int bytes, int alignBytes);
}

class XMemSystem :public ISystem {
public:
	bool Init() override;
};
