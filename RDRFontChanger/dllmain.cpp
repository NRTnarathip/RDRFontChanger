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
#include "CustomFont.h"
#include "TextureChanger.h"

void Setup() {
	// setup logger first
	auto logger = Logger::Instance();
	logger->ShowConsole();

	// ready to setup framework
	auto textureReplacer = TextureReplacer::InitOnMain();
	// CustomFont::InitOnMain(textureReplacer);

	// debug only!!
	Hooks::SetupHooks();
}

void Detach() {
	Hooks::OnDetachDLL();
}

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		Setup();
		break;
	case DLL_PROCESS_DETACH:
		Detach();
		break;
	}
	return TRUE;
}
