#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <print>
#include <unordered_map>
#include "Glyph.h"

namespace fs = std::filesystem;

struct SDFont {
	fs::path path;
	float spreadTexture;
	float spreadFontMetric;
	std::unordered_map<int, SDFGlyph> glyphs;
	std::unordered_map<int, SDFGlyph*> charCodeToGlyphMap;
	SDFont(fs::path path);
	void TryParseGlyphs(std::ifstream& file);
	int TotalGlyph() {
		return glyphs.size();
	}
	int TotalChar() {
		return charCodeToGlyphMap.size();
	}
};


