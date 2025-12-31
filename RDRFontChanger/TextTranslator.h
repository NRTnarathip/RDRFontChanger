#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include "TextTranslateFile.h"
#include "ISystem.h"

class TextTranslator : public ISystem
{
public:
	bool Init() override;

	static void AddTranslateString(std::string english, std::string newText);
	static const char* TryTranslate(std::string english);


private:
	//	key: english normalize, value: new string
	static std::unordered_map<std::string, std::string> g_translateStringMap;
	static std::vector<TextTranslateCsvFile*> g_translateFiles;
};

