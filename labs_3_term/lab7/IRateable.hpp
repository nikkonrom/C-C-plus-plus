#pragma once
class IRateable
{
public:

	virtual void DisplayRate() = 0;

	IRateable();
	virtual ~IRateable();
};

