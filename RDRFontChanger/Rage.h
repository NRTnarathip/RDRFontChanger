#pragma once
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

std::string SafePath(std::string path);
std::string SafePath(fs::path path);
