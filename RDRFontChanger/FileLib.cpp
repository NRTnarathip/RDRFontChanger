#include "FileLib.h"
#include <filesystem>

namespace fs = std::filesystem;


void GetFiles(std::string dir, std::vector<std::string>& files) {
	if (fs::exists(dir) && fs::is_directory(dir)) {
		for (const auto& entry : fs::directory_iterator(dir)) {
			if (fs::is_regular_file(entry)) {
				auto path = entry.path();
				auto relativePath = fs::relative(path);
				files.push_back(relativePath.string());
			}
		}
	}
}
