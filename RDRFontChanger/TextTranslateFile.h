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

class TextTranslateCsvFile
{
public:
	TextTranslateCsvFile(std::string path);
	bool TryLoad();
	std::string TryGetSrcString(int i);

	std::unordered_map<std::string, std::string> GetTranslateMap() {
		return m_translateMap;
	}

private:
	std::string m_csvPath;
	// key  : english raw, un normalize
	// value: translate
	std::unordered_map<std::string, std::string> m_translateMap;

};
