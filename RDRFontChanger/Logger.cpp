#include "Logger.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <cstdint>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdarg>
#include <sstream>

std::string tabString;
std::string Logger::GetTimeNowMsString() {
	std::stringstream ss;
	auto now = std::chrono::system_clock::now();
	auto time_t = std::chrono::system_clock::to_time_t(now);
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
		now.time_since_epoch()) % 1000;
	auto tm = *std::localtime(&time_t);
	std::string tmFormat = std::format("{:02d}:{:02d}:{:02d}:{:03d}",
		tm.tm_hour, tm.tm_min, tm.tm_sec, ms.count());
	ss << tmFormat.c_str();
	return ss.str();
}

Logger::Logger()
{
	// allow logger
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	freopen("CONIN$", "r", stdin);

	m_logStream.open(m_logFileName, std::ios::out | std::ios::trunc);
}

void Logger::LogFormat(const char* format, ...)
{
	char buffer[1024];
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	// build string
	std::stringstream sstream;
	auto now = std::chrono::system_clock::now();
	auto in_time = std::chrono::system_clock::to_time_t(now);
	sstream << "[" << std::put_time(std::localtime(&in_time), "%T") << "]";

	DWORD tid = GetCurrentThreadId();
	sstream << "[TID:" << tid << "] ";
	sstream << tabString;

	sstream << buffer << std::endl;

	// log it
	std::cout << sstream.str();

	m_logStream << sstream.str();
	m_logStream.flush();
}

void Logger::AddTab()
{
	tabString += ">>> ";
}

void Logger::UnTab()
{
	tabString.erase(tabString.size() - 4);
}

