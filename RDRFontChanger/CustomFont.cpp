#include "CustomFont.h"
#include "Logger.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

std::unordered_map<void*, int> CustomFont::g_registeredFontGlyphs;

static std::unordered_set<void*> g_dumpFonts;
void TryDumpSwfFont(swfFont* font) {
	// dump font
	if (g_dumpFonts.contains(font) == false) {
		g_dumpFonts.insert(font);
		std::string fileNameStr = std::format("font_{}.txt", (void*)font);
		logFormat("try dump font to file: %s", fileNameStr.c_str());

		std::ofstream stream(fileNameStr.c_str(), std::ios::out | std::ios::trunc);
		logFormat("opened stream file!");

		stream << std::format("font address={}", (void*)font) << "\n";

		auto sheet = font->sheetArrayPtr;
		auto glyphArrayFirstElement = (swfGlyph**)sheet->glyphArrayFirstItem;
		for (int i = 0;i < font->glyphCount;i++)
		{
			unsigned short currentCode = font->glyphToCodeArrayFirstItem[i];
			auto gAddress = (uintptr_t)glyphArrayFirstElement + i * sizeof(swfGlyph);
			auto g = (swfGlyph*)gAddress;
			auto line = std::format("index={}, char={}, left={:.2f}, top={:.2f}, width={:.2f}, height={:.2f}, a={:.2f}, b={:.2f}, c={:.2f}, d={:.2f}",
				i, currentCode,
				g->left, g->top, g->width, g->height,
				g->u0x10, g->u0x14, g->u0x18, g->u0x1C);
			stream << line.c_str() << "\n";
			float advance = *((float*)font->advanceFirstItem + i);
			auto line2 = std::format("advance={}\n", advance);
			stream << line2;
		}
		stream.close();
		logFormat("dump success for font file name: %s", fileNameStr.c_str());
	}

}

void CustomFont::RegisterGlyph(swfFont* font, BitmapFont& bitmapFont, BitmapFont::Glyph& bitmapGlyph)
{
	// init
	if (g_registeredFontGlyphs.contains(font) == false) {
		g_registeredFontGlyphs[font] = 0;
	}

	int glyphIndex = g_registeredFontGlyphs[font];

	// can't register max char
	if (glyphIndex == font->glyphCount - 1)
		return;

	// increement
	g_registeredFontGlyphs[font] += 1;


	// update x advance
	float* advanceArray = (float*)font->advanceFirstItem;

	// img size / font size
	float advanceScale = 1.0;
	advanceArray[glyphIndex] = bitmapGlyph.xadvance * advanceScale;

	// update glyphToCode 
	unsigned short* glyphToCodeArray = font->glyphToCodeArrayFirstItem;
	glyphToCodeArray[glyphIndex] = (unsigned short)bitmapGlyph.id;

	// replace glyph with custom
	auto sheet = font->sheetArrayPtr;
	swfGlyph* glyphArray = (swfGlyph*)sheet->glyphArrayFirstItem;
	swfGlyph* g = glyphArray + glyphIndex;
	g->left = bitmapGlyph.x;
	g->top = bitmapGlyph.y;
	g->width = bitmapGlyph.width;
	g->height = bitmapGlyph.height;
	float baseline = bitmapFont.baseline;
	float xoffset = bitmapGlyph.xoffset;
	float yoffset = bitmapGlyph.yoffset;
	// Formula (Y-up coordinate)
	float bmY_top = baseline - yoffset - bitmapFont.lineHeight;
	float bmY_bot = baseline - yoffset;

	float bearingX = xoffset;
	float bearingY = bitmapFont.lineHeight - yoffset - g->height;

	float unkScale = 1;
	g->u0x10 = bearingX * unkScale;
	g->u0x14 = -bearingY * unkScale;
	g->u0x18 = (g->left + g->width) * unkScale;
	g->u0x1C = (g->top + g->height) * unkScale;
	logFormat("reigstered font: x:%d, y:%d, w:%d, h:%d", (int)g->left, (int)g->top, (int)g->width, (int)g->height);
	logFormat("unk info: a:%d, b:%d, c:%d, d:%d", (int)g->u0x10, (int)g->u0x14, (int)g->u0x18, (int)g->u0x1C);
}

void CustomFont::TryRegisterThaiFontGlyphs(swfFont* font) {
	if (g_registeredFontGlyphs.contains(font) == false) {
		static BitmapFont thaiBitmapFont;
		if (thaiBitmapFont.isLoaded == false) {
			thaiBitmapFont.Load("thai.fnt");
		}

		logFormat("registered font glyphs for: %p", font);
		for (int i = 0;i < thaiBitmapFont.glyphs.size();i++) {
			auto g = thaiBitmapFont.glyphs[i];
			RegisterGlyph(font, thaiBitmapFont, g);
		}
	}
}


void BitmapFont::ParseGlyph(const std::string& line, BitmapFont::Glyph& g) {
	auto lineCstr = line.c_str();
	sscanf(lineCstr, "char id=%d x=%d y=%d width=%d height=%d xoffset=%d yoffset=%d xadvance=%d page=%d chnl=%d",
		&g.id, &g.x, &g.y, &g.width, &g.height,
		&g.xoffset, &g.yoffset, &g.xadvance, &g.page, &g.chnl);
}


void BitmapFont::Load(std::string path)
{
	if (isLoaded)
		return;
	isLoaded = true;

	std::ifstream file(path);
	std::string line;

	while (std::getline(file, line)) {
		auto lineCstr = line.c_str();
		// parse line
		if (line.find("char id=") == 0) {
			Glyph g;
			ParseGlyph(line, g);
			this->glyphs.push_back(g);
		}
		else if (line.find("common") == 0) {
			sscanf(lineCstr, "common lineHeight=%d base=%d scaleW=%d scaleH=%d",
				&lineHeight, &baseline, &scaleW, &scaleH);
		}
		else if (line.find("info") == 0) {
			sscanf(lineCstr, "info face=\"%[^\"]\" size=%d bold=%d italic=%d",
				face, &size, &bold, &italic);
			fontName = face;
		}
	}
	logFormat("loaded bitmap font name: %s, size: %d", fontName, size);
}
