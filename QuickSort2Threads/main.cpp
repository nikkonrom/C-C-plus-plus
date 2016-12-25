#include <windows.h>
#include <stdio.h>


void merge(int*, int);

int main() {
	int elements = 10;
	/*int* a;
	a = (int*)malloc(elements * sizeof(int));*/
	int a[10] = { 4,11,16,88,154,0,3,76,245,322 };
	srand(5);
	for (int index = 0; index < elements; index++) {
		//a[index] = 1 + rand() % 10;
		printf("  %d", a[index]);
	}
	puts("");
	merge(a, elements);
	for (int index = 0; index < elements; index++) {
		//a[index] = 1 + rand() % 10;
		printf("  %d", a[index]);
	}
	puts("");
	system("pause");
}


void merge(int *a, int n) {
	int ptr1, ptr2, write_position = 0, middle;
	int* c;
	c = (int*)malloc((n)* sizeof(int));
	
	ptr1 = 0;
	ptr2 = middle = n % 2 == 0? n/2 : n/2 + 1;

	while (true) {
		if (ptr1 < middle && ptr2 < n) {
			int temp;
			if (a[ptr1] < a[ptr2]) {
				temp = a[ptr1];
				ptr1++;
			}
			else {
				temp = a[ptr2];
				ptr2++;
			}
			c[write_position] = temp;
			write_position++;
		}

		else if (ptr1 < middle) {
			c[write_position] = a[ptr1];
			write_position++;
			ptr1++;
		}
		else if (ptr2 < n) {
			c[write_position] = a[ptr2];
			write_position++;
			ptr2++;
		}
		else
			break;
	}

	for (int counter = 0; counter < n; counter++)
		a[counter] = c[counter];

	free(c);
}
