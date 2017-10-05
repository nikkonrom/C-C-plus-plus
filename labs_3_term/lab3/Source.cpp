#include <iostream>
#include <cstdlib>
#include "Matrix.h"

inline  Matrix rethrow_copy( Matrix);
inline  Matrix& rethrow_reference( Matrix &);
inline  Matrix * rethrow_by_pointer( Matrix *);

int main() {

	Matrix matrix(5, 5, 0, 100), equals_test(3, 5);
	matrix.show();
	matrix[1][10] = 1.3;

	double sample = 0;
	sample = matrix[100][500];
	std::cout << "Sample(out of range): " << sample << std::endl;

	sample = matrix[1][1];
	std::cout << "Sample(in range): " << sample << std::endl;
	matrix[1][1] = 14.88;
	matrix.show();


	matrix.sort_arr();


	rethrow_reference(matrix).show();
	rethrow_by_pointer(&matrix)->show();
	rethrow_copy(matrix).show();

	Matrix equals_test2(equals_test);
	if (equals_test.equals(equals_test2))
		std::cout << "Operation 1: If this appeared, matrixs are equal" << std::endl;
	if (!matrix.equals(equals_test))
		std::cout << "Operation 2: If this appeared, matrixs aren't equal" << std::endl;
	system("pause");
	return 0;
}


inline  Matrix rethrow_copy( Matrix source) {
	return source;
}

inline  Matrix & rethrow_reference( Matrix & source) {
	return	source;
}

inline  Matrix * rethrow_by_pointer( Matrix * source) {
	return source;
}