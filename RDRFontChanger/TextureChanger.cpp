#include "TextureChanger.h"
#include "HookLib.h"
#include "grcImage.h"
#include <filesystem>
#include <string>
#include <vector>
#include <string>
#include "StringLib.h"

namespace fs = std::filesystem;

using namespace HookLib;

TextureReplacer* g_instance = nullptr;
const char* TextureReplacer::k_modsReplaceTeturesDir = "mods/replace_textures"; // default

void* (*fn_grcTextureD11_CreateFromBackingStore)(grcTextureD11* self);
void* HK_grcTextureD11_CreateFromBackingStore(grcTextureD11* self) {
	cw("BeginHook HK_grcTextureD11_CreateFromBackingStore, self: %p", self);

	self->BeforeCreateFromBackingStore();
	// replace here

	g_instance->OnBeforeCreateFromBackingStore(self);

	auto r = fn_grcTextureD11_CreateFromBackingStore(self);
	self->AfterCreateFromBackingStore();

	cw("EndHook HK_grcTextureD11_CreateFromBackingStore");
	return r;
}

TextureReplacer* TextureReplacer::InitOnMain()
{
	cw("TextureChagner setup...");
	if (g_instance) {
		cw("already instance!");
		return g_instance;
	}

	g_instance = new TextureReplacer();
}

TextureReplacer::TextureReplacer()
{
	HookRva(0x1543c0, HK_grcTextureD11_CreateFromBackingStore,
		&fn_grcTextureD11_CreateFromBackingStore);

	LoadMods();
}


void TextureReplacer::OnBeforeCreateFromBackingStore(grcTextureD11* tex)
{
	auto texName = tex->GetName();
	if (m_replaceTextureNames.contains(texName) == false) {
		return;
	}

	cw("try replace texture: %s", texName.c_str());
	auto filePathString = std::format("{}/{}", k_modsReplaceTeturesDir, texName);
	cw("try to read file: %s", filePathString.c_str());

	DirectX::ScratchImage img;
	auto filePathSystem = fs::path(filePathString);
	auto wFilePath = filePathSystem.wstring();
	HRESULT hr = DirectX::LoadFromDDSFile(
		wFilePath.data(),
		DirectX::DDS_FLAGS::DDS_FLAGS_NONE,
		nullptr, img);

	if (FAILED(hr)) {
		cw("error to LoadFromDDSFile");
		return;
	}

	// change it
	auto image = img.GetImage(0, 0, 0);
	auto oldRawImage = tex->rawImage;
	auto newRawImage = img.GetPixels();
	tex->rawImage = newRawImage;
	cw("set rawImage!! old: %p, new: %p!!", oldRawImage, newRawImage);

	// add to cache
	m_scratchImageMap.emplace(texName, std::move(img));
}

std::unordered_set<std::string> GetTextureNamesInModsFolder() {
	std::unordered_set<std::string> manifestPaths;

	auto rootDir = TextureReplacer::k_modsReplaceTeturesDir;
	if (fs::exists(rootDir) && fs::is_directory(rootDir)) {
		for (const auto& entry : fs::recursive_directory_iterator(rootDir)) {
			auto path = entry.path();
			auto filename = path.filename();
			if (fs::is_regular_file(entry) && path.extension() == ".dds") {
				// key hash lower case
				fs::path relative = fs::relative(path, rootDir);
				relative = relative.generic_string(); // normalize path format
				auto textureNameKey = ToLower(relative.string());
				cw("found texture name key: %s", textureNameKey.c_str());
				manifestPaths.insert(textureNameKey);
			}
		}
	}

	return manifestPaths;
}

void TextureReplacer::LoadMods()
{
	cw("try loading mods texture changer...");
	const char* modsDir = "mods";
	m_replaceTextureNames = GetTextureNamesInModsFolder();
	cw("found replace texture name count: %d", m_replaceTextureNames.size());
	for (const std::string& name : m_replaceTextureNames) {
		cw("texture name: %s", name.c_str());
	}
}
