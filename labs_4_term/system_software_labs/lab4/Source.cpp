#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <string>
#include <fstream>
#include <iostream>
#include <boost/lockfree/stack.hpp>

struct child_thread_param
{
	int thread_number;
	int print_delay;
	int create_delay;
	boost::lockfree::stack<HANDLE>* threads;

	child_thread_param(boost::lockfree::stack<HANDLE>* threads, int thread_number, int print_delay, int create_delay) :
		threads(threads), thread_number(thread_number), print_delay(print_delay), create_delay(create_delay)
	{

	}
};

std::atomic_int counter = 0;

DWORD WINAPI child_thread_routine(LPVOID parameter);
DWORD WINAPI automatic_creating_thread_routine(LPVOID parameter);
void child_process_delete(boost::lockfree::stack<HANDLE>* threads);


int main(int argc, char** argv)
{
	if (argc != 3 && argc != 1)
		return 1;

	int delay_to_print = 500;
	int delay_to_create = 3000;

	if (argc == 3)
	{
		delay_to_print = atoi(argv[1]);
		delay_to_create = atoi(argv[2]);
	}


	boost::lockfree::stack<HANDLE>* threads = new boost::lockfree::stack<HANDLE>(20);

	child_thread_param parameter_auto(threads, counter, delay_to_print, delay_to_create);
	CreateThread(NULL, NULL, automatic_creating_thread_routine, &parameter_auto, NULL, NULL);

	while (true)
	{
		const int key = _getch();
		switch (key)
		{
		case '+':
		{
			++counter;
			child_thread_param parameter(threads, counter, delay_to_print, delay_to_create);
			auto thread_handle = CreateThread(NULL, NULL, child_thread_routine, &parameter, NULL, NULL);
			(*threads).push(thread_handle);
			break;
		}
		case '-':
		{
			--counter;
			child_process_delete(threads);
			break;
		}
		case 'q':
		{
			while (!(*threads).empty())
			{
				--counter;
				child_process_delete(threads);
			}
			return 0;
		}
		}
	}
}

void child_process_delete(boost::lockfree::stack<HANDLE>* threads)
{
	HANDLE handle;
	(*threads).pop(handle);
	TerminateThread(handle, 1);
	CloseHandle(handle);
}

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



DWORD WINAPI child_thread_routine(LPVOID parameter)
{
	auto thread_parameter = *static_cast<child_thread_param*>(parameter);

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
	
	const HANDLE mutex = CreateMutexA(nullptr, FALSE, "FileMutex");
	while (true)
	{
		const DWORD result = WaitForSingleObject(mutex, INFINITE);

		if (result == WAIT_OBJECT_0)
		{
			std::cout << "Process " << thread_parameter.thread_number << ": " << get_line_n("strings.txt", thread_parameter.thread_number) << std::endl;
			std::cout.flush();
			Sleep(thread_parameter.print_delay);

			ReleaseMutex(mutex);
		}

	}
}

DWORD WINAPI automatic_creating_thread_routine(LPVOID parameter)
{
	child_thread_param thread_info = *static_cast<child_thread_param*>(parameter);

	while (true)
	{
		Sleep(thread_info.create_delay);
		++counter;
		child_thread_param new_parameter(thread_info.threads, counter, thread_info.print_delay, thread_info.create_delay);		
		auto thread_handle = CreateThread(NULL, NULL, child_thread_routine, &new_parameter, NULL, NULL);
		(*thread_info.threads).push(thread_handle);
	}

}
