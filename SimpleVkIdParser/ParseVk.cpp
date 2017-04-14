#include "ParseVk.h"
#include <regex>
#include <stdio.h>
#include <windows.h>
#include <wininet.h>
#pragma comment(lib,"wininet")
#include <Tlhelp32.h>

using namespace std;

#define PAGE_NAME "page.html"
#define MAX_LINE 400

wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

char* VkIdToHTML(char* id) {
	char* file_name = PAGE_NAME;
	wchar_t * text_id = convertCharArrayToLPCWSTR(id);
	bool ok = false;
	// инициализация WinInet
	HINTERNET hInternet =
		InternetOpen(
			TEXT("WinInet Test"),
			INTERNET_OPEN_TYPE_PRECONFIG,
			NULL, NULL,
			0);
	if (hInternet != NULL) {
		// открытие HTTP сессии
		HINTERNET hConnect =
			InternetConnect(
				hInternet,
				TEXT("www.m.vk.com"),
				INTERNET_DEFAULT_HTTP_PORT,
				NULL, NULL,
				INTERNET_SERVICE_HTTP,
				0,
				1u);
		if (hConnect != NULL) {
			// открытие запроса
			HINTERNET hRequest =
				HttpOpenRequest(
					hConnect,
					TEXT("GET"),
					text_id,
					NULL,
					NULL,
					0,
					INTERNET_FLAG_KEEP_CONNECTION,
					1);
			if (hRequest != NULL) {
				// посылка запроса
				BOOL bSend = HttpSendRequest(hRequest, NULL, 0, NULL, 0);
				if (bSend) {
					// создание выходного файла
					FILE *f;
					f = fopen(file_name, "w");

					if (f) for (;;) {
						// считывание данных
						char  szData[1024];
						DWORD dwBytesRead;
						BOOL bRead =
							InternetReadFile(
								hRequest,
								szData, sizeof(szData) - 1,
								&dwBytesRead);
						// выход из цикла при ошибке или завершении
						if (bRead == FALSE || dwBytesRead == 0)
							break;
						// сохранение результата
						szData[dwBytesRead] = 0;
						fprintf(f, "%s", szData);

						ok = true;
					}
					fclose(f);
				}
				// закрытие запроса
				InternetCloseHandle(hRequest);
			}
			// закрытие сессии
			InternetCloseHandle(hConnect);
		}
		// закрытие WinInet'a
		InternetCloseHandle(hInternet);
	}

	// для полного счастья проверяем, правильно ли всё отработало
	if (ok)
		return file_name;
	else
		return '\0';
}

int Parse(char* file_name, char** name, char** date, char** city, char** university, char** activity) {
	FILE *f;
	char file_str[MAX_LINE];

	if (file_name) {
		f = fopen(file_name, "r");
		
	}
	else
		return 1;

	bool check;
	do {
		fgets(file_str, MAX_LINE, f);
		if (*name == nullptr)
			*name = ParseName(file_str);

		if (*date == nullptr)
			*date = ParseBirthDate(file_str);

		if (*city == nullptr)
			*city = ParseCity(file_str);

		if (*university == nullptr)
			*university = ParseUniversity(file_str);

		if (*activity == nullptr)
			*activity = ParseActivity(file_str);

		check = *name && * date && *city && *university && *activity ? true : false;

	} while (!feof(f) && !check);


	fclose(f);
	return 0;
}

char* ParseName(char* file_str) {
	regex regex_name("(<title>)(.+?)(</title>)");
	cmatch result;
	regex_search(file_str, result, regex_name);
	if (result[0] != "\0") {
		char* name = (char*)malloc(50);
		strcpy(name, result.str(2).c_str());
		return name;
	}
	else
		return nullptr;
}

char* ParseBirthDate(char* file_str) {
	regex regex_name("(<dt>).{26}(</dt><dd>)(.+?)(</dd>)");
	cmatch result;
	regex_search(file_str, result, regex_name);
	if (result[0] != "\0") {
		char* date = (char*)malloc(50);
		strcpy(date, result.str(3).c_str());
		return date;
	}
	else
		return nullptr;
}

char* ParseCity(char* file_str) {
	regex regex_city("(<div class=\"pp_info\">)(.+?)(</div>)");
	cmatch result;
	regex_search(file_str, result, regex_city);
	if (result[0] != "\0") {
		char* city = (char*)malloc(50);
		strcpy(city, result.str(2).c_str());
		return city;
	}
	else
		return nullptr;
}

char* ParseUniversity(char* file_str) {
	regex regex_university("(<dt>.{22}</dt><dd>)(.+?)(</dd>)");
	cmatch result;
	regex_search(file_str, result, regex_university);
	if (result[0] != "\0") {
		char* university = (char*)malloc(50);
		strcpy(university, result.str(2).c_str());
		return university;
	}
	else
		return nullptr;
}

char* ParseActivity(char* file_str) {
	regex regex_activity("(<div class=\"pp_last_activity\">)(.+?)(<)");
	cmatch result;
	regex_search(file_str, result, regex_activity);
	if (result[0] != "\0") {
		char* activity = (char*)malloc(50);
		strcpy(activity, result.str(2).c_str());
		return activity;
	}
	else
		return nullptr;
}
