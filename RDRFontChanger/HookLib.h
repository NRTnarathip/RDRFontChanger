#pragma once
#include <unordered_map>
#include <iostream>
#include <cstdint>
#include "Logger.h"
#include "XMem.h"

namespace HookLib {
	void Init();
	void DisableHooks();
	bool HookFuncAddr(void* targetFunc, void* detour, void* ppBackupFunc);
	bool HookFuncRva(uintptr_t funcRva, void* detour, void* ppBackup);
	bool HookFuncImport(const wchar_t* moduleName, const char* importName, void* detour, void* ppBackup);
}
