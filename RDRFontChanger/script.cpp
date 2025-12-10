#include "script.h"
#include "keyboard.h"
#include <string>
#include <format>
#include <vector>
#include <filesystem>
#include <unordered_map>
#include <mutex>
#include "Hooks.h"
#include "Logger.h"
#define logFormat logIt

int MyFont::g_thaiFont = 0;

void PrintStatic()
{
	int static_ = (int)*getStaticPtr("$/content/scripting/designerdefined/short_update_thread", 119);
	std::string msg = std::format("Static_119: {}", (float)static_);
	HUD::HUD_CLEAR_OBJECTIVE_QUEUE();
	HUD::PRINT_OBJECTIVE_B(msg.c_str(), 2.0f, true, 2, 1, 0, 0, 0);
}

void printGlobal()
{
	int ptr = (int)*getGlobalPtr(54086);
	std::string msg = std::format("Stat: {}", ptr);
	HUD::HUD_CLEAR_OBJECTIVE_QUEUE();
	HUD::PRINT_OBJECTIVE_B(msg.c_str(), 2.0f, true, 2, 1, 0, 0, 0);
}

void printMessage(std::string msg) {
	HUD::HUD_CLEAR_OBJECTIVE_QUEUE();
	HUD::PRINT_OBJECTIVE_B(msg.c_str(), 2.0f, true, 2, 1, 0, 0, 0);
}


void SetupOnDllMain(HMODULE hInstance) {
	Logger::Instance();

	// scriptRegister(hInstance, ScriptMain);
	MyFont::RegisterFonts();
	keyboardHandlerRegister(OnKeyboardMessage);

	Hooks::SetupHooks();

	logFormat("Setup Main Dll!");
}

void ScriptMain()
{
	srand(static_cast<unsigned int>(GetTickCount64()));

	while (true)
	{
		drawText(0.5f, 0.5f,
			"<outline><33c4ff>outlined text</33c4ff></outline> "
			"<outline><sepia>Outlined sepia text</sepia></outline> "
			"<0xFcAf17>hex color text</0xFCAF17> "
			"normal text here & こんにちは "
			"<outline><shadow><00FF00>Text with shadow and outline</00FF00></shadow></outline>",
			255, 255, 255, 255, MyFont::g_thaiFont, 0.03f, Center);

		scriptWait(0);
	}
}

void MyFont::RegisterFonts()
{
	// Register custom fonts
	auto currentPath = std::filesystem::current_path();
	auto fontPathString = (currentPath / "noto-sans-jp-japanese-500-normal.ttf").string();
	auto fontPath = fontPathString.c_str();
	MyFont::g_thaiFont = getCustomFontByPath(fontPath);
	if (MyFont::g_thaiFont == -1) {
		MyFont::g_thaiFont = registerFont(fontPath, 50);
	}
}