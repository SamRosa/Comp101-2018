/***********************************************
Author: Samuel Rosa
Date: 11/1
Purpose: Converts lengths and weights
Sources of Help: <Please list any sources that you used
for help: tutors, web sites, lab assistants etc.>
Time Spent: 30 minutes
***********************************************/

#include <stdio.h>

void clearKeyboardBuffer();
void getUserInput(int* pInput);
int handleInput(int input);
void convertLength();
void convertWeight();
void lengthToMetric();
void lengthToUS();
void weightToMetric();
void weightToUS();

int main(int argc, char* argv[]) {

	int input = 0;

	do {
		getUserInput(&input);
	} while (handleInput(input));


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

	return *pInput = input;

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

	int input = -1;

	do {

		printf("Convert feet/inches to meters/centimeters: 1\n");
		printf("Convert meters/centimeters to feet/inches: 2\n");
		printf("Return to main: 0\n");
		printf("Enter and option: ");
		scanf("%d", &input);
		clearKeyboardBuffer();

	} while (input < 0 || input > 2);

	switch (input)
	{

	case 1:
		lengthToMetric();
		break;
	case 2:
		lengthToUS();
		break;
	case 0:
		return;

	}

}

void convertWeight()
{

	printf("User wishes to convert weight\n\n");

	int input = -1;

	do {

		printf("Convert pounds/ounces to kilograms/grams: 1\n");
		printf("Convert kilograms/grams to pounds/ounces: 2\n");
		printf("Return to main: 0\n");
		printf("Enter and option: ");
		scanf("%d", &input);
		clearKeyboardBuffer();

	} while (input < 0 || input > 2);

	switch (input)
	{

	case 1:
		weightToMetric();
		break;
	case 2:
		weightToUS();
		break;
	case 0:
		return;

	}

}

void lengthToMetric()
{

	printf("Converted length to metric\n\n");

}

void lengthToUS()
{

	printf("Converted length to imperial units\n\n");

}

void weightToMetric()
{

	printf("Converted weight to metric\n\n");

}

void weightToUS()
{

	printf("Converted weight to imperial units\n\n");

}