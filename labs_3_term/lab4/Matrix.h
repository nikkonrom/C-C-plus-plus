#pragma once
#include "Proxy.h"
#include <vector>
#include "MatrixInfo.h"
class Proxy;

class Matrix
{
public:
	Matrix(int, int, double, double);
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();

	Proxy operator[](int i);
	Matrix operator=(Matrix source);
	Matrix operator++(int);
	Matrix & operator++();
	Matrix operator()(double );
	Matrix operator+(Matrix source);
	Matrix operator-(Matrix source);
	bool operator==(Matrix source);
	void* operator new(size_t size);
	void operator delete(void* ptr);

	friend Matrix operator--(Matrix & source, int);
	friend Matrix& operator--(Matrix & source);
	friend Matrix operator+(Matrix & source, double filler);
	friend Matrix operator+(double filler, Matrix & source);
	friend bool operator==(Matrix & source, std::vector<std::vector<double>>);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& source);

	operator int()const;
	operator MatrixInfo()const;

	void show();
	void sort_arr();
	bool equals(const Matrix & matrix);

private:

	friend class Proxy;
	double ** matrix;
	int x_size, y_size;
	
	double fRand(double min, double max);
};


