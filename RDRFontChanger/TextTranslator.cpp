#include "TextTranslator.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "StringLib.h"
#include "Logger.h"
#include "HookLib.h"
#include "StringTypes.h"


using namespace HookLib;
namespace fs = std::filesystem;

const char* k_translate_strings_dir = "mods/translate_strings";

std::unordered_map<std::string, std::string> TextTranslator::g_translateStringMap;
std::vector<TextTranslateCsvFile*> TextTranslator::g_translateFiles;

void TryTranslateStringData(txtStringData* data) {

	if (data == nullptr || data->string == nullptr)
		return;

	std::string engString = data->string;
	auto translateResult = TextTranslator::TryTranslate(engString);
	if (translateResult) {
		std::string translateString = translateResult;
		// cw("new translate string!: %s", translateString.c_str());

		int allocSize = translateString.size() + 1;
		auto allocString = (char*)XMem::Allocate(allocSize, 1);
		memcpy(allocString, translateResult, translateString.size());
		allocString[allocSize - 1] = '\0';
		data->string = allocString;
	}

}
void TryTranslateStringTable(txtStringTable* self) {
	cw("try TryTranslateStringTable...");
	cw("stringTable: %p", self);
	if (self == nullptr)
		return;

	auto hashTable = self->hashTable;
	cw("hash table: %p", hashTable);
	if (hashTable == nullptr)
		return;

	auto entryVector = hashTable->entryVector;
	cw("numEntries: %d", hashTable->numEntries);
	int loopCounter = 0;
	for (int slot = 0; slot < entryVector.count; slot++) {
		txtHashEntry* entry = entryVector.elements[slot];
		//cw("slot index: %d", slot);
		//cw("begin entry: %p", entry);
		while (entry != nullptr) {
			loopCounter++;
			cw("[%d/%d] entry: %p", loopCounter, hashTable->numEntries, entry);
			auto data = entry->data;
			if (data) {
				// cw("[%d] data string: %s", i, data->string);
				TryTranslateStringData(data);
			}

			// move next!
			entry = entry->next;
		}
	}
	cw("end TryTranslateStringTable");
}

void* (*fn_txtStringTable_Load)(txtStringTable* self, byte* p2_path,
	int p3_langCode, void* param_4, void* param_5,
	void* param_6, void* param_7, void* param_8, void* p9);
void* HK_txtStringTable_Load(txtStringTable* self, byte* p2_path,
	int p3_langCode, void* param_4, void* param_5,
	void* param_6, void* param_7, void* param_8, void* p9) {
	cw("BeginHook HK_txtStringTable_Load");
	cw("p2_path: %s", p2_path);
	cw("try call fn_txtStringTable_Load");
	auto result = fn_txtStringTable_Load(self,
		p2_path, p3_langCode, param_4,
		param_5, param_6, param_7, param_8, p9);
	cw("HK_txtStringTable_Load result: %p", result);
	// TryTranslateStringTable(self);
	cw("EndHook HK_txtStringTable_Load");
	return result;
}

void* (*fn_txtStringTableReader)(void* reader, void* p1);
void* HK_txtStringTableReader(void* reader, void* p1) {
	cw("BeginHook HK_txtStringTableReader");
	cw("reader: %p", reader);
	cw("reader + 0x0: %p", *(void**)reader);
	cw("p1: %p", p1);

	cw("calling fn_txtStringTableReader...");
	auto r = fn_txtStringTableReader(reader, p1);
	cw("done call fn_txtStringTableReader");
	// TryTranslateStringTable(*(txtStringTable**)reader);

	cw("EndHook HK_txtStringTableReader");
	return r;
}

void* (*fn_txtStingTable_VF0)(txtStringTable* self, void* p1);
void* HK_txtStingTable_VF0(txtStringTable* self, void* p1) {
	cw("Begin HK_txtStingTable_VF0");
	auto r = fn_txtStingTable_VF0(self, p1);
	cw("HK_txtStingTable_VF0 result: %p", r);
	cw("End HK_txtStingTable_VF0");
	return r;
}

bool (*fn_txtHashTable_Insert)(txtHashTable* self, uint32_t hash, txtStringData* entry);
bool HK_txtHashTable_Insert(txtHashTable* self, uint32_t hash, txtStringData* entry) {
	//cw("Begin HK_txtHashTable_Insert");
	cw("string: %s", entry->string);
	TryTranslateStringData(entry);

	auto r = fn_txtHashTable_Insert(self, hash, entry);

	// cw("End HK_txtHashTable_Insert");
	return r;
}

txtStringData* (*fn_txtStringTableGet)(txtStringTable* self, uint32_t hash);
txtStringData* HK_txtStringTableGet(txtStringTable* self, uint32_t hash) {
	// cw("Begin HK_txtStringTableGet");

	auto result = fn_txtStringTableGet(self, hash);
	if (result) {
		TryTranslateStringData(result);
	}
	// cw("End HK_txtStringTableGet");
	return result;
}

bool (*fn_txtStringDataLoad)(txtStringData* self,
	void* reader, void* p2, void* p3, void* p4);
bool HK_txtStringDataLoad(txtStringData* self,
	void* reader, void* p2, void* p3, void* p4) {
	cw("Begin HK_txtStringDataLoad");
	auto result = fn_txtStringDataLoad(self, reader, p2, p3, p4);
	if (result) {
		cw("string: %s", self->string);
		TryTranslateStringData(self);
	}
	cw("End HK_txtStringDataLoad");
	return result;
}

void TextTranslator::AddTranslateString(std::string key, std::string newText)
{
	if (key.length() <= 1)
		return;

	g_translateStringMap[key] = newText;
	// cw("added translate: %s = %s", key.c_str(), newText.c_str());
}

bool TextTranslator::Init() {
	// init game hooks
	cw("try initialize Translatator");

	cw("setup hooks...");
	//HookRva(0x17fc50, HK_txtStringTable_Load, &fn_txtStringTable_Load);
	//HookRva(0xfbf30, HK_txtStringTableReader, &fn_txtStringTableReader);
	// HookRva(0x193c60, HK_txtHashTable_Insert, &fn_txtHashTable_Insert);
	HookRva(0x1800d0, HK_txtStringTableGet, &fn_txtStringTableGet);
	// HookRva(0x17f850, HK_txtStringDataLoad, &fn_txtStringDataLoad);



	cw("try load translate files...");
	// fetch all files
	std::unordered_set<std::string> csvFiles;
	if (fs::exists(k_translate_strings_dir) && fs::is_directory(k_translate_strings_dir)) {
		for (const auto& entry : fs::directory_iterator(k_translate_strings_dir)) {
			auto path = entry.path();
			if (fs::is_regular_file(entry) && path.extension() == ".csv") {
				csvFiles.insert(path.generic_string());
			}
		}
	}

	// search translate text file with @
	for (auto csvPath : csvFiles) {
		cw("localize csv file: %s", csvPath.c_str());

		// ready!!
		auto translateFile = new TextTranslateCsvFile(csvPath);
		g_translateFiles.push_back(translateFile);
		if (translateFile->TryLoad() == false) {
			cw("failed to load translate file!");
			continue;
		}


		cw("loaded translate csv file: %s", csvPath.c_str());

		// build translate string map!
		auto translateMap = translateFile->GetTranslateMap();
		for (auto [engKey, newString] : translateMap) {
			if (newString.size() >= 2)
				AddTranslateString(engKey, newString);
		}
	}

	return true;
}

const char* TextTranslator::TryTranslate(std::string english)
{
	static std::unordered_set<std::string> g_isTranslateStringSet;
	if (g_isTranslateStringSet.contains(english))
		return nullptr;

	if (g_translateStringMap.empty())
		return nullptr;

	if (english.size() <= 1)
		return nullptr;

	auto key = TextTranslateCsvFile::MakeEnglishRowKey(english);

	cw("try translate string key: %s", key.c_str());
	cw("string key len: %d", key.length());
	cw("english len: %d", english.length());

	const char* result = nullptr;
	if (g_translateStringMap.contains(key)) {
		result = (&g_translateStringMap[key])->c_str();
		cw("translated string: %s", result);
		g_isTranslateStringSet.insert(result);
	}
	else {
		cw("not found string to translate!");
	}

	return result;
}

