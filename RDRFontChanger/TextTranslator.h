#pragma once
#include <iostream>
#include "CustomFont.h"

class TextTranslator
{
public:
	static void Initialize();
	static bool TryTranslate(std::string& inout, CustomFont* font);
};

