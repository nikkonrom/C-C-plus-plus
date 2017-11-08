#pragma once
#include "PrivateHouse.h"
#include "Facade.h"
class Fachwerk :
	public virtual PrivateHouse
{
public:
	Fachwerk();
	Fachwerk(int number, std::string street, double yardSquare, Facade facade);
	~Fachwerk();

	virtual void Show();
protected:
	Facade facade;
};

