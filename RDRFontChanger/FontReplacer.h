#pragma once
#include "ISystem.h"
#include "SWFTypes.h"

class FontReplacer : public ISystem
{
public:
	FontReplacer() {
		g_instance = this;
	}

	bool Init() override;
	void TryReplaceMainFontToThai(swfFont* font);

	static FontReplacer* Instance() { return g_instance; };
private:
	static FontReplacer* g_instance;
};

