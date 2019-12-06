/***********************************************
Author: Samuel Rosa
Date: 10/16/18
Purpose: Calculates the population of green crud society given a starting
population and a number of days

Time Spent: 1 hour
***********************************************/

#include <stdio.h>

int getCrud();
int getDays();
void fibonacci(int crud, int days);
int userWishesToContinue();
void clearKeyboardBuffer();

int main(int argc, char* argv[])
{

	int n = 0;
	int d = 0;

	do
	{

		n = getCrud();
		d = getDays();

		fibonacci(n, d);

	} while (userWishesToContinue());

}

int getCrud()
{

	int crud = 0; //amount of crud in pounds
	int count = 0;

	do
	{

		printf("Please enter the intial size of the green crud: ");
		count = scanf("%d", &crud);
		clearKeyboardBuffer();

		if (count == 0 || crud <= 0)
		{

			printf("I'm sorry that value is unrecognized, negative, or zero.\n");

		}

	} while (count == 0 || crud <= 0);

	return crud;

}

int getDays()
{

	int days = 0;
	int count = 0;

	do
	{

		printf("Please enter the number of days: ");
		count = scanf("%d", &days);
		clearKeyboardBuffer();

		if (count == 0 || days < 0)
		{

			printf("I'm sorry that value is unrecognized or negative.\n");

		}

	} while (count == 0 || days < 0);

	return days;

}

void fibonacci(int crud, int days)
{

	int i;
	int previous = 0; //Will save the previous value for the fibonacci sequence

	printf("With an initial population of %d pounds of crud growing for %d days.\n", crud, days);

	days = days / 5; //Gets the number of times that the fibonacci will actually be done

	for (i = 1; i <= days; i++)
	{

		crud += previous;
		previous = crud - previous;

	}

	printf("The final population would be %d pounds.\n", crud);

}

int userWishesToContinue()
{

	char c = ' ';

	do
	{

		printf("Would you like to continue?(y/n) ");
		scanf(" %c", &c);
		clearKeyboardBuffer();

		if (c != 'Y' && c != 'y' &&
			c != 'N' && c != 'n')
		{

			printf("I'm sorry, I don't recognize that value.\n");

		}

	} while (c != 'Y' && c != 'y' &&
		c != 'N' && c != 'n');

	if (c == 'y' || c == 'Y')
	{

		return 1;

	}
	else
	{

		return 0;

	}

}

void clearKeyboardBuffer()
{

	char c = ' ';

	while (c != '\n')
	{

		scanf("%c", &c);

	}

}