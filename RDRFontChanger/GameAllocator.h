#pragma once
struct GameAllocator {
	static GameAllocator* Instance();
	virtual void vf0() = 0;
	virtual void vf1() = 0;
	virtual void* New(int bytes, int aligned) = 0;
	virtual void vf3() = 0;
	virtual void Delete(void* address) = 0;
};

