#include "SystemManager.h"
#include "Logger.h"


SystemManager* SystemManager::g_instance;
void SystemManager::OnAppInit()
{
	InitializeAll();
}

void SystemManager::OnRegisteredType(SystemRegisterData& data)
{
	cw("registed system type: %s", data.name());
}

bool SystemManager::TryCreateSystemInstanceRecursive(SystemRegisterData& sysData)
{
	// already registered
	auto& mainID = sysData.id;
	cw("Try Initialize System type: %s", mainID.name());

	if (IsHasSystemInstance(mainID)) {
		cw("already instance!");
		return true;
	}


	// load dependencies
	for (auto& dependencyID : sysData.dependencies) {
		auto& dependency = *TryGetSystemRegisterData(dependencyID);
		cw("try check dependency: %s", dependency.name());
		if (!TryCreateSystemInstanceRecursive(dependency)) {
			cw("error try to load dependency system!!");
			return false;
		}
	}


	// create instance!!
	cw("try create instance...");
	sysData.instance = sysData.createFn();
	cw("create type instance: %p", sysData.instance);
	cw("type name: %s", mainID.name());

	return true;
}


bool SystemManager::IsRegistered(std::type_index id)
{
	return m_registerSystems.find(id) != m_registerSystems.end();
}

bool SystemManager::IsHasSystemInstance(std::type_index id)
{
	return TryGetSystemInstance(id) != nullptr;
}

ISystem* SystemManager::TryGetSystemInstance(std::type_index id)
{
	auto data = TryGetSystemRegisterData(id);
	return data != nullptr ? data->instance : nullptr;
}

SystemManager::SystemRegisterData* SystemManager::TryGetSystemRegisterData(std::type_index id)
{
	auto it = m_registerSystems.find(id);
	return it != m_registerSystems.end() ? &it->second : nullptr;
}

bool SystemManager::InitializeAll()
{
	cw("try Create all instance...");
	for (auto& item : m_registerSystems) {
		auto& sys = item.second;
		if (!TryCreateSystemInstanceRecursive(sys)) {
			return false;
		}
	}

	cw("try Init all instance...");
	for (auto& sysDataPair : m_registerSystems) {
		auto& typeID = sysDataPair.first;
		auto& data = sysDataPair.second;
		cw("try Init() instance type: %s", typeID.name());
		if (!data.instance->Init()) {
			cw("failed to Init() instance type: %s", typeID.name());
		}
	}

	return true;
}
