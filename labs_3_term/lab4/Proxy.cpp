#pragma once
#include "Proxy.h"
#include <iostream>


Proxy::Proxy(Matrix &matrix_instance_, int index, bool instanced) : matrix_instance(matrix_instance_), i(index), instanced(instanced) {};

double & Proxy::operator[](int j) {
	static double junk = -1;
	
	if (instanced) {
		if (j >= 0 && j < matrix_instance.y_size)
			return matrix_instance.matrix[i][j];
		else {
			std::cout << "ERROR:index out of range" << std::endl;
			return junk;
			//exit(1);
		}
	}
	else {
		std::cout << "ERROR:index out of range" << std::endl;
		return junk;
		//exit(1);
	}
}
