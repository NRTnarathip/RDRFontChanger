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
	void LogFormat(const char* format, ...);

	// static utils
	static std::string GetTimeNowMsString();

private:
	Logger();
	std::ofstream m_logStream;
	const char* m_logFileName = "RDRFontChanger.log";
};

#define cw Logger::Instance()->LogFormat
#define logFormat Logger::Instance()->LogFormat
