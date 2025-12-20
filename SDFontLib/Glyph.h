#pragma once

#include <iostream>

struct Glyph {
	int id; // not char code!!
	std::string name;
	int width, height;
	float advanceX;
	float bearingX, bearingY;
	// vertical bearing x, y, advance
	float vbx, vby, vba;
	// texture U, V, width, height
	float tx, ty, tw, th;
};

