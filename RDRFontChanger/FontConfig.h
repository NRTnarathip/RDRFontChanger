#pragma once
class FontConfig
{
public:
	static FontConfig* Instance() {
		static FontConfig instance;
		return &instance;
	}

	float redemptionSDFontScale = 1;
	float narrowSDFontScale = 1;
	float narrowOL1SDFontScale = 1;

private:
	FontConfig();
	const char* configFilepath = "mods/fonts/font.ini";
};

