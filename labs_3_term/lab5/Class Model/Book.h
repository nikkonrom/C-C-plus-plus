///////////////////////////////////////////////////////////
//  Book.h
//  Implementation of the Class Book
//  Created on:      16-окт.-2017 18:32:48
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_0492DCDC_AE33_499e_9299_49F86327FB89__INCLUDED_)
#define EA_0492DCDC_AE33_499e_9299_49F86327FB89__INCLUDED_
#pragma once
#include "BookContent.h"
#include "Structure.h"
#include "Print.h"

class Book : public Print
{

public:
	Book(Structure structure, Author author, Publisher publisher, Content content, Cover cover);
	virtual ~Book();
	void Show();

private:
	BookContent content;
	Structure structure;

};
#endif // !defined(EA_0492DCDC_AE33_499e_9299_49F86327FB89__INCLUDED_)
