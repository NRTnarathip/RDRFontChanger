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
	va_list args;
	va_start(args, format);

	int size = vsnprintf(nullptr, 0, format, args) + 1;
	va_end(args);

	std::vector<char> buffer(size);
	va_start(args, format);
	vsnprintf(buffer.data(), size, format, args);
	va_end(args);

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

	std::lock_guard<std::mutex> lock(g_mutex);

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

const char* stringNull = "(null)";
const char* TryGetStringInternal(void* ptr) {
	if (ptr == nullptr)
		return stringNull;

	uintptr_t addr = (uintptr_t)ptr;
	if (addr < 0x10000)
		return stringNull;

	if (addr > 0x00007FFFFFFFFFFFULL)
		return stringNull;


	__try {
		const char* str = reinterpret_cast<const char*>(ptr);
		if (str[0] == '\0')
			return "";

		return str;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return "(null exception pointer)";
	}

	return stringNull;
}

std::string TryGetString(void* ptr) {
	return TryGetStringInternal(ptr);
}
