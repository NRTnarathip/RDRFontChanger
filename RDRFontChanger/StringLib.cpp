#include "StringLib.h"
#include <Windows.h>
#include <algorithm>
#include <string>

std::string WCharToString(const wchar_t* wstr) {
	if (!wstr)
		return {};

	int len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
	std::string result(len - 1, '\0');
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, result.data(), len, nullptr, nullptr);
	return result;
}

std::wstring ToWString(const std::string& str) {
	if (str.empty())
		return std::wstring();
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);

	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);

	return wstrTo;
}

std::string ToLower(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return s;
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

