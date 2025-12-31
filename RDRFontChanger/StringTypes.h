#pragma once
#include <iostream>
#include "AssertLib.h"


struct txtStringData {
	uint32_t hash; // 0
	const char* string; // x8
};

// size 0x18!
struct txtHashEntry {
	uint32_t hash; // 0x0
	uint32_t hashUnk; // 0x4
	txtStringData* data; // 0x8
	//// helper access to next array
	txtHashEntry* next; // 0x10
};
CHECK_OFFSET(txtHashEntry, next, 0x10);


struct txtHashTable {
	int numSlots;
	// vector<txtHashEntry> here!
	struct Vector {
		txtHashEntry** elements;
		unsigned short capacity;
		unsigned short count;
	};
	Vector entryVector;
	int numEntries;
};

CHECK_OFFSET(txtHashTable, numEntries, 0x18);

// confirm size: 0x28 PC
struct txtStringTable {
	void** vftable;
	void* x8; // x8
	txtHashTable* hashTable; //0x10
	char** stringKeyArray;
	int stringKeyArrayCount;
};


// confirm size: 0x18!
struct swfString {

};
