// Romaniuk, 650504, 1 variant
// Вычитание элементов матрицы

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

#define ITEMS_COUNT 8

using namespace std;

void writeMat(int obj[ITEMS_COUNT])
{
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		cout.width(4);
		cout << obj[i] << " ";
	}
	cout << endl;
}

void matrix_display(short obj[ITEMS_COUNT][ITEMS_COUNT])
{
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		for (int j = 0; j < ITEMS_COUNT; j++)
		{
			cout.width(4);
			cout << obj[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	short first_matrix[ITEMS_COUNT][ITEMS_COUNT];
	short second_matrix[ITEMS_COUNT][ITEMS_COUNT];
	short first_matrix_asm[ITEMS_COUNT][ITEMS_COUNT];
	short second_matrix_asm[ITEMS_COUNT][ITEMS_COUNT];
	short first_matrix_mmx[ITEMS_COUNT][ITEMS_COUNT];
	short second_matrix_mmx[ITEMS_COUNT][ITEMS_COUNT];

	for (int i = 0; i < ITEMS_COUNT; i++)
		for (int j = 0; j < ITEMS_COUNT; j++)
		{
			first_matrix[i][j] = first_matrix_asm[i][j] = first_matrix_mmx[i][j] = 15000 + rand() % 15000;
			second_matrix[i][j] = second_matrix_asm[i][j] = second_matrix_mmx[i][j] = 15000 + rand() % 10000;
		}
		
	cout << "Matrix A:" << endl;
	matrix_display(first_matrix);
	cout << "Matrix B:" << endl;
	matrix_display(second_matrix);

	int countcycle = 0;
	double start = clock();
	while (countcycle < 1000000)
	{
		for (int i = 0; i < ITEMS_COUNT; i++)
		{
			for (int j = 0; j < ITEMS_COUNT; j++)
			{
				first_matrix[i][j] -= second_matrix[i][j];
			}
		}
		countcycle++;
	}

	double finish = clock();
	double time = (finish - start) / 1000;
	cout << "Time C++ - " << time << "mc" << endl;
	matrix_display(first_matrix);

	int counter;
	countcycle = 0;
	start = clock();
	_asm finit
	while (countcycle < 1000000)
	{
		_asm
		{
			pusha
			xor esi, esi// обнуление регистра si
			xor ecx, ecx// обнуление регистра cx
			mov counter, ITEMS_COUNT*ITEMS_COUNT// внесение необходимого количества итераций
			loop1 :
			mov eax, first_matrix_asm[esi]// занесение элемента первой матрицы в регистр
				mov ebx, second_matrix_asm[esi]// занесение элемента второй матрицы в регистр
				sub eax, ebx// осуществление вычитания элементов
				mov first_matrix_asm[esi], eax// запись результата в первю матрицу
				add esi, 2// увеличение индекса
				sub counter, 1// уменьшение счётчика
				jnz loop1// переход на меткуё
				popa
		}
		countcycle++;
	}
	_asm fwait
	finish = clock();
	time = (finish - start) / 1000;
	cout << "Time with assembler - " << time << "mc" << endl;

	matrix_display(first_matrix_asm);

	start = clock();
	_asm finit
	while (countcycle < 1000000)
	{
		_asm
		{
			pusha
			xor esi, esi// обнуление регистра si
			xor ecx, ecx// обнуление регистра cx
			mov counter, ITEMS_COUNT*ITEMS_COUNT// внесение необходимого количества итераций
			loop2 :
			movq MM0, first_matrix_mmx[esi]// внесение в регистр упакованных байтов первой матрицы
				movq MM1, second_matrix_mmx[esi]// внесение в регистр упакованных байтов второй матрицы
				psubd MM0, MM1; осуществление вычитания
				movq first_matrix_mmx[esi], MM0// запись результата в первую матрицу
				add esi, 8// увеличение адреса(8 * 8 бит)
				sub counter, 4// увеличение счётчика сразу на 4 элемента
				jnz loop2// переход на метку
				emms
				popa
		}
		countcycle++;
	}
	_asm fwait
	finish = clock();
	time = (finish - start) / 1000;
	cout << "Time with MMX - " << time << "mc" << endl;
	matrix_display(first_matrix_mmx);

	system("pause");
}