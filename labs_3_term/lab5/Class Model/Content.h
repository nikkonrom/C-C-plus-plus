///////////////////////////////////////////////////////////
//  Content.h
//  Implementation of the Class Content
//  Created on:      16-окт.-2017 18:32:48
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_705D153C_8A87_4244_8997_C05884A23428__INCLUDED_)
#define EA_705D153C_8A87_4244_8997_C05884A23428__INCLUDED_

#include "IShowable.h"
#include <string>

class Content : public IShowable
{

public:
	Content();
	Content(int ageLimit, bool censorshipNeed, std::string type);
	virtual ~Content();

	void Show();

protected:
	int ageLimit;
	bool censorshipNeed;
	std::string type;

};
#endif // !defined(EA_705D153C_8A87_4244_8997_C05884A23428__INCLUDED_)
