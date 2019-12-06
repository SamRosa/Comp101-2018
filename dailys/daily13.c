/***********************************************
Author: Samuel Rosa
Date: 11/1
Purpose: Converts lengths and weights
Sources of Help: <Please list any sources that you used
for help: tutors, web sites, lab assistants etc.>
Time Spent: 25 minutes
***********************************************/

#include <stdio.h>

void clearKeyboardBuffer();
void getUserInput(int* pInput);
int handleInput(int input);
void convertLength(void);
void convertWeight(void);

int main(int argc, char* argv[]) {

	int input = 0;
	
	do {
		getUserInput(&input);
	}while(handleInput(input));


	return 0;
}

void clearKeyboardBuffer()
{

	char c = ' ';

	while (c != '\n')
	{

		scanf("%c", &c);

	}

}

/**
 *Gets user input and assigns it to a variable
 *
 *@param input
 *   The address of the variable having the input assigned
 */
void getUserInput(int* pInput)
{
	int input = -1;

	do {
		printf("Convert length: 1\n");
		printf("Convert weights: 2\n");
		printf("Exit program: 0\n");
		printf("Enter and option: ");
		scanf("%d", &input);
		clearKeyboardBuffer();
	} while (input > 2 || input < 0);

	*pInput = input;

}

int handleInput(int input)
{

	if (input == 1)
	{

		convertLength();
		return 1;

	}
	if (input == 2)
	{

		convertWeight();
		return 1;

	}
	else {
		return 0;
	}

}

void convertLength()
{

	printf("User wishes to convert length\n\n");

}

void convertWeight()
{

	printf("User wishes to convert weight\n\n");

}