#include "TextTranslator.h"
#include "StringLib.h"
#include "Logger.h"

std::unordered_map<std::string, std::string> thaiStrings = {
	{"settings", "ตั้งค่า"},
	{"play", "เล่น"},
	{"quit", "ออก"},
};

bool TextTranslator::TryTranslate(std::string& inout, CustomFont* font)
{
	if (font == nullptr) {
		cw("can't translate, cause font is null!");
		return false;
	}

	auto textKey = ToLower(inout);
	cw("try translate text key: %s", textKey.c_str());
	if (thaiStrings.contains(textKey)) {
		inout = thaiStrings[textKey];
		cw("new text: %s", inout.c_str());
		return true;
	}
	else {
		cw("not found key!");
	}

	return false;
}
