#pragma once
class MatrixInfo
{
public:

	MatrixInfo(int, double, double, double);
	~MatrixInfo();
	void show_info();
private:
	int count;
	double maximum_element, minimum_element, sum;
	
};

