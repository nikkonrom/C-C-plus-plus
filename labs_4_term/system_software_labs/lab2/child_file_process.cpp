#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iostream>

std::string get_line_n(const std::string& filename, int n)
{
	std::ifstream f(filename);
	std::string line;
	while (n >= 0)
	{
		std::getline(f, line);
		--n;		
	}
	return line;
}

HANDLE ghJob = CreateJobObjectA(NULL, NULL);


int main(int argc, char* argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcessA(nullptr,					// No module name (use command line)
		&std::string("coffee_child.exe")[0],	// Command line
		nullptr,					// Process handle not inheritable
		nullptr,					// Thread handle not inheritable
		FALSE,					// Set handle inheritance to FALSE
		CREATE_NEW_CONSOLE,
		nullptr,					// Use parent's environment block
		nullptr,					// Use parent's starting directory 
		&si,					// Pointer to STARTUPINFO structure
		&pi)					// Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%lu)\n", GetLastError());
		return -1;
	}
	HANDLE mutex = CreateMutexA(NULL, FALSE, "FileMutex");
	while (true)
	{
		DWORD result = WaitForSingleObject(mutex, INFINITE);

		if (result == WAIT_OBJECT_0)
		{
			std::cout << "Process " << argv[1] << ": " << get_line_n("strings.txt", atoi(argv[1])) << std::endl;
			std::cout.flush();
			Sleep(10);
			ReleaseMutex(mutex);
		}
	}
}
