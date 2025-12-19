#include "TextTranslator.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "StringLib.h"
#include "Logger.h"



namespace fs = std::filesystem;

const char* localizeDir = "mods/localize";
std::unordered_map<std::string, std::string> g_translateStringMap;

std::string GetEnglishStringKey(std::string englishString) {
	auto key = ToLower(englishString);
	return key;
}

void LoadStringFromFile(std::string loadfilename,
	std::unordered_map<int, std::string>& stringMap) {
	cw("try to load string from file: %s", loadfilename.c_str());

	auto filePath = std::format("{}/{}", localizeDir, loadfilename);
	std::ifstream originalFileStream(filePath);
	if (!originalFileStream.is_open()) {
		cw("error file can't open!");
		return;
	}

	std::string line;
	while (std::getline(originalFileStream, line)) {
		if (line.empty())
			continue;

		size_t start = line.find('[');
		size_t end = line.find(']');
		int index = 0;
		if (start != std::string::npos && end != std::string::npos && end > start) {
			index = std::stoi(line.substr(start + 1, end - start - 1));
		}

		size_t dash = line.find(" - ");
		std::string string;
		if (dash != std::string::npos) {
			string = line.substr(dash + 3);
		}

		stringMap[index] = string;
	}

	originalFileStream.close();
}


void TextTranslator::Initialize() {
	static bool isInitialize;
	if (isInitialize) return;
	isInitialize = true;


	std::unordered_set<std::string> foundFiles;
	cw("InitializeTranslatator");
	if (fs::exists(localizeDir) && fs::is_directory(localizeDir)) {
		for (const auto& entry : fs::directory_iterator(localizeDir)) {
			auto path = entry.path();
			auto filename = path.filename();
			if (fs::is_regular_file(entry) && path.extension() == ".txt") {
				foundFiles.insert(filename.string());
			}
		}
	}

	// key: filename such as interface_win32.txt
	static std::unordered_map<std::string,
		std::unordered_map<int, std::string>> cache_fileStringMap;

	// search translate text file with @
	for (auto currentFilename : foundFiles) {
		cw("localize file: %s", currentFilename.c_str());
		size_t atPos = currentFilename.find('@');
		if (atPos == std::string::npos)
			continue;

		auto originalFilename = currentFilename.substr(0, atPos) + ".txt";
		cw("en file: %s", originalFilename.c_str());
		if (foundFiles.contains(originalFilename) == false)
			continue;


		// ready!!
		cw("registered translate file: %s", currentFilename.c_str());

		std::unordered_map<int, std::string> originalStringMap;
		// get it from cache
		if (cache_fileStringMap.contains(originalFilename)) {
			originalStringMap = cache_fileStringMap[originalFilename];
		}
		// load new
		else {
			LoadStringFromFile(originalFilename, originalStringMap);
			cache_fileStringMap[originalFilename] = originalStringMap;
		}

		// load 
		std::unordered_map<int, std::string> translateStringMap;
		LoadStringFromFile(currentFilename, translateStringMap);

		for (auto [index, newString] : translateStringMap) {
			// try to find text original en
			// cw("try replace new string: %s", newString.c_str());
			if (originalStringMap.contains(index) == false)
				continue;

			auto englishString = originalStringMap[index];
			// it same string!
			if (englishString == newString)
				continue;

			auto key = GetEnglishStringKey(englishString);
			g_translateStringMap[key] = newString;
			cw("mapped key: %s, new string: %s",
				englishString.c_str(), newString.c_str());
		}
	}

	// try to load string table
}


bool TextTranslator::TryTranslate(std::string& inout, CustomFont* font)
{

	if (font == nullptr) {
		cw("can't translate, cause font is null!");
		return false;
	}

	if (g_translateStringMap.empty())
		return false;

	auto stringKey = GetEnglishStringKey(inout);
	cw("try translate string key: %s", stringKey.c_str());
	if (g_translateStringMap.contains(stringKey)) {
		inout = g_translateStringMap[stringKey];
		cw("new string: %s", inout.c_str());
		return true;
	}
	else {
		cw("not found key!");
	}

	return false;
}
