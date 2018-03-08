// Romaniuk, 650504, 16 variant
// F(x) = sin(x)/( x2+10)

#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
T fromString(const std::string& s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}

bool check(string s)
{
	int n = s.length();
	int countpoint = 0;
	for (int i = 0; i < n; i++) {

		if (s[i] == '.') {
			countpoint++;
		}
		else if ((s[i] > '9') || (s[i] < '0')) {
			return false;
		}

		if (countpoint > 1) {
			return false;
		}
	}
	return true;
}

double saferead(int opt)
{
	bool nsfrd = true; //no safe read
	string strTemp;
	double ans;
	do {
		nsfrd = false;
		switch (opt)
		{
		case 1: {
			cout << "Write start of interval(a) - ";
			break;
		}
		case 2: {
			cout << "Write finish of interval(b) - ";
			break;
		}
		case 3: {
			cout << "Write step(d) - ";
			break;
		}
		default: {
			cout << "Strange information. Next information must be wrong";
			return 1;
		}
		}
		cin >> strTemp;
		if (check(strTemp)) {
			ans = fromString<double>(strTemp);
		}
		else {
			cout << "WRONG INFORMATION. Please, write number again" << endl;
			nsfrd = true;
		}
	} while (nsfrd);
	return ans;
}

int main()
{
	bool rpt = true;
	do {
		system("cls");
		string strTemp;
		double a; //старт интервала
		double b; //окончание интервала
		double d; //шаг
		double count; //count = x - аргумент 

		double starting, finishing, time; //для подсчёта времени выполнения

		a = saferead(1);
		b = saferead(2);
		d = saferead(3);

		count = a;
		cout << "Answer for function without assembler" << endl;
		starting = clock();
		double ans;
		while (count <= b) {		//цикл для подсчёта без ассемблера
			ans = sin(count) / (count*count + 10.0);
			count += d;
		}
		finishing = clock();
		cout << "The last resault: F(" << count - d << ") = " << ans << endl;
		time = (finishing - starting) / 1000;
		cout << "Time for cycle without assembler - " << time << " ms" << endl;

		count = a;
		cout << "Answer for function with assembler" << endl;
		double cc = 10.0;
		starting = clock();


		_asm finit
		while (count <= b) {		//Цикл для подсчёта без ассемблера.			
			_asm {

				fld count // Загрузка аргумента в стек.
				fld count // Загрузка аргумента в стек.
				fmul // Перемножение аргумента с самим собой (x^2).
				fadd cc // Загрузка в стек числовой константы и сложение с послденим элементом стека.


				fld count // Загрузка аргумента в стек.
				fsin // Применение операции синуса к аргументу в стеке.

				fdivr // Осуществление обратного деления элементов стека.
				
				fstp ans // Выгрузка резутьтата в переменную ans.

			}
			count += d;
		}
		_asm fwait


		finishing = clock();

		cout << " The last result: F(" << count - d << ") = " << ans << endl;
		time = (finishing - starting) / 1000;
		cout << "Time for cycle with assembler - " << time << " ms" << endl;

		int i;
		cout << "Do you wont repeat that?(0-no/1-yes)";
		cin >> i;
		rpt = i != 0;

	} while (rpt);
}