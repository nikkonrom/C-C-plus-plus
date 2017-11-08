#include "StudentsHouse.h"

StudentsHouse::StudentsHouse()
{
}

StudentsHouse::StudentsHouse(int number, std::string street, double yardSquare,
	int numberOfApaprtments, bool isAdmittedToStudents, Facade facade, std::string timetable)
	: Fachwerk::Fachwerk(number, street, yardSquare, facade),
	Dormitory::Dormitory(number, street, numberOfApaprtments, isAdmittedToStudents), timetable(timetable)
{
}

StudentsHouse::~StudentsHouse()
{
}
