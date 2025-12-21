#include "SDFont.h"
#include "Logger.h"

SDFont::SDFont(fs::path path) {
	this->path = path;

	cw("try load font path: {}", path.string());
	std::ifstream file(path);
	if (!file.is_open()) {
		cw("failed file not open!");
		return;
	}

	std::string line;
	//begin pare unit SPREAD  TEXTURE || FONT METRICS!
	while (std::getline(file, line)) {
		if (line == "SPREAD IN TEXTURE") {
			// SPREAD TEXTURE
			std::getline(file, line);
			sscanf(line.c_str(), "%f", &this->spreadTexture);
			// SPREAD FONT METRICS!
			std::getline(file, line);
			std::getline(file, line);
			sscanf(line.c_str(), "%f", &this->spreadFontMetric);
			break;
		}
	}

	cw("font spreadTexture: {}", this->spreadTexture);
	cw("font spreadFontMetric: {}", this->spreadFontMetric);

	//begin pare glyphs!
	while (std::getline(file, line)) {
		TryParseGlyphs(file);
	}

	cw("loaded font! total glyphs: {}, total chars: {}",
		TotalGlyph(), TotalChar());
}

void SDFont::TryParseGlyphs(std::ifstream& file) {
	std::string line;
	while (std::getline(file, line)) {
		// stop
		if (line.contains("#Kernings"))
			break;

		// parse line
		char name[60];
		SDFGlyph g;
		sscanf(line.c_str(),
			"%x %s %f %f %f %f %f %f %f %f %f %f %f %f",
			&g.pointID, name,
			&g.width, &g.height,
			&g.horizontalBearingX, &g.horizontalBearingY,
			&g.advanceX,
			&g.vbx, &g.vby,
			&g.vadv,
			&g.tx, &g.ty,
			&g.tw, &g.th);
		g.name = name;
		glyphs.emplace(g.pointID, std::move(g));
	}

	// skip into #FT_ENCODING_UNICODE
	while (std::getline(file, line)) {
		if (line.contains("FT_ENCODING_UNICODE"))
			break;
	}

	// parse #FT_ENCODING_UNICODE first line!
	std::vector<std::string> split;
	int totalGlyph = 0;
	{

		std::stringstream lineStream(line);
		std::string tempString;
		while (lineStream >> tempString)
			split.push_back(tempString);

	}

	for (int i = 0; i < split.size();i++) {
		std::string str = split[i];
		if (totalGlyph == 0 && str.contains("0X")) {
			var numCharsString = split[i - 1];
			sscanf(numCharsString.c_str(), "%d", &totalGlyph);
		}

		// current it's 0X00000020	0X00000003
		if (totalGlyph > 0) {
			int charCode = 0;
			int glyphID = 0;
			var str2 = split[i + 1];
			i++;

			// parse
			sscanf(str.c_str(), "%x", &charCode);
			sscanf(str2.c_str(), "%x", &glyphID);

			// check if not exist
			if (glyphs.contains(glyphID) == false)
				continue;

			// link ref glyph
			auto g = &glyphs[glyphID];
			charCodeToGlyphMap[charCode] = g;
		}
	}

}
