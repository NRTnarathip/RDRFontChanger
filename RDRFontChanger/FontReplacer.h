#pragma once
#include "ISystem.h"
#include "SWFTypes.h"
#include "CustomFont.h"
#include <unordered_set>

class FontReplacer : public ISystem
{
public:
	FontReplacer() {
		g_instance = this;
	}

	bool Init() override;
	CustomFont* Register();
	CustomFont* TryReplaceToThaiFont(swfFont* font);

	static FontReplacer* Instance() { return g_instance; };
private:
	static FontReplacer* g_instance;
};

