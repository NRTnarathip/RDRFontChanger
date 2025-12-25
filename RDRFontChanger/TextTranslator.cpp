#include "TextTranslator.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "StringLib.h"
#include "Logger.h"


namespace fs = std::filesystem;

const char* localizeDir = "mods/localize";

std::unordered_map<std::string, std::string> TextTranslator::g_translateMap;
std::vector<TextTranslateCsvFile*> TextTranslator::g_translateFiles;


void TextTranslator::AddTranslateString(std::string english, std::string newText)
{
	auto key = MakeTextKeyFromEnglish(english);
	if (key.empty())
		return;

	g_translateMap[key] = newText;
	// cw("added translate: %s = %s", key.c_str(), newText.c_str());
}

bool TextTranslator::Init() {
	cw("try initialize Translatator");

	// fetch all files
	std::unordered_set<std::string> csvFiles;
	if (fs::exists(localizeDir) && fs::is_directory(localizeDir)) {
		for (const auto& entry : fs::directory_iterator(localizeDir)) {
			auto path = entry.path();
			if (fs::is_regular_file(entry) && path.extension() == ".csv") {
				csvFiles.insert(path.generic_string());
			}
		}
	}

	// search translate text file with @
	for (auto csvPath : csvFiles) {
		cw("localize csv file: %s", csvPath.c_str());

		// ready!!
		auto translateFile = new TextTranslateCsvFile(csvPath);
		g_translateFiles.push_back(translateFile);
		if (translateFile->TryLoad() == false) {
			cw("failed to load translate file!");
			continue;
		}


		cw("loaded translate csv file: %s", csvPath.c_str());

		// build translate string map!
		auto translateMap = translateFile->GetTranslateMap();
		for (auto [eng, newString] : translateMap) {
			if (newString.size() > 1)
				AddTranslateString(eng, newString);
		}
	}

	return true;
}

std::string TextTranslator::MakeTextKeyFromEnglish(std::string englishString) {
	auto key = ToLower(englishString);
	key = StringTrim(key);
	// collapse multiple spaces -> single space
	{
		std::string keyRemoveDuplicateSpace;
		bool lastSpace = false;
		for (char c : key)
		{
			if (std::isspace((unsigned char)c))
			{
				if (!lastSpace)
				{
					keyRemoveDuplicateSpace.push_back(' ');
					lastSpace = true;
				}
			}
			else
			{
				keyRemoveDuplicateSpace.push_back(c);
				lastSpace = false;
			}
		}
		key = keyRemoveDuplicateSpace;
	}

	return key;
}

bool TextTranslator::TryTranslate(std::string& inout)
{
	if (g_translateMap.empty())
		return false;

	auto stringKey = MakeTextKeyFromEnglish(inout);
	cw("try translate string key: %s", stringKey.c_str());
	if (g_translateMap.contains(stringKey)) {
		inout = g_translateMap[stringKey];
		cw("translated string: %s", inout.c_str());
		return true;
	}

	return false;
}

