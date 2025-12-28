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

const char* localizeDir = "mods/localize";

std::unordered_map<std::string, std::string> TextTranslator::g_translateStringMap;
std::unordered_map<std::string, std::string> TextTranslator::g_isTranslateYetMap;
std::vector<TextTranslateCsvFile*> TextTranslator::g_translateFiles;

void TryTranslateStringTable(txtStringTable* self) {
	cw("try TryTranslateStringTable...");
	cw("stringTable: %p", self);
	if (self == nullptr)
		return;

	auto hashTable = self->hashTable;
	// cw("hash table: %p", hashTable);
	if (hashTable == nullptr)
		return;

	auto vector = hashTable->entryVector;
	// cw("entry vector count: %d", vector.count);
	// cw("num slot: %d", hashTable->numSlots);
	cw("numEntries: %d", hashTable->numEntries);
	for (int slot = 0; slot < hashTable->numSlots;slot++) {
		txtHashEntry* entry = vector.elements[slot];
		//cw("slot index: %d", slot);
		//cw("begin entry: %p", entry);
		int i = -1;
		while (entry != nullptr) {
			i++;
			// cw("[%d] entry: %p", i, entry);
			auto data = entry->data;
			if (data == nullptr) {
				//	cw("skip data null!");
				break;
			}

			// cw("[%d] data string: %s", i, data->string);

			if (TextTranslator::IsTranslateYet(data->string) == false) {
				auto translateResult = TextTranslator::TryTranslate(data->string);
				if (translateResult) {
					data->string = translateResult;
					//cw("replaced game string: %s", gameString.c_str());
					//cw("new string:           %s", tempNewString.c_str());
				}
			}

			// move next!
			entry = entry->next;
		}
	}
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
	TryTranslateStringTable(self);
	cw("EndHook HK_txtStringTable_Load");
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
	HookRva(0x17fc50, HK_txtStringTable_Load, &fn_txtStringTable_Load);



	cw("try load translate files...");
	// fetch all files
	std::unordered_set<std::string> csvFiles;
	if (fs::exists(localizeDir) && fs::is_directory(localizeDir)) {
		for (const auto& entry : fs::directory_iterator(localizeDir)) {
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
	if (g_translateStringMap.empty())
		return nullptr;

	auto key = TextTranslateCsvFile::MakeEnglishRowKey(english);

	cw("try translate string key: %s", key.c_str());

	const char* result = nullptr;
	if (g_translateStringMap.contains(key)) {
		result = (&g_translateStringMap[key])->c_str();
		g_isTranslateYetMap[result] = result;
		cw("translated string: %s", result);
	}

	return result;
}

bool TextTranslator::IsTranslateYet(const char* str)
{
	return g_isTranslateYetMap.contains(str);
}

