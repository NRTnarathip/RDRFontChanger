#pragma once
#include <iostream>

std::string WCharToString(const wchar_t* wstr);

std::wstring ToWString(const std::string& str);

std::string ToLower(std::string s);

std::string TryGetString(void* ptr);
