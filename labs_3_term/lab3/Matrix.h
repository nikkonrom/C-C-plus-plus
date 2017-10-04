#pragma once
#include "Proxy.h"

class Proxy;

class Matrix
{
public:
	Matrix(int, int, bool);
	Matrix(const Matrix&);
	~Matrix();
	Proxy operator[](int i);
	friend void show(const Matrix & matrix);
	void sort_arr();
	bool equals(const Matrix & matrix);
private:

	friend class Proxy;
	double ** matrix;
	int x_size, y_size;

	double fRand(double min, double max);
};


