#pragma once
#include <Windows.h>
#include "SystemManager.h"

class Application
{
public:
	Application();
	void SetupOnDllLoaded(HMODULE hModule);
private:
	SystemManager m_systemMgr;
	void RegisterAllMyModule();
};

