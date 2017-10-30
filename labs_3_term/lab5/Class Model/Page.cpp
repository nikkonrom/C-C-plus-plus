///////////////////////////////////////////////////////////
//  Page.cpp
//  Implementation of the Class Page
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#include "Page.h"


Page::Page(int linesCount)
{
	this->linesCount = linesCount;
	this->source = new std::string[this->linesCount];
}

Page::Page()
{
	this->linesCount = 0;
	this->source = NULL;
}

Page::~Page() {
	delete[] this->source;
}


void Page::Show() {
	for (int i = 0; i < this->linesCount; i++)
	{
		std::cout << i << ". " << this->source[i] << std::endl;
	}
}