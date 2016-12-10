#include <conio.h>
#include <iostream>
#include "swapWords.h"


using namespace std;

int main(void) {
	char instr[100];
	cout << "Write a string (> 2 words)" << endl << "The original string: ";
	gets_s(instr);

	wordSwap(instr);

	cout << "String: " << instr << endl;
	_getch();
}