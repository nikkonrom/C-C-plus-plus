#pragma once
#include "Matrix.h"

class Matrix;
class Proxy
{
public:
	double & operator[](int j);
private:
	friend class Matrix;
	int i;
	bool instanced = false;
	Matrix &matrix_instance;
	
	Proxy(Matrix &matrix_instance_, int index, bool instanced);
	Proxy(const Proxy&);
	
};

