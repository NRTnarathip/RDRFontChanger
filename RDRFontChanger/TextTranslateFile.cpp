#include "TextTranslateFile.h"
#include "Logger.h"
#include "StringLib.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;


void TextTranslateFile::LoadStringFromFile(std::string filepath,
	std::unordered_map<int, std::string>& stringMap) {
	cw("try to load string from file: %s", filepath.c_str());

	std::ifstream stream(filepath);
	if (!stream.is_open()) {
		cw("error file can't open!");
		return;
	}

	std::string line;
	while (std::getline(stream, line)) {
		if (line.empty())
			continue;

		int index;
		std::string text;
		if (TryParseLine(line, index, text) == false) {
			continue;
		}
		stringMap[index] = text;
	}

	stream.close();
}

TextTranslateFile::TextTranslateFile(std::string srcPath, std::string translatePath)
{
	this->m_srcPath = srcPath;
	this->m_translatePath = translatePath;
}


bool TextTranslateFile::TryLoad()
{
	if (fs::exists(m_srcPath) == false
		|| fs::exists(m_translatePath) == false) {
		return false;
	}



	LoadStringFromFile(m_srcPath, srcStringMap.map);
	LoadStringFromFile(m_translatePath, translateStingMap.map);

	return true;
}

std::string TextTranslateFile::TryGetSrcString(int i)
{
	return srcStringMap.get(i);
}

bool TextTranslateFile::TryParseLine(std::string line, int& indexOut, std::string& text) {
	if (line.empty())
		return false;

	size_t start = line.find('[');
	size_t end = line.find(']');
	if (start != std::string::npos && end != std::string::npos && end > start) {
		indexOut = std::stoi(line.substr(start + 1, end - start - 1));
	}
	else {
		cw("error this line: %s", line.c_str());
		return false;
	}

	size_t dash = line.find("-");
	if (dash != std::string::npos) {
		text = line.substr(dash + 1);
		text = StringTrim(text);
		// cw("found parer text: %s", text.c_str());
		return true;
	}

	return false;
}
