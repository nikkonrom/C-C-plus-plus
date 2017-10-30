///////////////////////////////////////////////////////////
//  Page.h
//  Implementation of the Class Page
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_63787513_2B32_4516_B812_C92D79EA22DD__INCLUDED_)
#define EA_63787513_2B32_4516_B812_C92D79EA22DD__INCLUDED_

#include "IShowable.h"
#include <string>

class Page : public IShowable
{

public:
	Page(int linesCount);
	Page();
	virtual ~Page();

	void Show();

private:
	int linesCount;
	std::string* source;

};
#endif // !defined(EA_63787513_2B32_4516_B812_C92D79EA22DD__INCLUDED_)
