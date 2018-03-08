#include "CoffeeSort.h"
#include <utility>



CoffeeSort::CoffeeSort(int water_for_recipe, int coffee_for_recipe, int milk_for_recipe, int whipped_milk_for_recipe,
	int honey_for_recipe, int price, std::string name) : water_for_recipe(water_for_recipe),
	coffee_for_recipe(coffee_for_recipe),
	milk_for_recipe(milk_for_recipe),
	whipped_milk_for_recipe(whipped_milk_for_recipe),
	honey_for_recipe(honey_for_recipe),
	price(price),
	name(std::move(name))
{
}


int CoffeeSort::get_water_for_recipe() const
{
	return this->coffee_for_recipe;
}

int CoffeeSort::get_coffee_for_recipe() const
{
	return this->coffee_for_recipe;
}

int CoffeeSort::get_milk_for_recipe() const
{
	return this->milk_for_recipe;
}

int CoffeeSort::get_whipped_milk_for_recipe() const
{
	return this->whipped_milk_for_recipe;
}

int CoffeeSort::get_honey_for_recipe() const
{
	return this->honey_for_recipe;
}

int CoffeeSort::get_price() const
{
	return this->price;
}

std::string CoffeeSort::get_name() const
{
	return this->name;
}

CoffeeSort::~CoffeeSort()
= default;
