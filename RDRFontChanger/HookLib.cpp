#include "HookLib.h"
#include "Logger.h"
#include <Windows.h>
#include "XMem.h"
using namespace XMem;

#include "MinHook.h"
#pragma comment(lib, "libMinHook.x64.lib")

struct HookInfo {
	void* target;
	void* detour;
	void* backup;
};
std::unordered_map<void*, HookInfo*> g_hookMap;

void HookLib::Init()
{
	// hooks
	if (MH_Initialize() != MH_OK) {
		logFormat("minhook initialization failed");
	}
}

bool HookLib::HookFuncAddr(void* targetFunc, void* detour, void* ppBackupFunc) {
	auto it = g_hookMap.find(targetFunc);
	// already hooked at target func
	if (it != g_hookMap.end()) {
		auto hook = it->second;
		if (detour != hook->detour) {
			MessageBoxA(NULL, "Failed to hook. different detour at same target func", "Error", MB_OK | MB_ICONERROR);
			return false;
		}

		*(void**)ppBackupFunc = hook->backup;
		//log("already hook: %p", targetFunc);
		//log("detour: %p", hook->detour);
		//log("backup: %p", hook->backup);
		return true;
	}

	if (MH_CreateHook(targetFunc, detour, (void**)ppBackupFunc) != MH_OK) {
		MessageBoxA(NULL, "Failed to create hook", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	if (MH_EnableHook(targetFunc) != MH_OK)
	{
		MessageBoxA(NULL, "Failed to enable hook", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	auto hook = new HookInfo();
	hook->target = targetFunc;
	hook->backup = *(void**)ppBackupFunc;
	hook->detour = detour;
	g_hookMap[targetFunc] = hook;
	auto rva = GetRvaFromAddress((uintptr_t)targetFunc);
	logFormat("hooked func addr: 0x%llx, rva: 0x%llx", (uintptr_t)targetFunc, rva);
	//logFormat("  detour: %p ", hook->detour);
	//logFormat("  backup: %p", hook->backup);
	return true;
}

bool HookLib::HookFuncRva(uintptr_t funcRva, void* detour, void* ppBackup) {
	return HookFuncAddr(GetAddressFromRva(funcRva), detour, ppBackup);
}
