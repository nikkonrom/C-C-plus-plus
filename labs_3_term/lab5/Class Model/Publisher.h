///////////////////////////////////////////////////////////
//  Publisher.h
//  Implementation of the Class Publisher
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_DECDE405_FB28_43a8_857C_C36BD3BE2521__INCLUDED_)
#define EA_DECDE405_FB28_43a8_857C_C36BD3BE2521__INCLUDED_

#include "IShowable.h"
#include <string>
class Publisher : public IShowable
{

public:
	Publisher(std::string name, std::string organization);
	Publisher();
	virtual ~Publisher();

	void Show();

private:
	std::string name;
	std::string organization;

};
#endif // !defined(EA_DECDE405_FB28_43a8_857C_C36BD3BE2521__INCLUDED_)
