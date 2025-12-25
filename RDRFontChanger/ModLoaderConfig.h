#pragma once
class ModLoaderConfig {
public:
	static ModLoaderConfig* Instance() {
		static ModLoaderConfig m_instance;
		return &m_instance;
	}

	/// <summary>
	/// General
	/// </summary>
	bool enableConsole = false;

	/// <summary>
	/// Logger
	/// </summary>
	bool logConsole = true;
	bool logFile = false;
	bool logRenderer = false;
	bool logTimeStamp = true;
	bool logThreadID = true;

	/// <summary>
	/// dev debug
	/// </summary>
	bool devDebug = false;

private:
	ModLoaderConfig();
	const char* configFilePath = "mod_loader_config.ini";
};

