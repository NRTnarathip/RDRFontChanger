#pragma once
#include <unordered_map>
#include <iostream>
#include <cstdint>
#include "Logger.h"
#include "XMem.h"

namespace HookLib {
	void DisableHooks();
	bool HookAddr(void* targetFunc, void* detour, void* ppBackupFunc);
	bool HookRva(uintptr_t funcRva, void* detour, void* ppBackup);
	bool HookImport(const wchar_t* moduleName, const char* importName, void* detour, void* ppBackup);


	template<typename Ret, typename... Args>
	Ret InvokeRva(uintptr_t rva, Args... args)
	{
		uintptr_t addr = (uintptr_t)XMem::GetAddressFromRva(rva);
		using Fn = Ret(__fastcall*)(Args...);
		return ((Fn)(addr))(args...);
	}

	template<typename Ret, typename... Args>
	Ret Invoke(void* addr, Args... args)
	{
		using Fn = Ret(__fastcall*)(Args...);
		return ((Fn)(addr))(args...);
	}


	template<typename Ret, typename... Args>
	Ret InvokeVTable(void* instance, int vtableIndex, Args... args)
	{
		using Fn = Ret(__fastcall*)(Args...);
		void** vftable = *(void***)instance;
		return ((Fn)(vftable[vtableIndex]))(args...);
	}
}

