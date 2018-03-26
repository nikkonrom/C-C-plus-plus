//#include <cstdio>
//#include <cstdlib>
//#include <Windows.h>
//#include <conio.h>
//#include <string>
//#include <stack>
//
//int child_process_create(std::stack<PROCESS_INFORMATION*>* processes, LPVOID sharedMemPtr);
//void child_process_delete(std::stack<PROCESS_INFORMATION*>* processes);
//
//int main()
//{
//	const auto processes = new std::stack<PROCESS_INFORMATION*>;
//
//	const auto shared_memory_name = "process_name_memory";
//	auto hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0, 10000, shared_memory_name);
//	if (hFileMapping == nullptr)
//		return 1;
//
//	auto lpFileMap = MapViewOfFile(hFileMapping, FILE_MAP_WRITE, 0, 0, 0);
//	if (lpFileMap == nullptr)
//		return 1;
//
//	while (true)
//	{
//		const int key = _getch();
//		switch (key)
//		{
//		case '+':
//		{
//			child_process_create(processes, lpFileMap);
//			break;
//		}
//		case '-':
//		{
//			child_process_delete(processes);
//			break;
//		}
//		case 'q':
//		{
//			while (!(*processes).empty())
//			{
//				child_process_delete(processes);
//			}
//			UnmapViewOfFile(lpFileMap);
//			CloseHandle(hFileMapping);
//			return 0;
//		}
//		}
//	}
//}
//
//int child_process_create(std::stack<PROCESS_INFORMATION*>* processes, LPVOID fileMapPtr)
//{
//	*static_cast<int*>(fileMapPtr) = (*processes).size();
//
//	STARTUPINFO si;
//	auto pi = new PROCESS_INFORMATION;
//	ZeroMemory(&si, sizeof(si));
//	si.cb = sizeof(si);
//	ZeroMemory(pi, sizeof(pi));
//	auto parameter = std::string("file_child.exe");
//
//	if (!CreateProcessA(nullptr,					// No module name (use command line)
//		&parameter[0],	// Command line
//		nullptr,					// Process handle not inheritable
//		nullptr,					// Thread handle not inheritable
//		FALSE,					// Set handle inheritance to FALSE
//		0,
//		nullptr,					// Use parent's environment block
//		nullptr,					// Use parent's starting directory 
//		&si,					// Pointer to STARTUPINFO structure
//		pi)					// Pointer to PROCESS_INFORMATION structure
//		)
//	{
//
//		printf("CreateProcess failed (%lu)\n", GetLastError());
//		return -1;
//	}
//	(*processes).push(pi);
//	return 0;
//}
//
//void child_process_delete(std::stack<PROCESS_INFORMATION*>* processes)
//{
//	PROCESS_INFORMATION* pi = (*processes).top();
//	TerminateProcess((*pi).hProcess, 1);
//	CloseHandle((*pi).hProcess);
//	(*processes).pop();
//
//}