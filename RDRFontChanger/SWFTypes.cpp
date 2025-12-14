#include "SWFTypes.h"
#include "Logger.h"
#include <vector>
#include <string.h>

#include "XMem.h"
using namespace XMem;

void DumpSWFText(void* o)
{
	SWFText* t = (SWFText*)o;
	// cw("t");
}
const char* GetSWFTypeName(int e) {
	static std::vector<std::string> names{
		"Shape", // 1
		"Sprite",
		"Button",
		"Bitmap",
		"Font",
		"Text",
		"EditText",
		"", // 8 unuse
		"MorphShape", // 9
	};
	if (e <= 0 || e >= 10)
		return "";
	return names.at(e - 1).c_str();
}

FlashManager* GetFlashManager()
{
	FlashManager* flashMgr = (FlashManager*)GetAddressFromRva(0x2c45610);
	return flashMgr;
}
SWFTypeEnum GetSWFFileType(void* o) {
	return (SWFTypeEnum)(*((char*)o + 0x10));
}

int GetSWFTotalFiles(swfFile* file) {
	return *(std::uint16_t*)((std::uintptr_t)(file)+0x4E);
}

void* FindFont(swfFile* mainFile, const char* findFontName)
{
	cw("Try FindFont...");
	auto totalFiles = GetSWFTotalFiles(mainFile);
	cw("total file %d", totalFiles);
	cw("main files: %p", mainFile->files);

	if (totalFiles == 0 || mainFile->files == nullptr)
		return nullptr;

	for (int index = 0; index < totalFiles;index++)
	{
		swfFile* file = *(swfFile**)((long)mainFile->files + index * 8);
		cw("index: %d", index);
		cw("file: %p", file);
		cw("file name: %s, findName: %s", file->name, findFontName);
		if ((file != nullptr) && (GetSWFFileType(file) == SWFTypeEnum::Font)) {
			auto resultStrcmp = _stricmp(file->name, findFontName);
			cw("match!!");
			if (resultStrcmp == 0)
				return file;
		}
	}
	cw("not found any font: %s", findFontName);
	return nullptr;
}
fuiMovie* TryGetMovieFromID(FlashManager* mgr, uint8_t id)
{
	if (id == 0xFF)
		return nullptr;

	int index = static_cast<int8_t>(id);
	if (index >= mgr->movieCount)
		return nullptr;

	fuiMovie** array = (fuiMovie**)&mgr->movieArray;
	return array[index];
}

typedef void* (*fnGetPackFileProps)(PackFileIndex_c* packFileIndex, PackFileProperty* propsOut, uint32_t hash);
void* GetPackFileProps(PackFileIndex_c* packFileIndex, PackFileProperty* propsOut, uint32_t hash) {
	static fnGetPackFileProps fnPtr = 0;
	if (fnPtr == nullptr)
		fnPtr = (fnGetPackFileProps)GetAddressFromRva(0xeb6930);
	return fnPtr(packFileIndex, propsOut, hash);
}

PackFilePropertyKeyPair* PackFileEntryHashMap::Find(uint32_t findKey)
{
	// simple logic, 
	// !pool optimize
	PackFileEntryHashMap* map = this;
	for (size_t i = 0; i < map->count; ++i) {
		auto entry = &map->data[i];
		if (entry->key == findKey)
			return entry;
	}

	return nullptr;
}

void DumpPackFile(PackFile_c* p)
{
	cw("try dump pack file= %p", p);
	auto fileIndex = p->fileIndex;
	cw("file index: %p", fileIndex);
	cw("pack file name: %s", fileIndex->packFileName);
	cw("total files: %d", fileIndex->totalFiles);
	cw("files capacity: %d", fileIndex->fileHashCapacity);
	auto map = &fileIndex->hashMap;
	for (int i = 0;i < fileIndex->totalFiles;i++) {
		cw("index: %d", i);
		auto currentHash = fileIndex->fileHashVector[i];
		cw("current hash: 0x%x", currentHash);
		PackFileProperty packFileProps;
		auto result = GetPackFileProps(fileIndex, &packFileProps, currentHash);
		cw("v0: 0x%x", packFileProps.v0);
		cw("v1: 0x%x", packFileProps.v1);
		cw("v2: 0x%x", packFileProps.v2);
	}
}

uint32_t Hash(const void* data, size_t len, uint32_t seed = FNV_OFFSET_BASIS_32)
{
	const uint8_t* p = (const uint8_t*)data;
	uint32_t hash = seed;
	for (size_t i = 0; i < len; ++i)
		hash = (hash * 16777619u) ^ p[i];
	return hash;
}
