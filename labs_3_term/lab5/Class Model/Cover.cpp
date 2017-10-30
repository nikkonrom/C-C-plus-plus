///////////////////////////////////////////////////////////
//  Cover.cpp
//  Implementation of the Class Cover
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#include "Cover.h"


Cover::Cover()
{
	this->hasImages = false;
	this->preview = "";
}

Cover::Cover(std::string preview, bool hasImages){
	this->preview = preview;
	this->hasImages = hasImages;
}



Cover::~Cover(){

}





void Cover::Show(){
	std::cout << "Cover preview: " << this->preview << std::endl 
		<< "Cover has images: " << std::boolalpha << this->hasImages << std::endl;
}