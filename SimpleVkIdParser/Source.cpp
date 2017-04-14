#include <stdio.h>
#include <windows.h>
#include "Menu.h"
#include <locale.h>

int main(int argc, char* argv[])
{
	setlocale(0, "LC_ALL");
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	VkList list;

	if (InitializeMenu(&list)) {
		system("pause");
		return 1;
	}
	if (MainMenu(&list)) {
		system("pause");
		return 2;
	}
	free(list.array_of_people);
	return 0;
}

