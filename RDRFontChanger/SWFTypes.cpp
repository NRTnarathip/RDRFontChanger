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
