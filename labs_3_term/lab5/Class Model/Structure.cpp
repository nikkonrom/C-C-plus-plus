///////////////////////////////////////////////////////////
//  Structure.cpp
//  Implementation of the Class Structure
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#include "Structure.h"



Structure::Structure()
{
}

Structure::Structure(Binding typeOfBinding, int countOfPages, int linesInPageCount) : 
	typeOfBinding(typeOfBinding), countOfPages(countOfPages), linesInPageCount(linesInPageCount)
{
}

Structure::~Structure() {

}





void Structure::Show() {
	std::cout << "Type of binding: " << this->typeOfBinding << std::endl
		<< "Count of pages: " << this->countOfPages << std::endl;
}