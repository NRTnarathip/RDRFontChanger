#pragma once

#include <windows.h>

typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Actor;
typedef int ActorSet;
typedef int Player;
typedef int Vehicle;
typedef int Camera;
typedef int Cam;
typedef int Object;
typedef int Layout;
typedef int GUIWindow;
typedef int Blip;
typedef int Prompt;
typedef int Mount;
typedef int Volume;
typedef int FireHandle;
typedef int ScrHandle;
typedef int Iterator;
typedef int PersChar;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

#pragma pack(push, 1)
typedef struct
{
	float x;
	float y;
	float z;
} Vector3;
#pragma pack(pop)

typedef struct 
{ 
	float x, y;
} Vector2;

typedef struct
{ 
	int R, G, B, A; 
} RGBA;