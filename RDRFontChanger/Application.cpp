#include "Application.h"
#include "Logger.h"
#include "TextureChanger.h"
#include "FontReplacer.h"
#include "Hooks.h"

Application::Application() {
}

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
}

void Application::RegisterAllMyModule()
{
	auto& sys = m_systemMgr;
	cw("try Register all module...");


	// reigster here
	sys.Register<TextureReplacer>();
	sys.Register<FontReplacer, TextureReplacer>();




	// debug
	Hooks::SetupDebugHooks();
}
