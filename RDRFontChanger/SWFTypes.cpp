#include "SWFTypes.h"
#include "Logger.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "XMem.h"
#include "Rage.h"
#include <print>

using namespace XMem;

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
		auto fontName = font->name();
		cw("file name: %s, findName: %s", fontName.c_str(), findFontName);
		if ((font != nullptr) && (GetSWFFileType(font) == SWFTypeEnum::Font)) {
			auto resultStrcmp = _stricmp(fontName.c_str(), findFontName);
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

bool swfSheet::DoesTextureContains(std::string findName) {
	if (this->textureCount == 0)
		return false;

	findName = SafePath(findName);
	for (int i = 0;i < this->textureCount;i++) {
		std::string textureName = textureNameArray[i];
		textureName = SafePath(textureName);
		if (textureName.contains(findName))
			return true;
	}

	return false;
}

int swfSheet::FindTextureIndexOf(std::string findName)
{
	if (this->textureCount == 0)
		return -1;

	findName = SafePath(findName);
	for (int i = 0;i < this->textureCount;i++) {
		std::string textureName = textureNameArray[i];
		textureName = SafePath(textureName);
		if (textureName == findName)
			return i;
	}

	return -1;
}

bool swfSheet::DoesTextureExist(std::string findName)
{
	if (this->textureCount == 0)
		return false;

	cw("DoesTextureExist: %s", findName.c_str());
	std::println("print ln: %s", findName.c_str());

	findName = SafePath(findName);
	for (int i = 0;i < this->textureCount;i++) {
		std::string name = textureNameArray[i];
		name = SafePath(name);
		cw("check texture key: %s, findName: %s", name.c_str(), findName.c_str());
		if (name == findName)
			return true;
	}

	return false;
}

swfFont* swfFont::Clone()
{
	auto  clone = new swfFont();
	memcpy(clone, this, sizeof(swfFont));

	// Todo!
	//memcpy(clone->sheet, this->sheet, sizeof(swfSheet));
	//clone->sheet->cellArrayPtr = new swfGlyph[sheet->cellCount];

	//clone->sheet->textureArray = (grcTextureD11**)(new grcTextureD11[clone->sheet->textureCount]);
	//memcpy(clone->sheet->textureArray, sheet->textureArray, );

	return clone;
}

void swfFont::LogInfo()
{
	cw(" -- Font Info --");
	std::string name = nameBuffer;
	cw("name: %s", name.c_str());
	cw("ascent: %d", ascent);
	cw("descent: %d", descent);
	cw("sheet: %p", sheet);
	if (sheet) {
		cw("font size: %d", sheet->size);
		cw("glyph count: %d", sheet->cellCount);
		cw("texture count: %d", sheet->textureCount);
		for (int i = 0;i < sheet->textureCount;i++) {
			std::string name = sheet->textureNameArray[i];
			cw("texture[%d]: %s", i, name.c_str());
		}
	}
	cw(" -- End Font Info --");
}
