#include "TextTranslateFile.h"
#include "Logger.h"
#include "StringLib.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <filesystem>
#include "rapidcsv.h"
#include "StringLib.h"

namespace fs = std::filesystem;

TextTranslateCsvFile::TextTranslateCsvFile(std::string path)
{
	this->m_csvPath = fs::path(path).generic_string();
}


bool TextTranslateCsvFile::TryLoad()
{
	try {
		rapidcsv::Document doc(m_csvPath);

		std::vector<std::string> keys = doc.GetColumn<std::string>("row_key");
		std::vector<std::string> engs = doc.GetColumn<std::string>("english");
		std::vector<std::string> translates = doc.GetColumn<std::string>("translate");

		for (size_t i = 0; i < keys.size(); ++i) {
			auto rowKey = keys[i];
			auto eng = engs[i];
			auto translate = translates[i];
			if (translate.length() <= 1)
				continue;

			m_translateMap[eng] = translate;
			// pn("loaded line: {} - {}", rowKey, translate);
		}
	}
	catch (const std::exception& e) {
		cw("error: %s", e.what());
	}


	return true;
}
