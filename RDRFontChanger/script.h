#pragma once

#include <Windows.h>

#include <natives.h>
#include <types.h>
#include <enums.h>
#include <main.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <cstdint>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdarg>

class MyFont {
public:
	static int g_thaiFont;
	static void RegisterFonts();
};

void SetupOnDllMain(HMODULE hInstance);

void ScriptMain();
