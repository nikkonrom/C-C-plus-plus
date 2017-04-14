#include "VkPerson.h"
#include "ParseVk.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#define FILE_NAME "id.txt"
#define ID_LINE 20

void DeleteNewLine(char* ptr) {

	for (int i = 0; *ptr != '\n' && i < 20; i++)
		ptr++;
	*ptr = '\0';
}

int InitStruct(VkPerson* person, char* id, int number) {
	person->number = number;
	person->name = nullptr;
	person->activity = nullptr;
	person->city = nullptr;
	person->date = nullptr;
	person->university = nullptr;
	person->id = id;

	Parse(VkIdToHTML(id), &(person->name), &(person->date), &(person->city), &(person->university), &(person->activity));
	if (strstr(person->name, u8"403") || strstr(person->name, u8"ћобильна€") || strstr(person->name, u8"404"))
		return 1;
	if (person->date != nullptr)
		CreateNumericDate(person);
	return 0;
}

int InitListFromFile(VkList* list) {

	list->array_of_people = nullptr;
	list->count_of_people = 0;

	FILE* f;
	f = fopen(FILE_NAME, "r");
	if (f == nullptr)
		return 2;

	list->array_of_people = (VkPerson*)malloc(sizeof(VkPerson));
	if (list->array_of_people == nullptr)
		return 1;

	int index;
	char text_line[ID_LINE];
	for (index = 0;; index++) {
		fgets(text_line, ID_LINE, f);
		if (text_line != "\0") {
			DeleteNewLine(text_line);
			if (InitStruct(&(list->array_of_people)[index], text_line, index + 1)) {
				free(list->array_of_people);
				return 3;
			}

		}
		if (feof(f))
			break;
		list->array_of_people = (VkPerson*)realloc(list->array_of_people, sizeof(VkPerson) * (index + 2));
	}
	list->count_of_people = index + 1;
	fclose(f);
	return 0;
}

int AddPerson(VkList* list) {
	puts("Please, ented a VK id of a person, you want to add to the list");
	char id[ID_LINE];
	fgets(id, ID_LINE, stdin);


	list->count_of_people++;
	VkPerson* new_array = (VkPerson*)malloc(list->count_of_people * sizeof(VkPerson));
	if (new_array == nullptr) return 1;

	if (InitStruct(&(new_array[list->count_of_people - 1]), id, list->count_of_people)) {
		//new_array = (VkPerson*)realloc()
		//free(&(list->array_of_people[list->count_of_people - 1]));
		free(new_array);
		return 2;
	}
	for (int i = 0; i < list->count_of_people - 1; i++)
	{
		new_array[i] = list->array_of_people[i];
	}
	if (list->array_of_people != nullptr) free(list->array_of_people);
	list->array_of_people = new_array;

	return 0;
}

void OutputStruct(VkPerson person) {
	printf("Person #%d\n%s\n%s\n%s\n%s\n%s\n", person.number, person.name, person.date, person.city, person.university, person.activity);
	printf("\n\n\n");
}

void OutputList(VkList list) {
	if (list.array_of_people == nullptr) {
		puts("Array is empty");
		return;
	}


	for (int i = 0; i < list.count_of_people; i++) {
		OutputStruct(list.array_of_people[i]);
	}
}

void SortListByName(VkList list) {
	for (int i = list.count_of_people - 1; i > 0; i--) {
		for (int j = 0; j < list.count_of_people - 1; j++) {
			if (strcmp(list.array_of_people[j].name, list.array_of_people[j + 1].name) >= 0) {
				VkPerson temp;
				temp = list.array_of_people[j];
				list.array_of_people[j] = list.array_of_people[j + 1];
				list.array_of_people[j + 1] = temp;
			}
		}
	}
}

void SortListByNumber(VkList list) {
	for (int i = list.count_of_people - 1; i > 0; i--) {
		for (int j = 0; j < list.count_of_people - 1; j++) {
			if (list.array_of_people[j].number > list.array_of_people[j+1].number) {
				VkPerson temp;
				temp = list.array_of_people[j];
				list.array_of_people[j] = list.array_of_people[j + 1];
				list.array_of_people[j + 1] = temp;
			}
		}
	}
}

void SortListByDate(VkList list) {
	for (int i = list.count_of_people - 1; i > 0; i--) {
		for (int j = 0; j < list.count_of_people - 1; j++) {
			if (list.array_of_people[j].month_of_birth > list.array_of_people[j + 1].month_of_birth) {
				VkPerson temp;
				temp = list.array_of_people[j];
				list.array_of_people[j] = list.array_of_people[j + 1];
				list.array_of_people[j + 1] = temp;
			}
			if (list.array_of_people[j].month_of_birth == list.array_of_people[j + 1].month_of_birth) {
				if (list.array_of_people[j].date_of_birth > list.array_of_people[j + 1].date_of_birth) {
					VkPerson temp;
					temp = list.array_of_people[j];
					list.array_of_people[j] = list.array_of_people[j + 1];
					list.array_of_people[j + 1] = temp;
				}
			}
		}
	}
}

void SortListByActivity(VkList list)
{
	for (int i = list.count_of_people - 1; i > 0; i--) {
		for (int j = 0; j < list.count_of_people - 1; j++) {
			int first_fiel_priority = 0, second_field_priority = 0;
			if (list.array_of_people[j].activity) {
				first_fiel_priority = 1;
				if (strstr(list.array_of_people[j].activity, u8"Online"))
					first_fiel_priority = 2;
			}
			if (list.array_of_people[j + 1].activity) {
				second_field_priority = 1;
				if (strstr(list.array_of_people[j+1].activity, u8"Online"))
					second_field_priority = 2;
			}
			if (first_fiel_priority > second_field_priority) {
				VkPerson temp;
				temp = list.array_of_people[j];
				list.array_of_people[j] = list.array_of_people[j + 1];
				list.array_of_people[j + 1] = temp;
			}
		}
	}
}

int DeleteStruct(VkList * list, int n)
{
	if (list->count_of_people == 0)
		return 1;
	if (list->count_of_people < n)
		return 2;
	--n;
	for (int i = n; i < list->count_of_people - 1; i++)
	{
		int num_temp;
		num_temp = list->array_of_people[i].number;
		list->array_of_people[i].number = list->array_of_people[i + 1].number;
		list->array_of_people[i + 1].number = num_temp;
		VkPerson temp;
		temp = list->array_of_people[i];
		list->array_of_people[i] = list->array_of_people[i + 1];
		list->array_of_people[i + 1] = temp;

	}
	list->array_of_people = (VkPerson*)realloc(list->array_of_people, sizeof(VkPerson) * --list->count_of_people);

	return 0;
}

void CreateNumericDate(VkPerson* person) {
	char buf_temp[2];

	if (strstr(person->date, u8"€нвар€"))
		person->month_of_birth = JANUARY;
	if (strstr(person->date, u8"феврал€"))
		person->month_of_birth = FEBRUARY;
	if (strstr(person->date, u8"марта"))
		person->month_of_birth = MARCH;
	if (strstr(person->date, u8"апрел€"))
		person->month_of_birth = APRIL;
	if (strstr(person->date, u8"ма€"))
		person->month_of_birth = MAY;
	if (strstr(person->date, u8"июн€"))
		person->month_of_birth = JUNE;
	if (strstr(person->date, u8"июл€"))
		person->month_of_birth = JULY;
	if (strstr(person->date, u8"августа"))
		person->month_of_birth = AUGUST;
	if (strstr(person->date, u8"сент€бр€"))
		person->month_of_birth = SEPTEMBER;
	if (strstr(person->date, u8"окт€бр€"))
		person->month_of_birth = OCTOBER;
	if (strstr(person->date, u8"но€бр€"))
		person->month_of_birth = NOVEMBER;
	if (strstr(person->date, u8"декабр€"))
		person->month_of_birth = DECEMBER;

	buf_temp[0] = *(person->date);
	buf_temp[1] = *(person->date + 1);
	person->date_of_birth = atoi(buf_temp);


}