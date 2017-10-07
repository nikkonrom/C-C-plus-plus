#include "MatrixInfo.h"
#include <iostream>

using namespace std;



MatrixInfo::MatrixInfo(int count, double maximum, double minimum, double sum) : count(count), maximum_element(maximum), minimum_element(minimum), sum(sum)
{
}

MatrixInfo::~MatrixInfo()
{
}

void MatrixInfo::show_info()
{
	cout << "Count of elements: " << count << endl << "Maximum: " << maximum_element << endl << "Minimum: " << minimum_element << endl << "Sum: " << sum << endl;
}
