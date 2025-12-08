#pragma once

#include <windows.h>

#define IMPORT __declspec(dllimport)

typedef void(*KeyboardHandler)(DWORD, WORD, BYTE, BOOL, BOOL, BOOL, BOOL);

IMPORT void keyboardHandlerRegister(KeyboardHandler handler);

IMPORT void keyboardHandlerUnregister(KeyboardHandler handler);

IMPORT void scriptWait(DWORD time);
IMPORT void scriptRegister(HMODULE module, void(*LP_SCRIPT_MAIN)());
IMPORT void scriptRegisterAdditionalThread(HMODULE module, void(*LP_SCRIPT_MAIN)());
IMPORT void scriptUnregister(HMODULE module);

IMPORT void nativeInit(UINT64 hash);
IMPORT void nativePush64(UINT64 val);
IMPORT PUINT64 nativeCall();

static void WAIT(DWORD time) { scriptWait(time); }

IMPORT UINT64 *getGlobalPtr(int globalId);
IMPORT UINT64 *getStaticPtr(const char* scriptName, int staticId);

IMPORT void* getCommandFromHash(UINT64 hash);

// Drawing

/*
	Make sure to call these functions every frame if you want to render something on the screen!
	The coordiantes behave the same as in other Rockstar Games titles. x=0.5, y=0.5 is center of the screen on any resolution.
	Width and Height: 0.2 is 20% width of your screen, same goes for height
	There are some default fonts that are already embedded into ScriptHook, you can look them up in the enums.h file!
*/
IMPORT void drawRect(float x, float y, float width, float height, int r, int g, int b, int a, float rounding);
/*
* Color Tags available:
* <red>Text</red>
* <orange>Text</orange>
* <yellow>Text</yellow>
* <green>Text</green>
* <blue>Text</blue>
* <purple>Text</purple>
* <brown>Text</brown>
* <sepia>Text</sepia>
* <grey>Text</grey>
*/
IMPORT void drawText(float x, float y, const char* text, int r, int g, int b, int a, int fontId, float fontSize, int justification);
IMPORT void drawSprite(float x, float y, float width, float height, int spriteId, float rotation, int r, int g, int b, int a);

/*	
	IMPORTANT: Only call this function once, in DllMain after scriptRegister!
	This function accepts a path to a .ttf file, make sure to check the fontSize before registering it. Usually you always want to pass sizePixels=72.0f
	RETURNS: fontId to use in drawText.
*/
IMPORT int registerFont(const char* filename, float sizePixels);
/*
	This is only for when you reload your mod or if you want to actively provide a good reload functionality. The reason for this export is that if you reload your mod, you will use the ID of your registered font, so in order to get it back, you can call this export.
	I would advise you to implement it this way:
	customFontId = getCustomFontByPath("my/path/to/font.ttf");
	if (customFontId < 0) {
		customFontId = registerFont("my/path/to/font.ttf", 72.0f);
	}
*/
IMPORT int getCustomFontByPath(const char* filename);
/*
	IMPORTANT: Only call this function once, at the beginning of your script!
	This function accepts a path to any image format (.png, .jpg, .jpeg, ...)
	RETURNS: if successfull it returns the spriteId to use in drawSprite.
*/
IMPORT int registerSprite(const char* filepath);
IMPORT int registerSprite(unsigned int width, unsigned int height, const void* data);


/*
	This function can be used to get all actors in the game world.
	RETURNS: the number of actors found and in array.
	
	USAGE: (Kill all actors, but local actor)
	constexpr int SIZE = 100;
	int actors[SIZE];

	int count = worldGetAllActors(actors, SIZE);

	for (int i = 0; i < count; i++) {
		if (!ENTITY::IS_ACTOR_VALID(actors[i])) continue;
		if (ACTOR::IS_ACTOR_LOCAL_PLAYER(actors[i])) continue;

		HEALTH::KILL_ACTOR(actors[i]);
	}
*/
IMPORT int worldGetAllActors(int* arr, int size);


/*
	You can pass any object to this function and it will return the address of it in memory.
*/
IMPORT BYTE* getScriptHandleBaseAddress(int handle);

/*
	Get the current ScriptHook version, this is extremely important to check if your mod is using features from newer scripthook updates. Make sure to check if the minimal requirement is given with this enum and export.
*/
enum eScriptHookVersion : int {
	VER_1_0 = 0,
	VER_1_1,
	VER_1_2,
	VER_1_3,
	VER_1_5,
	VER_1_5_1
};

IMPORT eScriptHookVersion getVersion();

/*
* You can use this export to call any script function defined in any script in the game.
* The scriptname has to be the offical hash representation, that means: $/content/main would be atStringHash -> 0xC35697FF
* The positon is the function address in memory of the script. You can get the position with MagicRDR's script decompiler. It will be next to the function definition.
* Argcount and args, is relatively self explanatory.
* 
* Example to give money, via a function call in the main script:
 	std::vector<u64> args{1000, 1, 1 };
	scriptCall("$/content/main", 107871, (u32)args.size(), args.data());

	This will add 1000 $ to your bank account.

* Important: it could be the case that the "pause" script functions won't work, simply because of the design of the game.
*/
IMPORT UINT64 scriptCall(const char* scriptName, UINT32 position, UINT32 argCount, PUINT64 args);