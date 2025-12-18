#pragma once
#include <iostream>
#include "grcImage.h"
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "DirectXTex.h"

class TextureReplacer
{
public:
	static const char* k_modsReplaceTeturesDir;

	static TextureReplacer* InitOnMain();
	TextureReplacer();
	void OnBeforeCreateFromBackingStore(grcTextureD11* tex);
private:
	std::unordered_set<std::string> m_replaceTextureNames;
	std::unordered_map<std::string, DirectX::ScratchImage> m_scratchImageMap;
	void LoadMods();
};
