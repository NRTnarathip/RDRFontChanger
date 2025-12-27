#include "Application.h"
#include "Logger.h"
#include "TextureChanger.h"
#include "FontReplacer.h"
#include "Hooks.h"
#include "RenderHook.h"
#include "TextTranslator.h"
#include "XMem.h"
#include "FontManager.h"
#include "HookLib.h"
using namespace HookLib;

void* (*fn_ShowError3)(uint64_t param_1, uint64_t param_2, void*, void*);
void* HK_ShowError3(uint64_t param_1, uint64_t param_2, void* p3, void* p4) {
	cw("bypass fn_ShowError3");
	return 0;
}


Application::Application() {}

void Application::SetupOnDllLoaded(HMODULE hModule)
{
	// setup core system
	m_systemMgr.OnAppInit();
	RegisterAllMyModule();
	// init all!
	if (!m_systemMgr.InitializeAll()) {
		cw("failed to system intiialize all");
		return;
	}


	// debug!!
	Hooks::SetupDebugHooks();

	// register thai font 
	auto fontReplacer = FontReplacer::Instance();
	fontReplacer->RegisterFontFromDir("mods/fonts");

	// bypass error dialog
	HookLib::HookRva(0xf6f820, HK_ShowError3, &fn_ShowError3);
}

void Application::RegisterAllMyModule()
{
	auto& sys = m_systemMgr;
	cw("try Register all module...");


	// reigster here
	sys.Register<TextureReplacer>();
	sys.Register<RenderHook>();
	sys.Register<XMemSystem>();
	sys.Register<TextTranslator>();
	sys.Register<FontManager>();

	sys.Register<FontReplacer, TextureReplacer, FontManager>();

}
