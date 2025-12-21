#include "BitmapFont.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include "Logger.h"
#include "Rage.h"

namespace fs = std::filesystem;

std::unordered_map<std::string, BitmapFont*> g_fontCache;

void BitmapFont::ParseGlyph(const std::string& line, BitmapFont::Glyph& g) {
	auto lineCstr = line.c_str();
	sscanf(lineCstr, "char id=%d x=%d y=%d width=%d height=%d xoffset=%d yoffset=%d xadvance=%d page=%d chnl=%d",
		&g.charCode, &g.x, &g.y, &g.width, &g.height,
		&g.xoffset, &g.yoffset, &g.xadvance, &g.page, &g.chnl);
}

BitmapFont* BitmapFont::TryLoad(std::string path)
{
	auto safepath = SafePath(path);
	if (g_fontCache.contains(safepath))
		return g_fontCache[safepath];

	auto font = g_fontCache[safepath] = new BitmapFont(safepath);
	return font;
}

BitmapFont::BitmapFont(std::string path)
{
	std::ifstream file(path);
	if (file.is_open() == false) {
		cw("failed can't open bitmap font path: %s", path.c_str());
		return;
	}

	std::string line;

	while (std::getline(file, line)) {
		auto lineCstr = line.c_str();
		// parse line
		if (line.find("char id=") == 0) {
			auto& glyph = this->glyphs.emplace_back(Glyph{});
			ParseGlyph(line, glyph);
			charIDToGlyph[glyph.charCode] = &glyph;
		}
		else if (line.find("common") == 0) {
			sscanf(lineCstr, "common lineHeight=%d base=%d scaleW=%d scaleH=%d",
				&lineHeight, &baseline, &scaleW, &scaleH);
		}
		else if (line.find("info") == 0) {
			sscanf(lineCstr, "info face=\"%[^\"]\" size=%d bold=%d italic=%d",
				face, &size, &bold, &italic);
			fontName = face;
		}
	}
	cw("loaded bitmap font name: %s, size: %d", fontName, size);
}

