#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <stack>

int child_process_create(std::stack<PROCESS_INFORMATION*>* processes);
void child_process_delete(std::stack<PROCESS_INFORMATION*>* processes);


int main()
{
	std::stack<PROCESS_INFORMATION*>* processes = new std::stack<PROCESS_INFORMATION*>;
	int key;
	while (true)
	{
		key = _getch();
		switch (key)
		{
		case '+':
		{
			child_process_create(processes);
			break;
		}
		case '-':
		{
			child_process_delete(processes);
		}
		case 'q':
		{
			while (!(*processes).empty())
			{
				child_process_delete(processes);
			}
			break;
		}
		}
	}


	return 0;
}

int child_process_create(std::stack<PROCESS_INFORMATION*>* processes)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	(*processes).push(&pi);
	if (!CreateProcessA(nullptr,					// No module name (use command line)
		&std::string("file_child.exe ").append(std::to_string((*processes).size()))[0],	// Command line
		nullptr,					// Process handle not inheritable
		nullptr,					// Thread handle not inheritable
		FALSE,					// Set handle inheritance to FALSE
		0,
		nullptr,					// Use parent's environment block
		nullptr,					// Use parent's starting directory 
		&si,					// Pointer to STARTUPINFO structure
		&pi)					// Pointer to PROCESS_INFORMATION structure
		)
	{
		(*processes).pop();
		printf("CreateProcess failed (%lu)\n", GetLastError());
		return -1;
	}
	return 0;
}

void child_process_delete(std::stack<PROCESS_INFORMATION*>* processes)
{
	PROCESS_INFORMATION* pi = (*processes).top();
	TerminateProcess((*pi).hProcess, 1);
	CloseHandle((*pi).hProcess);
	(*processes).pop();

}
