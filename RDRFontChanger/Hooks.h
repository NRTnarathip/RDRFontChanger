#pragma once
#include <cstdint>

class Hooks
{
public:
	static void SetupHooks();
	static uintptr_t GetRvaFromAddress(uintptr_t addr);
	static uintptr_t GetImageBase();
	static void PrintStackRva();
};

