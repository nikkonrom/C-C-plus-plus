///////////////////////////////////////////////////////////
//  Print.cpp
//  Implementation of the Class Print
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#include "Print.h"

Print::Print(Author author, Publisher publisher, Content content) :
	author(author), publisher(publisher), content(content){}

Print::Print()
{
}


Print::~Print(){

}





void Print::Show(){
	this->author.Show();
	this->publisher.Show();
	this->content.Show();
	
}