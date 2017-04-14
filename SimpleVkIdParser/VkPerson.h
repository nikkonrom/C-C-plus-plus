#pragma once

enum Month {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

struct VkPerson
{
	int number;
	char* name;
	char* id;
	char* date;
	char* city;
	char* university;
	char* activity;
	Month month_of_birth;
	int date_of_birth;
};

struct  VkList
{
	VkPerson* array_of_people = nullptr;
	int count_of_people = 0;
};

int InitStruct(VkPerson* person, char* id); 
int InitListFromFile(VkList* list);
int AddPerson(VkList* list);
void OutputStruct(VkPerson*);
void OutputList(VkList list);
void SortListByName(VkList list);
void SortListByNumber(VkList list);
void CreateNumericDate(VkPerson* person);
void SortListByDate(VkList list);
void SortListByActivity(VkList list);
int DeleteStruct(VkList *list, int n);