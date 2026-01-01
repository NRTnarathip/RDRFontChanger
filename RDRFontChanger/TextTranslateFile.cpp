#include "TextTranslateFile.h"
#include "Logger.h"
#include "StringLib.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <filesystem>
#include "rapidcsv.h"
#include "StringLib.h"
#include <regex>
#include <algorithm>
#include "uni_algo/norm.h"


namespace fs = std::filesystem;


TextTranslateCsvFile::TextTranslateCsvFile(std::string path)
{
	this->m_csvPath = fs::path(path).generic_string();
}

bool TextTranslateCsvFile::TryLoad()
{
	try {
		rapidcsv::Document doc(m_csvPath);

		std::vector<std::string> filenameList = doc.GetColumn<std::string>("filename");
		std::vector<std::string> englishList = doc.GetColumn<std::string>("english");
		std::vector<std::string> translateList = doc.GetColumn<std::string>("translate");


		for (size_t i = 0; i < englishList.size(); ++i) {
			auto translate = translateList[i];
			if (translate.length() <= 1)
				continue;

			// it's same text
			auto eng = englishList[i];
			if (eng == translate)
				continue;

			auto rowKey = MakeEnglishRowKey(eng);
			if (rowKey.length() <= 1)
				continue;

			m_translateMap[rowKey] = translate;
			//cw("loaded line: %s", rowKey.c_str());
			//cw("translate  : %s", translate.c_str());
		}
	}
	catch (const std::exception& e) {
		cw("error: %s", e.what());
	}


	return true;
}

std::string normalizeNFC(std::string input)
{
	return una::norm::to_nfc_utf8(input);
}

std::string NormalizeNBSP(std::string input) {
	// In UTF-8, a non-breaking space (U+00A0) is represented by C2 A0
	const std::string NBSP_UTF8 = "\xC2\xA0";
	const std::string SPACE_UTF8 = " ";

	std::string s = input;
	size_t pos = 0;
	while ((pos = s.find(NBSP_UTF8, pos)) != std::string::npos) {
		s.replace(pos, NBSP_UTF8.length(), SPACE_UTF8);
		pos += SPACE_UTF8.length(); // Move past the replaced character
	}
	return s;
}

std::string TextTranslateCsvFile::MakeEnglishRowKey(std::string key)
{
	key = NormalizeNBSP(key);

	key = StringTrim(key);

	// collapse multiple space -> single underscore
	bool lastSpace = false;
	std::string collapse;
	for (char c : key) {
		if (isspace((unsigned char)c)) {
			if (!lastSpace) collapse += '_';
			lastSpace = true;
		}
		else {
			collapse += c;
			lastSpace = false;
		}
	}
	key = collapse;

	// remove chars . " ? ! , and more...
	static std::unordered_set<char> g_charCodeToRemoveMap = {
		'.',
		',',
		'-',
		'\'',
		'\"',
		'?',
		'!'
	};
	key.erase(std::remove_if(key.begin(), key.end(),
		[](char c) {
			return g_charCodeToRemoveMap.contains(c);
		}), key.end());

	// to lower
	std::transform(key.begin(), key.end(), key.begin(), ::tolower);

	// normalize!
	key = normalizeNFC(key);


	return key;
}
