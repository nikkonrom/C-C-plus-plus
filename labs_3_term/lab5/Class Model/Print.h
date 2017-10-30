///////////////////////////////////////////////////////////
//  Print.h
//  Implementation of the Class Print
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_B2DD1234_778E_40f7_A783_E64F01441841__INCLUDED_)
#define EA_B2DD1234_778E_40f7_A783_E64F01441841__INCLUDED_
#pragma once
#include "Content.h"
#include "IShowable.h"
#include "Author.h"
#include "Publisher.h"

class Print : public IShowable
{

public:

	Print(Author author, Publisher publisher, Content content);
	Print();
	virtual ~Print();
	

	void Show();

protected:
	Content content;
	Author author;
	Publisher publisher;

};
#endif // !defined(EA_B2DD1234_778E_40f7_A783_E64F01441841__INCLUDED_)
;