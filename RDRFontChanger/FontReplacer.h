#pragma once
#include <unordered_set>
#include "ISystem.h"
#include "SWFTypes.h"
#include "CustomFontSDF.h"

class FontReplacer : public ISystem
{
public:
	static constexpr auto k_SDFontFileExtName = ".sdfont";

	FontReplacer() {
		g_instance = this;
	}
	bool Init() override;

	void RegisterFontWithFontSDF(std::string gameFontName, std::string newFontPath);
	CustomFontSDF* TryLoadCustomFont(swfFont* font);
	CustomFontSDF* TryGetCustomFont(swfFont* font);
	void RegisterFontFromDir(std::string dir);
	void TryLoadCustomFonts();

	static FontReplacer* Instance() { return g_instance; };
private:
	static FontReplacer* g_instance;
};

