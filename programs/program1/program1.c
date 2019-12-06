/***********************************************
Author: Sam Rosa
Date: 10/14/18
Purpose: Asks the user for a lower and upper boundry and then runs the collatz
conjecture on each and prints out the number of steps it took

Time Spent: 1 hour 30 mins
***********************************************/

#include <stdio.h>

int get_user_input(void); //Receives and returns the users input
void collatz(int lower, int upper); //Does the conjecture
void clear_keyboard_buffer(void);
int collatz_calculate(int n); // Calculates the conjecture and return the number of steps


int main(int argc, char* argv[]) 
{

	int lower; //Lower boundry of the program
	int upper; //Upper boundry of the program

	do {
		printf("Enter a starting point: ");
		lower = get_user_input();
		if (lower <= 1 || lower >= 1000) {
			printf("Please enter an integer greater than 1 and less than 1000\n");
		}
	} while (lower <= 1 || lower >= 1000); //Makes sure the input is in the correct range
	do {
		printf("Enter an ending point: ");
		upper = get_user_input();
		if (upper <= lower || upper >= 10000) {
			printf("Please enter an integer greater than the lower boundry and less than 10000\n");
		}
	} while (upper <= lower || upper >= 10000); //Makes sure the input is in the correct range
	collatz(lower, upper);
	printf("\n");

}


int get_user_input() //Gets and return int of user input
{

	int input; //The user input
	int count; //Count of what scanf recieved

	do {
		count = scanf("%d", &input);
		clear_keyboard_buffer();
		if (count == 0) {
			printf("Please enter a valid integer: ");
		}
	} while (count == 0);

	return input;
	
}

void collatz(int lower, int upper) //Does the conjecture and prints it out
{

	int count; // Keeps track of the number of steps
	int working_number = lower; // The number that is currently being worked on
	int column = 0; // Keeps track of the number of columns

	while (working_number <= upper) {

		count = collatz_calculate(working_number);

		printf("%5d", working_number);
		printf(":");
		printf("%-5d ", count);
		column++;
		if (column == 7) {
			printf("\n");
			column = 0;
		}

		working_number++;

	}

}

int collatz_calculate(int n) // Returns int steps for int n received
{
	int steps = 0; //number of steps taken

	while (n != 1) {

		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = (3 * n) + 1;
		}
		steps++;
	}

	return steps;

}

void clear_keyboard_buffer(void) //Clears the keyboard buffer
{

	char c = ' ';

	scanf("%c", &c);
	while (c != '\n') {

		scanf("%c", &c);

	}
}