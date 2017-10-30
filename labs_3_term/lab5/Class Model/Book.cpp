///////////////////////////////////////////////////////////
//  Book.cpp
//  Implementation of the Class Book
//  Created on:      16-окт.-2017 18:32:48
//  Original author: Никита
///////////////////////////////////////////////////////////

#include "Book.h"


Book::Book(Structure structure, Author author, Publisher publisher, Content content, Cover cover) 
	: content(content, cover, structure.countOfPages, structure.linesInPageCount)
{
	this->structure = structure;
	this->author = author;
	this->publisher = publisher;
	//BookContent content1();
	//this->content(content, cover, structure.countOfPages, structure.linesInPageCount);
}

Book::~Book()
{
}

void Book::Show() {
	this->author.Show();
	this->publisher.Show();
	this->structure.Show();
	this->content.Show();
}