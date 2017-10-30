///////////////////////////////////////////////////////////
//  BookContent.cpp
//  Implementation of the Class BookContent
//  Created on:      16-окт.-2017 18:32:48
//  Original author: Никита
///////////////////////////////////////////////////////////

#include "BookContent.h"


BookContent::BookContent() {

}



BookContent::BookContent(Content content, Cover cover, int pagesCount, int linesInPageCount) : Content(content),
cover(cover),
pagesCount(pagesCount) {

	this->pages = (Page*)operator new(sizeof(Page)*pagesCount);
	for (int i = 0; i < pagesCount; i++)
	{
		new (pages + i)(Page)(linesInPageCount);
	}
}

BookContent::~BookContent() {
	for (int i = 0; i < this->pagesCount; i++)
	{
		pages[i].~Page();
	}
	operator delete (pages);
}





void BookContent::Show() {
	Content::Show();

	this->cover.Show();

	for (int i = 0; i < pagesCount; i++)
	{
		std::cout << "Page " << i << ":" << std::endl;
		this->pages[i].Show();
	}
}