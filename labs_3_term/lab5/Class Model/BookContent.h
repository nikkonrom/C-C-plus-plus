///////////////////////////////////////////////////////////
//  BookContent.h
//  Implementation of the Class BookContent
//  Created on:      16-окт.-2017 18:32:48
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_AA62A564_BCD7_45d0_AEE9_4F27BC96A604__INCLUDED_)
#define EA_AA62A564_BCD7_45d0_AEE9_4F27BC96A604__INCLUDED_

#include "Cover.h"
#include "Content.h"
#include "Page.h"

class BookContent : public Content
{

public:
	BookContent();
	//BookContent(BookContent & content);
	BookContent(Content content, Cover cover, int pagesCount, int linesInPageCount);
	virtual ~BookContent();
	void Show();

private:
	int pagesCount;
	Cover cover;
	Page* pages;

};
#endif // !defined(EA_AA62A564_BCD7_45d0_AEE9_4F27BC96A604__INCLUDED_)
