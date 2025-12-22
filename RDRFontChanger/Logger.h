#pragma once

#include <fstream>
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <cstdint>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdarg>
#include <mutex>
#include <algorithm>
#include <format>


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

	template<typename... Args>
	void Print(const std::string& fmt, Args&&... args) {
		std::lock_guard<std::mutex> lock(m_mutex);
		std::string msg = std::vformat(fmt, std::make_format_args(args...));
		std::string time = TimeNow();
		DWORD tid = GetCurrentThreadId();
		auto final = std::format("{}[TID:{}] {}\n", time, tid, msg);
		std::cout << final;
		LogToFile(final);
	}

private:
	Logger();
	std::mutex m_mutex;
	std::ofstream m_logStream;
	const char* m_logFileName = "RDRFontChanger.log";

	std::string TimeNow();

	void LogToFile(std::string line);
};

#define cw Logger::Instance()->LogFormat
#define logFormat Logger::Instance()->LogFormat
#define addTab Logger::Instance()->AddTab
#define unTab Logger::Instance()->UnTab
#define pn Logger::Instance()->Print


