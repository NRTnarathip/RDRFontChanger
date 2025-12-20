#include "Rage.h"
#include <iostream>
#include <filesystem>
#include "StringLib.h"

namespace fs = std::filesystem;

std::string SafePath(std::string path) {
	auto fspath = fs::path(path);
	return SafePath(fspath);
}

std::string SafePath(fs::path inputPath)
{
	auto result = inputPath.generic_string();
	result = ToLower(result);
	return result;
}
