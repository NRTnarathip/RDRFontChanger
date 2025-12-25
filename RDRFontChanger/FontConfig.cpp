#include "FontConfig.h"
#include "Logger.h"
#include "INIReader.h"


FontConfig::FontConfig()
{
	cw("try load font config...");
	INIReader reader(configFilepath);
	if (reader.ParseError() < 0) {
		cw("load %s failed", configFilepath);
		return;
	}

	const char* SDFontSec = "sdfont";
	redemptionSDFontScale = reader.GetReal(
		SDFontSec, "redemption_scale", redemptionSDFontScale);
	narrowSDFontScale = reader.GetReal(
		SDFontSec, "narrow_scale", narrowSDFontScale);
	narrowOL1SDFontScale = reader.GetReal(
		SDFontSec, "narrow_ol1_scale", narrowOL1SDFontScale);

}
