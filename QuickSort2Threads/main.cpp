#include <windows.h>
#include <stdio.h>
#include <time.h>

#define THREADS_NUMBER 2
#define PAUSE 10 /* ms */

DWORD* array;

struct ALLData {
	HANDLE hMutex;
	DWORD lowBorder, upBorder;
};

void sortQuick(DWORD* array, int begin, int size) {
	int index_left, index_right, intermidate_number;
	index_left = begin;
	index_right = size;
	int middle_element = array[(size + begin) / 2];
	do {
		while (array[index_left] < middle_element)
			index_left++;
		while (array[index_right] > middle_element)
			index_right--;
		if (index_left <= index_right) {
			intermidate_number = array[index_left];
			array[index_left] = array[index_right];
			array[index_right] = intermidate_number;
			index_left++;
			index_right--;
		}
	} while (index_left <= index_right);
	if (index_left < size)
		sortQuick(array, index_left, size);
	if (index_right > begin)
		sortQuick(array, begin, index_right);

	return;
}

void merge(DWORD* a, int n) {
	int ptr1, ptr2, write_position = 0, middle;
	int* c;
	c = (int*)malloc((n) * sizeof(int));

	ptr1 = 0;
	ptr2 = middle = n % 2 == 0 ? n / 2 : n / 2 + 1;

	while (true) {
		if (ptr1 < middle && ptr2 < n) {
			int temp;
			if (a[ptr1] < a[ptr2]) {
				temp = a[ptr1];
				ptr1++;
			}
			else {
				temp = a[ptr2];
				ptr2++;
			}
			c[write_position] = temp;
			write_position++;
		}

		else if (ptr1 < middle) {
			c[write_position] = a[ptr1];
			write_position++;
			ptr1++;
		}
		else if (ptr2 < n) {
			c[write_position] = a[ptr2];
			write_position++;
			ptr2++;
		}
		else
			break;
	}

	for (int counter = 0; counter < n; counter++)
		a[counter] = c[counter];

	free(c);
}


DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{

	CONST ALLData* Local = (ALLData*)lpParam;
		
	WaitForSingleObject(Local->hMutex, INFINITE);
	
	sortQuick(array, Local->lowBorder, Local->upBorder);
	

	ReleaseMutex(Local->hMutex);
	Sleep(PAUSE);
	
	
	ExitThread(0);
}

VOID Error(CONST HANDLE hStdOut, CONST LPCWSTR szMessage) {
	DWORD dwTemp;
	TCHAR szError[256];
	WriteConsole(hStdOut, szMessage, lstrlen(szMessage), &dwTemp, NULL);
	wsprintf(szError, TEXT("LastError = %d\r\n"), GetLastError());
	WriteConsole(hStdOut, szError, lstrlen(szError), &dwTemp, NULL);
	ExitProcess(0);
}

INT main() {
	TCHAR szMessage[256];
	DWORD dwTemp, i, elements;
	HANDLE hThreads[THREADS_NUMBER];
	CONST HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


	printf("Please, enter a count of numbers in the array:\t");
	scanf("%d", &elements);

	array = (DWORD*)malloc(elements * sizeof(DWORD));
	srand(6);
	for (int index = 0; index < elements; index++)
		array[index] = 1 + rand() % 1000;


	struct ALLData Data[THREADS_NUMBER];
	
	DWORD startTime, endTime;
	startTime = clock();

	for (i = 0; i < THREADS_NUMBER; i++)
	{		
		Data[i].hMutex = CreateMutex(NULL, FALSE, NULL);	
		Data[i].lowBorder = elements / THREADS_NUMBER * i;
		Data[i].upBorder = elements / THREADS_NUMBER * (i + 1) + 1;
		if (NULL == Data[i].hMutex) {
			Error(hStdOut, TEXT("Failed to create mutex.\r\n"));
		}

		hThreads[i] = CreateThread(NULL, 0, &ThreadProc, &Data[i], 0, NULL);

		if (NULL == hThreads[i]) {
			Error(hStdOut, TEXT("Failed to create thread.\r\n"));
		}
	}

	WaitForMultipleObjects(THREADS_NUMBER, hThreads, TRUE, INFINITE);
		
	merge(array, elements);

	endTime = clock();
	endTime -= startTime;


	/*for (int index = 0; index < elements; index++) 
	{
		wsprintf(szMessage, TEXT("Array[%d] = %d\r\n"), index, array[index]);
		WriteConsole(hStdOut, szMessage, lstrlen(szMessage), &dwTemp, NULL);
	}*/

	printf("Sort time:\t%d ms\n", endTime);


	for (i = 0; i < THREADS_NUMBER; i++)
	{
		CloseHandle(hThreads[i]);
		CloseHandle(Data[i].hMutex);
	}
	
	system("pause");
	ExitProcess(0);
}
