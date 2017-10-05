#pragma once
#include "Proxy.h"

class Proxy;

class Matrix
{
public:
	Matrix(int, int, double, double);
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	Proxy operator[](int i);
	void show();
	void sort_arr();
	bool equals(const Matrix & matrix);
private:

	friend class Proxy;
	double ** matrix;
	int x_size, y_size;

	double fRand(double min, double max);
};


