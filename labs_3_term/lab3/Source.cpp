#include <iostream>
#include <cstdlib>
#include "Matrix.h"

inline const Matrix rethrow_copy(const Matrix);
inline const Matrix& rethrow_reference(const Matrix &);
inline const Matrix * rethrow_by_pointer(const Matrix *);

int main() {

	Matrix matrix(5, 5, true), equals_test(3, 5, false), equals_test2(3, 5, false);

	show(matrix);
	matrix[1][10] = 1.3;
	double sample = 0;
	sample = matrix[100][500];
	std::cout << "Sample(out of range): " << sample << std::endl;
	sample = matrix[1][1];
	std::cout << "Sample(in range): " << sample << std::endl;
	matrix[1][1] = 14.88;
	show(matrix);
	matrix.sort_arr();
	show(rethrow_reference(matrix));
	show(*rethrow_by_pointer(&matrix));
	show(rethrow_copy(matrix));
	if (equals_test.equals(equals_test2))
		std::cout << "Operation 1: If this appeared, matrixs are equal" << std::endl;
	if (!matrix.equals(equals_test))
		std::cout << "Operation 2: If this appeared, matrixs aren't equal" << std::endl;
	system("pause");
	return 0;
}


inline const Matrix rethrow_copy(const Matrix source) {
	return source;
}

inline const Matrix & rethrow_reference(const Matrix & source) {
	return	source;
}

inline const Matrix * rethrow_by_pointer(const Matrix * source) {
	return source;
}