#include "GameAllocator.h"
#include "XMem.h"
#include "HookLib.h"

GameAllocator* GameAllocator::Instance()
{
	static GameAllocator* instance;
	if (instance == nullptr)
		instance = HookLib::InvokeRva<GameAllocator*>(0x7fd70);
	return instance;
}
