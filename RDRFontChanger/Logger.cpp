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
#include <mutex>

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
	m_logStream.open(m_logFileName, std::ios::out | std::ios::trunc);
	ShowConsole();
}

void Logger::ShowConsole()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	freopen("CONIN$", "r", stdin);
}

std::mutex g_mutex;
void Logger::LogFormat(const char* format, ...)
{
	std::lock_guard<std::mutex> lock(g_mutex);

	va_list args, args2;
	va_start(args, format);
	va_copy(args2, args);

	int size = vsnprintf(nullptr, 0, format, args) + 1;
	va_end(args);

	std::vector<char> buffer(size);
	vsnprintf(buffer.data(), size, format, args2);
	va_end(args2);

	auto now = std::chrono::system_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	auto in_time = std::chrono::system_clock::to_time_t(now);

	struct tm buf;
	localtime_s(&buf, &in_time);

	std::stringstream sstream;

	// [HH:MM:SS.ms]
	sstream << "[" << std::put_time(&buf, "%H:%M:%S")
		<< "." << std::setfill('0') << std::setw(3) << ms.count() << "]";

	DWORD tid = GetCurrentThreadId();
	sstream << "[TID:" << std::setw(5) << tid << "] ";

	sstream << buffer.data() << std::endl;

	std::string finalLog = sstream.str();

	std::cout << finalLog;

	if (m_logStream.is_open()) {
		m_logStream << finalLog;
		m_logStream.flush();
	}
}

void Logger::AddTab()
{
	tabString += ">>> ";
}

void Logger::UnTab()
{
	tabString.erase(tabString.size() - 4);
}
