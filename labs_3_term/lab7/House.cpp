#include "House.hpp"


House::House()
{
}

House::House(int number, std::string street) : number(number), street(street)
{
	rate = 1.00;
}

void House::Show() {
	std::cout << "Number of house: " << this->number << std::endl << "Street: " << this->street << std::endl;
}


void House::DisplayRate()
{
	DisplayEnterString();
	std::cout << this->rate << std::endl;
}


House::~House()
{
}

void House::DisplayEnterString()
{
	std::cout << "Tariff rate for the current building type: ";
}
