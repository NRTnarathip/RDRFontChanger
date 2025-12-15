#pragma once

struct grcImage {

};

struct grcImageFactory {
	virtual void* VF0() = 0;
	virtual void* VF1() = 0;
	virtual void* VF2() = 0;
	virtual void* VF3() = 0;
	virtual grcImage* CreateTexture(const char* fileName, int unk) = 0;

	static grcImageFactory* GetGrcImageFactory();
};

