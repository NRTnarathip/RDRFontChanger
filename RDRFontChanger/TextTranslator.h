#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "CustomFont.h"
#include "TextTranslateFile.h"

class TextTranslator
{
public:
	//	key: english, value: new string
	static std::unordered_map<std::string, std::string> g_translateStringMap;
	static std::vector<TextTranslateFile*> g_textTranslateFileList;
	static void AddTranslateString(std::string english, std::string newText);
	static void Initialize();
	static bool TryTranslate(std::string& inout);
	static std::string MakeTextKeyFromEnglish(std::string englishString);
};

