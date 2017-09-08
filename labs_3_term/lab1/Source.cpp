#include <stdio.h>

#include <stdlib.h>

bool check_braces(char *);

int main(int argc, char * argv[]) {
	if (argc != 3) {
		printf("ERROR: invalid file input/output or too many args\n");
		system("pause");
		return 0;
	}
	FILE * input_file;
	input_file = fopen(argv[1], "r");

	FILE * output_file;
	output_file = fopen(argv[2], "w");

	char source[100];

	while (!feof(input_file))
	{
		fscanf(input_file, "%s", source);
		if (check_braces(source)) {
			//printf("True");
			fprintf(output_file, "True\n");
		}
		else {
			//printf("False");
			fprintf(output_file, "False\n");
		}
	}

	fclose(input_file);
	fclose(output_file);

	return 0;
}

bool check_braces(char* source) {

	int brace_checker = 0;

	while (*source)
	{
		if (*source == '(')
			brace_checker++;
		else if (*source == ')')
		{
			brace_checker--;
		}
		source++;
		if (brace_checker < 0)
			return false;
	}
	if (brace_checker == 0)
		return true;
	else
		return false;
}