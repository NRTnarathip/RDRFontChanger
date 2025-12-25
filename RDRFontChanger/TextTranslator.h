#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include "TextTranslateFile.h"
#include "ISystem.h"

class TextTranslator : public ISystem
{
public:
	//	key: english, value: new string
	static std::unordered_map<std::string, std::string> g_translateMap;
	static std::vector<TextTranslateCsvFile*> g_translateFiles;

	static void AddTranslateString(std::string english, std::string newText);
	static bool TryTranslate(std::string& inout);

	static std::string MakeTextKeyFromEnglish(std::string englishString);
	bool Init() override;
};

