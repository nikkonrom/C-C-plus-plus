#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include "CoffeeMachine.h"


using namespace std;

void insert_money_menu(CoffeeMachine & machine);
void choose_drink_menu(CoffeeMachine & machine);

int main()
{
	CoffeeMachine machine{};


	while (true)
	{
		system("cls");
		cout << "!!!ATTENTION!!! The machine does not give up!" << endl;
		cout << "Money amount: " << machine.get_balance() / 100 << " rubles " << machine.get_balance() % 100 << " kopecks" << endl;
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
			break;
		}
		case 50:
		{

			choose_drink_menu(machine);

			break;
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
		cout << "Money amount: " << machine.get_balance() / 100 << " rubles " << machine.get_balance() % 100 << 
			" kopecks" << endl;
		cout << "Type \"NrMk\" to insert N rubles and M kopecks into machine" << endl;
		cout << "Type \"0\" to end insertion" << endl;
		int rubles = 0, kopecks = 0;
		int state = scanf_s("%dr%dk", &rubles, &kopecks);
		if (rubles == 0 && kopecks == 0)
			break;
		machine.add_money(rubles * 100 + kopecks);
	}

}

void choose_drink_menu(CoffeeMachine & machine)
{
	while (true)
	{
		system("cls");
		cout << "Press a numeric key, corresponding to the drink" << endl;
		int counter = 0;
		for (const CoffeeSort& available_sort : machine.get_available_sorts())
		{
			cout << ++counter << ". " << available_sort.get_name() << " - " << available_sort.get_price() / 100 <<
				" rubles " << available_sort.get_price() % 100 << " kopecks" << endl;
		}
		int key = _getch() - 49;
		if (key >= 0 && key <= machine.get_available_sorts().size() - 1)
		{
			system("cls");
			cout << machine.make_coffee(machine.get_available_sorts()[key]) << endl;
			system("pause");
			return;
		}


	}
}
