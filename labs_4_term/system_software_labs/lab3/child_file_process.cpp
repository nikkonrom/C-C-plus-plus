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


int main(int argc, char* argv[])
{
	int process_number;

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
	const HANDLE memory_mutex= CreateMutexA(nullptr, FALSE, "SharedMemoryMutex");
	const DWORD memory_result = WaitForSingleObject(memory_mutex, INFINITE);
	if (memory_result == WAIT_OBJECT_0)
	{
		const auto shared_memory_name = "process_name_memory";
		const auto h_file_mapping = OpenFileMapping(FILE_MAP_READ, FALSE, shared_memory_name);
		const auto lp_file_map = MapViewOfFile(h_file_mapping,
			FILE_MAP_READ, 0, 0, 0);

		process_number = *static_cast<int*>(lp_file_map);
		UnmapViewOfFile(lp_file_map);
		CloseHandle(h_file_mapping);
		ReleaseMutex(memory_mutex);
	}

	const HANDLE mutex = CreateMutexA(nullptr, FALSE, "FileMutex");
	while (true)
	{
		const DWORD result = WaitForSingleObject(mutex, INFINITE);

		if (result == WAIT_OBJECT_0)
		{
			std::cout << "Process " << process_number << ": " << get_line_n("strings.txt", process_number) << std::endl;
			std::cout.flush();
			Sleep(500);
			
			ReleaseMutex(mutex);
		}

	}
}

