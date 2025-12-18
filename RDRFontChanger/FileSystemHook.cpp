#include "FileSystemHook.h"
#include "Logger.h"
#include <Windows.h>
#include "HookLib.h"
using namespace HookLib;

#include "StringLib.h"



typedef BOOL(WINAPI* ReadFile_t)(
	HANDLE,
	LPVOID,
	DWORD,
	LPDWORD,
	LPOVERLAPPED
	);
ReadFile_t fnReadFile;
BOOL WINAPI HK_ReadFile(HANDLE hFile, LPVOID buffer,
	DWORD size, LPDWORD bytesRead, LPOVERLAPPED overlapped)
{
	wchar_t pathWString[MAX_PATH];
	cw("Hook ReaFile...");

	if (GetFinalPathNameByHandleW(
		hFile,
		pathWString,
		MAX_PATH,
		FILE_NAME_NORMALIZED
	)) {
		auto path = WCharToString(pathWString);
		cw("[ReadFile] %s | size=%lu", path.c_str(), size);
	}

	return fnReadFile(
		hFile,
		buffer,
		size,
		bytesRead,
		overlapped
	);
}
void SetupFileSystemHook()
{
	auto kernelbase = L"KERNELBASE.dll";
	HookImport(kernelbase, "ReadFile", HK_ReadFile, &fnReadFile);
}
