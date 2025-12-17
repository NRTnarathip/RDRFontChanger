#include "SWFTypes.h"
#include "Logger.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

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
		swfFont* font = *(swfFont**)((long)mainFile->files + index * 8);
		cw("index: %d", index);
		cw("file: %p", font);
		cw("file name: %s, findName: %s", font->name, findFontName);
		if ((font != nullptr) && (GetSWFFileType(font) == SWFTypeEnum::Font)) {
			auto resultStrcmp = _stricmp(font->name, findFontName);
			cw("match!!");
			if (resultStrcmp == 0)
				return font;
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

typedef bool (*fnDoesFileExist)(PackFile_c* packFile, const char* name);
bool PackFile_DoesFileExist(PackFile_c* packFile, const char* name) {
	static fnDoesFileExist fn = (fnDoesFileExist)GetAddressFromRva(0xeae670);
	return fn(packFile, name);
}

#include <unordered_map>
void DumpPackFile(PackFile_c* packFile)
{
	cw("try dump pack file= %p", packFile);
	auto fileIndex = packFile->fileIndex;
	cw("file index: %p", fileIndex);
	cw("pack file name: %s", fileIndex->packFileName);
	cw("total files: %d", fileIndex->totalFiles);
	cw("files capacity: %d", fileIndex->fileHashCapacity);
	// file index static rva: RDR.exe+74357C0 

	std::ifstream fileNameStream("ImportedFileNames.txt");
	std::string name;
	std::unordered_map<uint32_t, std::string> fileNameMap;
	while (std::getline(fileNameStream, name)) {
		auto len = name.size();
		auto hash = RageHashFNV(name.data(), len);
		fileNameMap[hash] = name;
	}

	fileNameStream.close();
}

void DumpSWFContext(swfContext* ctx)
{
	cw("dump swf ctx: %p", ctx);
	cw("ctx name: %s", ctx->fileName);
	cw("try dump all files...");
	auto ctxFile = (swfFile*)ctx->file;
	cw("total file: %d", ctxFile->totalFiles);
	cw("magic: 0x%x", ctxFile->magic);
	auto directory = (void**)ctxFile->files;
	cw("files: %p", directory);
	cw("version: %d", ctxFile->version);
	for (int fileIndex = 0; fileIndex < ctx->file->totalFiles; fileIndex++) {
		auto file = (swfFile*)directory[fileIndex];
		cw("[%d] file: %p", fileIndex, file);
		if (file == nullptr)
			continue;

		//cw("name: %s", file->name);
		cw("magic: 0x%x", file->magic);
		auto fileType = (byte)file->magic;
		cw("file type: typeName: %s", GetSWFTypeName(fileType));
		cw("total files: %d", file->totalFiles);
		cw("obj map array: %p", file->objectMap);
		cw("obj map count: %d", file->objectMapCount);
	}
}

uint32_t RageHashFNV(const void* data, size_t len)
{
	const uint8_t* p = (const uint8_t*)data;
	uint32_t hash = FNV_OFFSET_BASIS_32;
	for (size_t i = 0; i < len; ++i)
		hash = (hash * 16777619u) ^ p[i];
	return hash;
}

bool swfSheet::IsTextureExist(const char* findName)
{
	if (this->textureCount == 0)
		return false;

	for (int i = 0;i < this->textureCount;i++) {
		auto name = textureNameArray[i];
		if (name && strcmp(name, findName) == 0)
			return true;
	}

	return false;
}
