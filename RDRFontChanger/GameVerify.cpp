#include "GameVerify.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include "Logger.h"


bool GameVerify::Assert()
{
	std::ifstream file("RDR.exe", std::ios::binary);
	if (!file.is_open())
		return false;

	IMAGE_DOS_HEADER dos{};
	file.read((char*)&dos, sizeof(dos));


	IMAGE_FILE_HEADER fileHeader{};
	file.seekg(dos.e_lfanew + sizeof(DWORD)); // skip file signature
	file.read((char*)&fileHeader, sizeof(fileHeader));

	time_t t = fileHeader.TimeDateStamp;
	cw("current game TimeDateStamp: 0x%x", fileHeader.TimeDateStamp);
	cw("target assert TimeDateStamp: 0x%x", K_AssertTimeDateStamp);

	bool verify = t == K_AssertTimeDateStamp;
	cw("verify?: %s", verify ? "yes" : "no");

	return verify;
}
