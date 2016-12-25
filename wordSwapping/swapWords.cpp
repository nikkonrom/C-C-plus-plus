#include <iostream>
#include "swapWords.h"

void wordSwap(char* instr) {
	int index, counter = 0, counter_of_words = 0;
	int word1, word2, count_of_spaces = 0, swap_counter, write_position = 0;
	bool flag_word1 = false, flag_word2 = false;

	for (index = 0; instr[index] != '\0'; index++) {
		counter++;
		if (instr[0] != ' ' && instr[index] == ' ') {
			counter_of_words++;
		}
	}
	if (instr[index - 1] != ' ') {
		instr[index] = ' ';
		instr[index + 1] = 0;
		counter_of_words++;
	}



	for (swap_counter = 1; swap_counter <= counter_of_words / 2; swap_counter++) {


		for (index = write_position; count_of_spaces != 2; index++) {

			if (instr[index] == ' ') {
				count_of_spaces++;
			}
			if (count_of_spaces == 1 && !flag_word1) {
				word1 = index - 1;
				flag_word1 = true;
			}
			else if (count_of_spaces == 2 && !flag_word2) {
				word2 = index - 1;
				flag_word2 = true;
			}

		}

		int start_position_word1 = write_position, start_position_word2 = word1 + 2;
		int word1len = word1 - write_position + 1, word2len = word2 - start_position_word2 + 1;
		int difference = word1len - word2len;
		int differenceCondition;

		if (!difference)
			differenceCondition = 0;
		else if (difference > 0)
			differenceCondition = 1;
		else
			differenceCondition = -1;

		switch (differenceCondition) {
		case 0: {
			for (int symbolCount = 0; symbolCount < word1len; symbolCount++) {
				char intermidateSymbol = instr[start_position_word1 + symbolCount];
				instr[start_position_word1 + symbolCount] = instr[start_position_word2 + symbolCount];
				instr[start_position_word2 + symbolCount] = intermidateSymbol;
			}
			break;
		}
		case 1: {
			for (int symbolCount = 0; symbolCount < word2len; symbolCount++) {
				char intermidateSymbol = instr[start_position_word1 + symbolCount];
				instr[start_position_word1 + symbolCount] = instr[start_position_word2 + symbolCount];
				instr[start_position_word2 + symbolCount] = intermidateSymbol;
			}

			for (int counterOfDifference = 0; counterOfDifference < difference; counterOfDifference++) {
				int essentialNumber = word1 - counterOfDifference;
				for (int swap_counter = 0; swap_counter < word1len - difference + 1; swap_counter++) {
					char intermidateSymbol = instr[essentialNumber + swap_counter];
					instr[essentialNumber + swap_counter] = instr[essentialNumber + swap_counter + 1];
					instr[essentialNumber + swap_counter + 1] = intermidateSymbol;
				}
			}

			break;
		}
		case -1: {
			for (int symbolCount = 0; symbolCount < word1len; symbolCount++) {
				char intermidateSymbol = instr[start_position_word1 + symbolCount];
				instr[start_position_word1 + symbolCount] = instr[start_position_word2 + symbolCount];
				instr[start_position_word2 + symbolCount] = intermidateSymbol;
			}

			difference = abs(difference);
			for (int counterOfDifference = 0; counterOfDifference < difference; counterOfDifference++) {
				int essentialNumber = word2 - difference + 1 + counterOfDifference;
				for (int swap_counter = 0; swap_counter < word2len - difference + 1; swap_counter++) {
					char intermidateSymbol = instr[essentialNumber - swap_counter];
					instr[essentialNumber - swap_counter] = instr[essentialNumber - swap_counter - 1];
					instr[essentialNumber - swap_counter - 1] = intermidateSymbol;
				}
			}

			break;
		}
		}


		write_position = index;
		count_of_spaces = 0;
		flag_word1 = false;
		flag_word2 = false;


	}

	return;
}