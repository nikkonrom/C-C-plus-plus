#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "VkPerson.h"

//int validateInput(int n) {
//	char buf[BUFSIZ];
//	char junk;
//	int number, key;
//	bool ok = false;
//
//
//	while (!ok)
//	{
//		fputs("Please, enter a number of person, you want to remove from the list: ", stdout);
//		fflush(stdout);
//
//
//		if (fgets(buf, BUFSIZ, stdin) == NULL)
//		{
//			if (!ferror(stdin))
//			{
//				fputs("No input available\n", stderr);
//
//			}
//			else
//			{
//				perror("stdin");
//				clearerr(stdin);
//				continue;
//			}
//		}
//
//
//		if (sscanf(buf, "%d %c\n", &number, &junk) != 1 && number <= n && number > 0)
//		{
//			system("cls");
//			fputs("Incorrect input\n", stderr);
//			continue;
//		}
//
//		ok = true;
//	}
//
//	return(number);
//}

int validateInput(int n) {
	int number = 0;
	int detection = 0;
	do {
		system("cls");
		printf("Please, enter a number of person, you want to remove from the list: ");
		rewind(stdin);
		detection = scanf("%d", &number);

	} while (number < 1 || !detection);

	return number;
}

int InitializeMenu(VkList* list) {
	system("cls");
	int key;
	puts("Press \"1\" to initialize the list from file");
	puts("Press \"2\" to initialize the list with keyboard");

	do {
		key = _getch();
	} while (key != 49 && key != 50);

	switch (key) {
	case 49:
		system("cls");
		if (int k = InitListFromFile(list)) {

			switch (k) {
			case 1:
				system("cls");
				puts("ERROR: Unable to allocate memory. Error code: 1");
				
				return 1;
			case 2:
				system("cls");
				puts("ERROR: Cannot open a file. Error code: 2");
				
				return 2;
			case 3:
				system("cls");
				puts("ERROR: Wrong id or empty file. Error code: 3");
				
				return 3;
			}
		}
		break;
	case 50:
		system("cls");
		if (int k = AddPerson(list))
			switch (k) {
			case 1:
				system("cls");
				puts("ERROR: Unable to allocate memory. Error code: 1");
				free(list->array_of_people);
				return 1;
			case 2:
				system("cls");
				puts("ERROR: Wrong id. Error code: 2");
				free(list->array_of_people);
				return 2;
			}
		break;
	}
}

int SortMenu(VkList list) {
	int key;
	puts("Press \"1\" to sort the list of persons by it's name");
	puts("Press \"2\" to sort the list of persons by it's date of birth");
	puts("Press \"3\" to sort the list of persons by it's activity");
	puts("Press \"4\" to sort the list of persons by it's number");
	do {
		key = _getch();
	} while (key != 49 && key != 50 && key != 51 && key != 52);



	switch (key) {
	case 49:
		system("cls");
		SortListByName(list);
		break;
	case 50:
		system("cls");
		SortListByDate(list);
		break;

	case 51:
		system("cls");
		SortListByActivity(list);
		break;
	case 52:
		system("cls");
		SortListByNumber(list);
		break; 

	}

	puts("Sorting succeed");
	return 0;
}

int MainMenu(VkList * list) {
	int key;
	system("cls");
	puts("Press \"1\" to add a person to the list");
	puts("Press \"2\" to output the list");
	puts("Press \"3\" to sort the list");
	//puts("Press \"4\" to search profiles in the list");
	puts("Press \"4\" to delete person profile from the list");
	puts("Press \"Backspace\" to exit the program");
	do {
		key = _getch();
	} while (key != 49 && key != 50 && key != 51 && key != 52 && key != 8);

	int delete_instance;

	switch (key) {
	case 49:
		system("cls");
		if (int k = AddPerson(list)) {
			switch (k) {
			case 1:
				puts("ERROR: Unable to allocate memory. Error code: 1");
				free(list->array_of_people);
				return 1;
			case 2:
				puts("ERROR: Wrong id. Error code: 2");
				free(list->array_of_people);
				return 2;
			}
		}
		break;
	case 50:
		system("cls");
		OutputList(*list);
		puts("Press \"Backspace\" to go back");
		do {
			key = _getch();
		} while (key != 8);
		break;
	case 51:
		system("cls");
		SortMenu(*list);
		puts("Press \"Backspace\" to go back");
		do {
			key = _getch();
		} while (key != 8);
		break;
	case 52:
		system("cls");
		delete_instance = DeleteStruct(list, validateInput(list->count_of_people));
		if (delete_instance == 1)
			puts("Remove error: empty array");
		else if ((delete_instance == 2))
			puts("Remove error: no such struct in array");
		else
			puts("Removal succeed");
		puts("Press \"Backspace\" to go back");
		do {
			key = _getch();
		} while (key != 8);
		break;
	case 8:
		return 0;
	}
	MainMenu(list);
}