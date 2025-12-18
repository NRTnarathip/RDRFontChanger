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

std::string ToLower(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return s;
}
