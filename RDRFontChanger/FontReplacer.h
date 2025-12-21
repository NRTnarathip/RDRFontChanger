#pragma once
#include <unordered_set>
#include "ISystem.h"
#include "SWFTypes.h"
#include "CustomFont.h"
#include "CustomSwfFontBitmap.h"
#include "CustomFontSDF.h"

class FontReplacer : public ISystem
{
public:
	static std::vector<swfFont*> g_gameFonts;
	FontReplacer() {
		g_instance = this;
	}

	bool Init() override;
	void RegisterFontNarrowWithFontBitmap(std::string fontPath);
	void RegisterFontNarrowWithFontSDF(
		std::string regularPath, std::string boldPath);
	CustomSwfFontBitmap* TryReplaceFontNarrowWithBitmap(swfFont* font);
	CustomSwfFontSDF* TryReplaceFontNarrowWithSDF(swfFont* font);

	static FontReplacer* Instance() { return g_instance; };
private:
	CustomSwfFontSDF* TryReplaceFontNarrowWithSDFInternal(swfFont* font);
	static FontReplacer* g_instance;
};

