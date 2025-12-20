#include <iostream>
#include <filesystem>
#include <fstream>
#include <print>
#include "Logger.h"
#include "SDFont.h"

namespace fs = std::filesystem;

int main()
{
	fs::path path = R"(D:\RDRModder\ThaiFontMaker\SDFont-App\thai_sdf.txt)";
	SDFont font(path);
	cw("try make min max bitmap font");
	while (true) {}
}
