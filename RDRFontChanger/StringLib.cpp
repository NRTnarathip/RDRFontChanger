#include "StringLib.h"
#include <Windows.h>
#include <algorithm>
#include <string>
#include <filesystem>

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

const char* leftRightTrimCharset = " \t\n\r\f\v";
inline std::string LeftTrim(std::string& s, const char* t = leftRightTrimCharset) {
	s.erase(0, s.find_first_not_of(t));
	return s;
}

inline std::string RightTrim(std::string& s, const char* t = leftRightTrimCharset) {
	size_t pos = s.find_last_not_of(t);
	if (pos != std::string::npos) {
		s.erase(pos + 1);
	}
	else {
		// String was all whitespace
		s.clear();
	}
	return s;
}

std::string StringTrim(std::string s)
{
	s = LeftTrim(s);
	s = RightTrim(s);
	return s;
}

std::string StringRemove(std::string s, std::string remove) {
	size_t pos;
	while ((pos = s.find(remove)) != std::string::npos) {
		s.erase(pos, remove.length());
	}
	return s;
}

std::string StringFileNoExt(std::string path)
{
	return std::filesystem::path(path).stem().string();
}

