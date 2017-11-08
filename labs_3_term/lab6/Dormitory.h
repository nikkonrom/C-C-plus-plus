#pragma once
#include "BlockOfFlats.h"
class Dormitory :
	public virtual BlockOfFlats
{
public:
	Dormitory();
	Dormitory(int number, std::string street, int numberOfApartments, bool isAdmittedToStudents);
	~Dormitory();
	virtual void Show();
protected:
	bool isAdmittedToStudents;
};

