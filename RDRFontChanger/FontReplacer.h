#pragma once
#include <unordered_set>
#include "ISystem.h"
#include "SWFTypes.h"
#include "CustomFont.h"
#include "CustomFontSDF.h"

class FontReplacer : public ISystem
{
public:
	static std::vector<swfFont*> g_gameFonts;
	static constexpr auto k_SDFontFileExtName = ".sdfont";

	FontReplacer() {
		g_instance = this;
	}
	bool Init() override;

	void RegisterFontWithFontSDF(std::string gameFontName, std::string newFontPath);
	CustomSwfFontSDF* TryReplaceFont(swfFont* font);
	CustomSwfFontSDF* TryGetCustomFont(swfFont* font);
	void RegisterFontFromDir(std::string dir);

	static FontReplacer* Instance() { return g_instance; };
private:
	static FontReplacer* g_instance;
};

