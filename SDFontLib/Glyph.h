#pragma once

#include <iostream>
struct SDFGlyph {
	int pointID; // not char code!!
	std::string name;
	float width, height;
	float advanceX;
	// horizontal bearing x, y
	float horizontalBearingX, horizontalBearingY;
	// vertical bearing x, y, 
	float vbx, vby, vadv;
	// texture U, V, width, height
	float tx, ty, tw, th;
};

