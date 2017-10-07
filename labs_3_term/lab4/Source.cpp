#include <iostream>
#include <cstdlib>
#include "Matrix.h"

inline  Matrix rethrow_copy( Matrix);
inline  Matrix& rethrow_reference( Matrix &);
inline  Matrix * rethrow_by_pointer( Matrix *);

using namespace std;

int main() {

	Matrix matrix(5, 5, 0, 100), equals_test(3, 5);	
	
	Matrix matrix_copy = matrix; 
	std::cout << matrix_copy;
	matrix_copy(5);	
	std::cout << matrix_copy;
	matrix = matrix + matrix_copy;
	int count = (int)matrix;
	cout << count << endl;
	MatrixInfo info = (MatrixInfo)matrix;
	info.show_info();

	matrix = matrix + 10.0;
	//matrix = 10.0 + matrix;
	//Matrix * arr = new[]

	vector<vector<double>> vector = { {0,0}, {0,0} };
	Matrix vector_test(2, 2);
	if (vector_test == vector)
		cout << "!!!!!!!!!!!!!";

	cout << matrix;
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