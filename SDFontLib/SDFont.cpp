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
	//begin pare glyphs!
	while (std::getline(file, line)) {
		if (line == "GLYPHS") {
			TryParseGlyphs(file);
			break;
		}
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
		float w, h, bx, by, adv, vbx, vby, vadv, tx, ty, tw, th;
		char name[60];
		int id;
		sscanf(line.c_str(),
			"%x %s %f %f %f %f %f %f %f %f %f %f %f %f",
			&id, name,
			&w, &h,
			&bx, &by,
			&adv,
			&vbx, &vby,
			&vadv,
			&tx, &ty,
			&tw, &th);

		// setup glyph
		auto& g = glyphs[id] = Glyph{};
		g.id = id;
		g.name = name;
		g.width = w;
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

			// check if exist
			if (glyphs.contains(glyphID) == false)
				continue;

			// link ref glyph
			auto g = &glyphs[glyphID];
			charCodeToGlyphMap[charCode] = g;
		}
	}

}
