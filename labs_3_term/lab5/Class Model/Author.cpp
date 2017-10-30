///////////////////////////////////////////////////////////
//  Author.cpp
//  Implementation of the Class Author
//  Created on:      16-окт.-2017 18:32:48
//  Original author: Никита
///////////////////////////////////////////////////////////

#include "Author.h"




Author::Author(std::string name, bool publishingMembership):name(name), publishingMembership(publishingMembership)
{
}

Author::Author()
{
}

Author::~Author(){

}





void Author::Show(){
	std::cout << "Author's name: " << this->name << std::endl
		<< "Author's participating in publishing: " << std::boolalpha << this->publishingMembership << std::endl;
}