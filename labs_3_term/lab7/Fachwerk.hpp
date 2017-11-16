#pragma once
#include "PrivateHouse.hpp"
#include "Facade.hpp"
class Fachwerk :
	public  PrivateHouse
{
public:
	Fachwerk();
	Fachwerk(int number, std::string street, double yardSquare, Facade facade);
	~Fachwerk();

	virtual void Show() override;
protected:
	Facade facade;
};

