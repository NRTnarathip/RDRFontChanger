#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <typeindex>
#include "ISystem.h"
#include <iostream>
#include <algorithm>

class SystemManager {
public:
	SystemManager() {
		g_instance = this;
	}

	struct SystemRegisterData {
		using CreateFn = ISystem * (*)();

		explicit SystemRegisterData(std::type_index tid)
			: id(tid),
			instance(nullptr),
			createFn(nullptr)
		{
		}
		std::type_index id;
		ISystem* instance;
		CreateFn createFn;
		std::vector<std::type_index> dependencies;
		const char* name() const {
			return id.name();
		}
	};
	void OnAppInit();

	template<typename MainType, typename... DependencyTypes>
	void Register() {
		std::type_index id(typeid(MainType));

		// alrady register this type
		if (IsRegistered(id))
			return;

		// register it!
		auto [it, inserted] = m_registerSystems.emplace(
			id,
			SystemRegisterData(id)
		);
		auto& sysData = it->second;
		sysData.createFn = []() -> ISystem* {
			return new MainType();
			};
		(sysData.dependencies.emplace_back(typeid(DependencyTypes)), ...);

		// events
		OnRegisteredType(it->second);
	}
	bool IsRegistered(std::type_index id);
	bool IsHasSystemInstance(std::type_index id);
	ISystem* TryGetSystemInstance(std::type_index id);
	SystemRegisterData* TryGetSystemRegisterData(std::type_index id);
	bool InitializeAll();


	template< typename T>
	T* TryGetSystemInstance() {
		return (T*)TryGetSystemInstance(std::type_index(typeid(T)));
	}
	static SystemManager* Instance() { return g_instance; }
private:
	static SystemManager* g_instance;
	std::unordered_map<std::type_index, SystemRegisterData> m_registerSystems;
	void OnRegisteredType(SystemRegisterData& data);
	bool TryInitSystemRecursive(SystemRegisterData& sysData);
};


