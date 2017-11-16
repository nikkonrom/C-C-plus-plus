#include "StudentsHouse.hpp"

StudentsHouse::StudentsHouse()
{
}

StudentsHouse::StudentsHouse(int number, std::string street, double yardSquare,
	int numberOfApaprtments, bool isAdmittedToStudents, Facade facade, std::string timetable)
	: House(number, street),
	Fachwerk(number, street, yardSquare, facade),
	Dormitory(number, street, numberOfApaprtments, isAdmittedToStudents), timetable(timetable)
{
	rate = 0.45;
}

StudentsHouse::~StudentsHouse()
{
}

void StudentsHouse::Show()
{
	Fachwerk::Show();
	Dormitory::Show();
	
}
