/***********************************************
Author: Sam Rosa
Date: 9/30/18
Purpose: Ask a user to put in a negative integer and then check if it is
Time Spent: 45 minutes
***********************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);
void negative_check(void);

int main(int argc, char* argv[]) {

	negative_check();

	return 0;
}

void negative_check(void) {

	int count = 0;
	int input = 0;

	printf("Please enter a negative integer: ");
	count = scanf("%d", &input);
	clear_keyboard_buffer();
	while (!count || input >= 0) {

		printf("I'm sorry, you must enter a negative integer less than 0: ");
		count = scanf("%d", &input);
		clear_keyboard_buffer();

	}

	printf("The negative integer was: %d\n", input);

}

void clear_keyboard_buffer(void) {
	char check = ' ';

	scanf("%c", &check);
	while (check != '\n') {

		scanf("%c", &check);

	}

}