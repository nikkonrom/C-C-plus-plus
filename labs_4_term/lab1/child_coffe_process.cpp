#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include "CoffeeMachine.h"


using namespace std;

void insert_money_menu(CoffeeMachine & machine);

int main()
{
	CoffeeMachine machine{};

	
	while(true)
	{
		system("cls");
		cout << "Money amount: " << machine.get_balance() << " kopecks";
		cout << "Press \"1\" to insert money" << endl;
		cout << "Press \"2\" to choose drink" << endl;
		cout << "Press \"Backspace\" to go destroy coffee machine" << endl;
		int key;
		do {
			key = _getch();
		} while (key != 49 && key != 50 && key != 8);
		switch (key)
		{
		case 49:
			{
			insert_money_menu(machine);
			}
		case 50:
			{
				
			}
		case 8:
			goto break_label;
		}
	}
	break_label:

	return 0;
}

void insert_money_menu(CoffeeMachine & machine)
{
	while (true)
	{
		system("cls");
		cout << "Money amount: " << machine.get_balance() << " kopecks";
		cout << "Type \"NrMk\" to insert N rubles and M kopecks into machine" << endl;
		cout << "Type \"0\" to end insertion" << endl;
		int rubles = 0, kopecks = 0;
		int state = scanf_s("%dr%dk", rubles, kopecks);
		if (!state)
			break;
		machine.add_money(rubles * 100 + kopecks);
	}
	
}
