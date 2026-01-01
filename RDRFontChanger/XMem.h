#pragma once
#include <cstdint>
#include "ISystem.h"

namespace XMem {
	uintptr_t GetImageBase();
	uintptr_t GetRvaFromAddress(uintptr_t addr);
	uintptr_t GetRvaFromAddress(void* addr);
	void* GetAddressFromRva(int rva);
	void* New(int bytes, int alignBytes);
	void Delete(void* ptr);
}

class XMemSystem :public ISystem {
public:
	bool Init() override;
};
