///////////////////////////////////////////////////////////
//  Structure.h
//  Implementation of the Class Structure
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_DD2EB672_296B_4f43_A3A0_80F14A6A4921__INCLUDED_)
#define EA_DD2EB672_296B_4f43_A3A0_80F14A6A4921__INCLUDED_

#include "Binding.h"
#include "IShowable.h"

class Book;

class Structure : public IShowable
{

public:
	Structure();
	Structure(Binding typeOfBinding, int countOfPages, int linesInPageCount);
	virtual ~Structure();
	friend class Book;

	void Show();

private:
	int countOfPages;
	int linesInPageCount;
	Binding typeOfBinding;

};
#endif // !defined(EA_DD2EB672_296B_4f43_A3A0_80F14A6A4921__INCLUDED_)
