#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


struct StringMap {
	// index : string
	std::unordered_map<int, std::string> map;
	bool contains(int index) {
		return map.contains(index);
	}
	std::string get(int index, bool& found) {
		if (map.contains(index))
			return map[index];
		return {};
	}
	std::string get(int index) {
		bool found;
		return get(index, found);
	}

	void add(int index, std::string s) {
		map[index] = s;
	}
};

class TextTranslateFile
{
public:
	StringMap srcStringMap;
	StringMap translateStingMap;

	TextTranslateFile(std::string srcPath, std::string translatePath);
	bool TryLoad();
	std::string TryGetSrcString(int i);

	static bool TryParseLine(std::string line, int& indexOut, std::string& text);
	static void LoadStringFromFile(std::string filepath,
		std::unordered_map<int, std::string>& stringMap);

private:
	std::string m_srcPath;
	std::string m_translatePath;
};
