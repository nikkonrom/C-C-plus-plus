///////////////////////////////////////////////////////////
//  Content.cpp
//  Implementation of the Class Content
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#include "Content.h"


Content::Content()
{
	this->ageLimit = 6;
	this->censorshipNeed = false;
	this->type = "common";
}

Content::Content(int ageLimit, bool censorshipNeed, std::string type)
{
	this->ageLimit = ageLimit;
	this->censorshipNeed = censorshipNeed;
	this->type = type;
}

Content::~Content(){

}





void Content::Show(){
	std::cout << "Content age limit: " << this->ageLimit << std::endl
		<< "Need of censorship for content: " << std::boolalpha << this->censorshipNeed << std::endl
	<< "Type of content: " << this->type << std::endl;
}