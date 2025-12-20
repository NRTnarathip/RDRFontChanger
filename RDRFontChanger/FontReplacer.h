#pragma once
#include <unordered_set>
#include "ISystem.h"
#include "SWFTypes.h"
#include "CustomFont.h"
#include "CustomSwfFontBitmap.h"

class FontReplacer : public ISystem
{
public:
	FontReplacer() {
		g_instance = this;
	}

	bool Init() override;
	void RegisterFontNarrowWithFontBitmap(std::string newFontName);
	CustomSwfFontAbstract* TryReplaceFontNarrow(swfFont* font);

	static FontReplacer* Instance() { return g_instance; };
private:
	static FontReplacer* g_instance;
};

