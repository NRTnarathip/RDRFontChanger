#pragma once
#include "ISystem.h"
#include <iostream>
#include <unordered_set>
#include "SWFTypes.h"

class FontManager : public ISystem
{
public:
	FontManager();

	// member
	bool Init() override;
	std::unordered_set<swfFont*> GetFonts();
	typedef void (*OnCreateFont)(swfFont*);
	typedef void (*OnDeleteFont)(swfFont*);
	void RegisterOnCreateFont(OnCreateFont fn);
	void RegisterOnDeleteFont(OnDeleteFont fn);
	void InvokeOnCreateFont(swfFont* font);
	void InvokeOnDeleteFont(swfFont* font);

	// static 
	static FontManager* Instance();
	static std::string MakeGameFontNameKey(std::string gameFontName);

private:
	std::unordered_set<OnCreateFont> m_onCreateFontSet;
	std::unordered_set<OnDeleteFont> m_onDeleteFontSet;
};

