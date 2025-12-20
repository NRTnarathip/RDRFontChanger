#pragma once
#include <iostream>
#include "grcImage.h"
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "DirectXTex.h"
#include "ISystem.h"
#include <filesystem>

class TextureReplacer : public ISystem {
public:
	static const char* k_modsReplaceTeturesDir;
	TextureReplacer();
	bool Init() override;
	void OnBeforeCreateFromBackingStore(grcTextureD11* tex);
	void RegisterReplaceTexture(std::string textureName, std::string path);
	static TextureReplacer* Instance() { return g_instance; }

private:
	std::unordered_map<std::string, std::string> m_registerReplaceTextureMap;
	std::unordered_map<std::string, DirectX::ScratchImage> m_scratchImageMap;
	void LoadDefaultTextureFiles();
	void SetupHooks();
	static TextureReplacer* g_instance;
};
