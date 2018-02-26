#pragma once
#include <string>

class CoffeeSort
{
	int water_for_recipe;
	int coffee_for_recipe;
	int milk_for_recipe;
	int whipped_milk_for_recipe;
	int honey_for_recipe;
	int price;
	std::string name;

public:
	CoffeeSort(int water_for_recipe,
		int coffee_for_recipe,
		int milk_for_recipe,
		int whipped_milk_for_recipe,
		int honey_for_recipe,
		int price,
		std::string name);

	int get_water_for_recipe() const;
	int get_coffee_for_recipe() const;
	int get_milk_for_recipe() const;
	int get_whipped_milk_for_recipe() const;
	int get_honey_for_recipe() const;
	int get_price() const;
	std::string get_name() const;

	~CoffeeSort();
};

