#include "dllmain.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <cstdint>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdarg>
#include <filesystem>
#include "Logger.h"
#include "Hooks.h"
#include "TextureChanger.h"
#include <unordered_set>
#include "Application.h"
#include "GameVerify.h"

void Setup(HMODULE module) {
	if (GameVerify::Assert() == false) {
		MessageBoxA(NULL, "Failed to game integrity check!", "Error", MB_OK | MB_ICONERROR);
		return;
	}

	Application* app = new Application();
	app->SetupOnDllLoaded(module);
}

void Detach() {
	Hooks::OnDetachDLL();
}

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		Setup(hInstance);
		break;
	case DLL_PROCESS_DETACH:
		Detach();
		break;
	}
	return TRUE;
}
