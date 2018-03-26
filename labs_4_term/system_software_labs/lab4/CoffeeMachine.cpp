#include "CoffeeMachine.h"



CoffeeMachine::CoffeeMachine()
{
	this->balance = 0;
	this->coffee = 2000 + rand() % 2000;
	this->water = 4000 + rand() % 2000;
	this->milk = 1000 + rand() % 2000;
	this->honey = 200 + rand() % 200;
	this->whipped_milk = 1500 + rand() % 1000;
	this->available_sorts.emplace_back(30, 20, 0, 0, 0, 100, "Espresso");
	this->available_sorts.emplace_back(30, 20, 30, 90, 0, 150, "Cappuccino");
	this->available_sorts.emplace_back(30, 20, 90, 30, 0, 200, "Latte");
	this->available_sorts.emplace_back(30, 20, 90, 0, 0, 200, "Flat-White");
	this->available_sorts.emplace_back(240, 20, 0, 0, 0, 150, "Americano");
	this->available_sorts.emplace_back(30, 20, 0, 60, 30, 250, "Honey Raft");

}

int CoffeeMachine::get_balance() const
{
	return this->balance;
}

void CoffeeMachine::add_money(const int amount)
{
	this->balance += amount;
}

bool CoffeeMachine::check_money(const CoffeeSort& item) const
{
	return this->balance - item.get_price() >= 0;
}

std::vector<CoffeeSort> CoffeeMachine::get_available_sorts() const
{
	return this->available_sorts;
}

std::string CoffeeMachine::make_coffee(const CoffeeSort& item)
{
	if (check_money(item))
	{
		if (this->coffee - item.get_coffee_for_recipe() >= 0 && this->water - item.get_water_for_recipe() >= 0 &&
			this->milk - item.get_milk_for_recipe() >= 0 && this->whipped_milk - item.get_whipped_milk_for_recipe() >= 0 &&
			this->honey - item.get_honey_for_recipe() >= 0) {

			this->coffee -= item.get_coffee_for_recipe();
			this->water -= item.get_water_for_recipe();
			this->milk -= item.get_milk_for_recipe();
			this->whipped_milk -= item.get_whipped_milk_for_recipe();
			this->honey -= item.get_honey_for_recipe();

			this->balance -= item.get_price();
			return "Enjoy your " + item.get_name() + "! Have a good day :)";
		}
		return "Sorry, not enough products, please choose another sort :(";
	}
	return "Sorry, not enough money :(";

}




CoffeeMachine::~CoffeeMachine()
= default;
