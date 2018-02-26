#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <string>

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcessA(nullptr,					// No module name (use command line)
		&std::string("child_coffe_process.exe")[0],	// Command line
		nullptr,					// Process handle not inheritable
		nullptr,					// Thread handle not inheritable
		FALSE,					// Set handle inheritance to FALSE
		CREATE_NEW_CONSOLE,		// lol
		nullptr,					// Use parent's environment block
		nullptr,					// Use parent's starting directory 
		&si,					// Pointer to STARTUPINFO structure
		&pi)					// Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%lu)\n", GetLastError());
		return -1;
	}

	SYSTEMTIME lt;

	while (WaitForSingleObject(pi.hProcess, 50))
	{
		GetLocalTime(&lt);
		printf("%02d:%02d:%02d p\r", lt.wHour, lt.wMinute, lt.wSecond);
	}

	CloseHandle(pi.hProcess);
	return 0;
}
