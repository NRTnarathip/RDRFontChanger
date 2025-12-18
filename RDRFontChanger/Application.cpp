#include "Application.h"
#include "Logger.h"
#include "TextureChanger.h"
#include "Hooks.h"

Application::Application() {
}

void Application::SetupOnDllLoaded(HMODULE hModule)
{
	// setup core system
	m_systemMgr.OnAppInit();


	// ready
	RegisterAllMyModule();
}

void Application::RegisterAllMyModule()
{
	auto& sys = m_systemMgr;
	cw("try Register all module...");


	// reigster here
	sys.Register<TextureReplacer>();



	// init all!
	if (!sys.InitializeAll()) {
		cw("failed to system intiialize all");
		return;
	}


	// debug
	Hooks::SetupDebugHooks();
}
