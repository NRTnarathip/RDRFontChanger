#include "TextTranslator.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "StringLib.h"
#include "Logger.h"


namespace fs = std::filesystem;

const char* localizeDir = "mods/localize";

std::unordered_map<std::string, std::string> TextTranslator::g_translateStringMap;
std::vector<TextTranslateFile*> TextTranslator::g_textTranslateFileList;


void TextTranslator::AddTranslateString(std::string english, std::string newText)
{
	auto key = MakeTextKeyFromEnglish(english);
	if (key.empty())
		return;

	g_translateStringMap[key] = newText;
	// cw("added translate: %s = %s", key.c_str(), newText.c_str());
}

void TextTranslator::Initialize() {
	static bool isInitialize;
	if (isInitialize) return;
	isInitialize = true;
	cw("InitializeTranslatator");


	// fetch all files
	std::unordered_set<std::string> foundFiles;
	auto gameDir = fs::current_path();

	if (fs::exists(localizeDir) && fs::is_directory(localizeDir)) {
		for (const auto& entry : fs::directory_iterator(localizeDir)) {
			auto path = entry.path();
			auto filename = path.filename();
			if (fs::is_regular_file(entry) && path.extension() == ".txt") {
				auto relativePath = fs::relative(path, gameDir);
				foundFiles.insert(relativePath.string());
			}
		}
	}

	// key: filename such as interface_win32.txt
	static std::unordered_map<std::string,
		std::unordered_map<int, std::string>> cache_fileStringMap;

	// search translate text file with @
	for (auto currentPath : foundFiles) {
		cw("localize file: %s", currentPath.c_str());
		// filter file by '@' for detect translate file!
		size_t atPos = currentPath.find('@');
		if (atPos == std::string::npos)
			continue;

		auto srcPath = currentPath.substr(0, atPos) + ".txt";
		cw("en file: %s", srcPath.c_str());
		if (foundFiles.contains(srcPath) == false)
			continue;


		// ready!!
		TextTranslateFile translateFile(srcPath, currentPath);
		if (translateFile.TryLoad() == false) {
			continue;
		}
		cw("loaded translate file: %s", currentPath.c_str());

		// build translate string map!
		for (auto& [index, newString] : translateFile.translateStingMap.map) {
			auto english = translateFile.srcStringMap.get(index);
			if (english.empty() == false)
				AddTranslateString(english, newString);
		}
	}
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
	if (g_translateStringMap.empty())
		return false;

	auto stringKey = MakeTextKeyFromEnglish(inout);
	cw("try translate string key: %s", stringKey.c_str());
	if (g_translateStringMap.contains(stringKey)) {
		inout = g_translateStringMap[stringKey];
		cw("translated string: %s", inout.c_str());
		return true;
	}

	return false;
}

