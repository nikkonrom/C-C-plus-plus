#pragma once

#include <string>
#include "IShowable.h"

class House : public IShowable
{
public:
	House();
	House(int number, std::string street);
	virtual void Show();
	~House();
protected:
	int number;
	std::string street;
};

