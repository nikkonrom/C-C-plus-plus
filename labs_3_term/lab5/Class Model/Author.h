///////////////////////////////////////////////////////////
//  Author.h
//  Implementation of the Class Author
//  Created on:      16-окт.-2017 18:32:48
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_492C969A_5609_4ee6_A14F_149A568DC054__INCLUDED_)
#define EA_492C969A_5609_4ee6_A14F_149A568DC054__INCLUDED_

#include "IShowable.h"
#include <string>

class Author : public IShowable
{

public:
	Author(std::string name, bool publishingMembership);
	Author();
	virtual ~Author();

	void Show();

private:
	std::string name;
	bool publishingMembership;

};
#endif // !defined(EA_492C969A_5609_4ee6_A14F_149A568DC054__INCLUDED_)
