#pragma once
#include <string>
#include "CoffeeSort.h"
#include <vector>


class CoffeeMachine
{
	int balance;
	int water;
	int coffee;
	int milk;
	int whipped_milk;
	int honey;
	std::vector<CoffeeSort> available_sorts;

public:
	CoffeeMachine();

	int get_balance() const;
	void add_money(int amount);
	bool check_money(CoffeeSort item) const;

	std::string make_coffee(CoffeeSort item);
	bool make_espresso();
	~CoffeeMachine();
};

