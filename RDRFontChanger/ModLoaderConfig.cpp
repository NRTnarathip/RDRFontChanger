#include "ModLoaderConfig.h"
#include "ini.h"
#include "INIReader.h"

ModLoaderConfig::ModLoaderConfig()
{
	INIReader reader(configFilePath);
	if (reader.ParseError() < 0) {
		return;
	}


	// General{
	{
		const char* General = "General";
		enableConsole = reader.GetBoolean(General, "enableConsole", enableConsole);
	}


	// Logger
	{

		const char* Logger = "Logger";
		logConsole = reader.GetBoolean(Logger, "logConsole", logConsole) && enableConsole;
		logFile = reader.GetBoolean(Logger, "logFile", logFile);
		logRenderer = reader.GetBoolean(Logger, "logRenderer", logRenderer);
		logTimeStamp = reader.GetBoolean(Logger, "logTimestamp", logTimeStamp);
		logThreadID = reader.GetBoolean(Logger, "logThreadID", logThreadID);
	}

	{
		const char* Dev = "Dev";
		// debug zone
		devDebug = reader.GetBoolean(Dev, "devDebug", devDebug);
	}
}

