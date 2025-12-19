#pragma once
#include "ISystem.h"



class RenderHook : public ISystem
{
public:
	bool Init() override;
	static RenderHook* Instance();
};

