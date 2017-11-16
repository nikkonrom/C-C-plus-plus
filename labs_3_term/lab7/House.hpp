#pragma once

#include <string>
#include "IShowable.hpp"
#include "IRateable.hpp"

class House : public IShowable, public IRateable
{
public:
	House();
	House(int number, std::string street);
	virtual void Show() override;
	virtual void DisplayRate() override;
	~House();
protected:
	void DisplayEnterString();
	int number;
	double rate;
	std::string street;
};

