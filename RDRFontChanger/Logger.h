#pragma once

#include <fstream>
#include <iostream>

class Logger
{
public:
	static Logger* Instance()
	{
		static Logger instance;
		return &instance;
	}
	void ShowConsole();
	void LogFormat(const char* format, ...);
	void AddTab();
	void UnTab();

	// static utils
	static std::string GetTimeNowMsString();

private:
	Logger();
	std::ofstream m_logStream;
	const char* m_logFileName = "RDRFontChanger.log";
};

#define cw Logger::Instance()->LogFormat
#define logFormat Logger::Instance()->LogFormat
#define addTab Logger::Instance()->AddTab
#define unTab Logger::Instance()->UnTab


std::string TryGetString(void* ptr);
