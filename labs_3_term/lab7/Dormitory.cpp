#include "Dormitory.hpp"



Dormitory::Dormitory()
{
}

Dormitory::Dormitory(int number, std::string street, int numberOfApartments, bool isAdmittedToStudents) 
	: BlockOfFlats(number, street, numberOfApartments), 
	House(number, street),
	isAdmittedToStudents(isAdmittedToStudents)
{
	rate = 0.5;
}




Dormitory::~Dormitory()
{
}

void Dormitory::Show()
{
	BlockOfFlats::Show();
	std::cout << "Dormitory for students: " << std::boolalpha << this->isAdmittedToStudents << std::endl;
}

	