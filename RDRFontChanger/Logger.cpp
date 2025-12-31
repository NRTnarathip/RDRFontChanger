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
#include "ModLoaderConfig.h"
#include "StringLib.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stacktrace>
#include <sstream>
#include <cstdint>

std::string tabString;

ModLoaderConfig* modLoaderConfig;

void Logger::LogStacktrace()
{
	std::stringstream ss;
	auto stack = std::stacktrace::current();
	ss << stack;
	auto stackString = ss.str();
	cw("Stack trace...");
	cw("%s", stackString.c_str());
}

Logger::Logger()
{
	modLoaderConfig = ModLoaderConfig::Instance();

	if (modLoaderConfig->logFile) {
		m_logStream.open(m_logFileName, std::ios::out | std::ios::trunc);
		m_logStream << "\xEF\xBB\xBF"; // utf8 boom
	}

	if (modLoaderConfig->enableConsole)
		ShowConsole();
}

std::string Logger::TimeNow() {
	auto now = std::chrono::system_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
		now.time_since_epoch()) % 1000;

	std::time_t t = std::chrono::system_clock::to_time_t(now);
	tm tmBuf;
	localtime_s(&tmBuf, &t);

	std::ostringstream ss;
	ss << "[" << std::put_time(&tmBuf, "%H:%M:%S")
		<< "." << std::setw(3) << std::setfill('0') << ms.count() << "]";
	return ss.str();
}

void Logger::LogToFileInternal(std::string line)
{
	if (modLoaderConfig->logFile)
		if (m_logStream.is_open()) {
			m_logStream << line;
			m_logStream.flush();
		}
}

void Logger::LogToConsoleInternal(std::string line)
{
	if (modLoaderConfig->logConsole) {
		std::cout << line;
	}
}

bool Logger::IsDisableAllLogTypes()
{
	if (modLoaderConfig->logConsole == false
		&& modLoaderConfig->logFile == false) {
		return true;
	}

	return false;
}

void Logger::ShowConsole()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	freopen("CONIN$", "r", stdin);
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// ให้ stdout เป็น wide
	std::wcout.imbue(std::locale(""));
}

void Logger::LogFormat(const char* format, ...)
{
	if (IsDisableAllLogTypes()) {
		return;
	}

	std::lock_guard<std::mutex> lock(m_mutex);

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
	sstream << std::format("[TID:{}] ", tid);

	sstream << buffer.data() << std::endl;

	std::string finalLog = sstream.str();

	LogToConsoleInternal(finalLog);
	LogToFileInternal(finalLog);
}


void Logger::LogFormat(const wchar_t* format, ...)
{
	if (IsDisableAllLogTypes())
		return;

	va_list args;
	va_start(args, format);

	int len = _vscwprintf(format, args);
	if (len <= 0) {
		va_end(args);
		return;
	}

	std::wstring buffer(len, L'\0');
	vswprintf(buffer.data(), len + 1, format, args);

	va_end(args);

	std::string utf8 = WCharToString(buffer.c_str());
	LogFormat(utf8.c_str());
}

void Logger::AddTab()
{
	tabString += ">>> ";
}

void Logger::UnTab()
{
	tabString.erase(tabString.size() - 4);
}
