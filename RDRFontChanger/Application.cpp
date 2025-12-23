#include "Application.h"
#include "Logger.h"
#include "TextureChanger.h"
#include "FontReplacer.h"
#include "Hooks.h"
#include "RenderHook.h"
#include "TextTranslator.h"
#include "XMem.h"

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


	// ready
	// load text translate
	TextTranslator::Initialize();


	// debug!!
	Hooks::SetupDebugHooks();

	// register thai font 
	auto fontReplacer = FontReplacer::Instance();
	fontReplacer->RegisterFontFromDir("mods/fonts");
}

void Application::RegisterAllMyModule()
{
	auto& sys = m_systemMgr;
	cw("try Register all module...");


	// reigster here
	sys.Register<TextureReplacer>();
	sys.Register<FontReplacer, TextureReplacer>();
	sys.Register<RenderHook>();
	sys.Register<XMemSystem>();

}
