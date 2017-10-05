#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

Matrix::Matrix(int x_size, int y_size, double min_rand, double max_rand) : x_size(x_size), y_size(y_size), matrix(new double*[x_size])
{
	srand(time(NULL));
	for (int i = 0; i < x_size; i++) {
		matrix[i] = new double[y_size];
		for (int j = 0; j < y_size; j++)
		{
			matrix[i][j] = fRand(min_rand, max_rand);
		}
	}
}

Matrix::Matrix(int x_size, int y_size) : x_size(x_size), y_size(y_size), matrix(new double*[x_size])
{
	srand(time(NULL));
	for (int i = 0; i < x_size; i++) {
		matrix[i] = new double[y_size];
		for (int j = 0; j < y_size; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix & matrix)
{
	this->x_size = matrix.x_size;
	this->y_size = matrix.y_size;
	this->matrix = new double*[matrix.x_size];
	for (int i = 0; i < matrix.x_size; i++) {
		this->matrix[i] = new double[matrix.y_size];
		for (int j = 0; j < matrix.y_size; j++)
		{
			this->matrix[i][j] = matrix.matrix[i][j];
		}
	}
}


Matrix::~Matrix()
{
	for (int i = 0; i < x_size; i++)
		delete[] this->matrix[i];
	delete this->matrix;
}

Proxy Matrix::operator[](int i)
{
	if (i > 0 && i < this->x_size)
		return Proxy(*this, i, true);
	else
		return Proxy(*this, i, false);
}



void Matrix::sort_arr()
{
	double * junk_array = new double[this->x_size*this->y_size];
	for (int i = 0; i < this->x_size; i++)
	{
		for (int j = 0; j < this->y_size; j++)
		{
			junk_array[i*this->x_size + j] = this->matrix[i][j];
		}
	}
	sort(junk_array, junk_array + this->y_size*this->y_size);
	for (int i = 0; i < this->x_size; i++)
	{
		for (int j = 0; j < this->y_size; j++)
		{
			this->matrix[i][j] = junk_array[i*this->x_size + j];
		}
	}
	delete[] junk_array;
}

bool Matrix::equals(const Matrix & matrix)
{
	if (this->x_size == matrix.x_size && this->y_size == matrix.y_size)
		for (int i = 0; i < this->x_size; i++)
		{
			for (int j = 0; j < y_size; j++)
			{
				if (this->matrix[i][j] != matrix.matrix[i][j])
					return false;
			}
		}
	else
	{
		return false;
	}
	return true;
}

double Matrix::fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}



void Matrix::show() {
	std::stringstream stream;
	int precision = 4, width = 8;
	stream.precision(precision);
	stream << std::endl;

	for (int i = 0; i < this->x_size; i++)
	{
		for (int j = 0; j < this->y_size; j++)
		{
			stream << setw(width) << this->matrix[i][j] << " ";
		}
		stream << std::endl;

	}
	stream << std::endl;
	std::cout << stream.str();
}