/***********************************************
Author: Sam Rosa
Date: 10/1/18
Purpose: Have user enter an integer between 1 to 79
Time Spent: 30 minutes
***********************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);
void draw_line(int n);

int main(int argc, char* argv[]) {

	int n = 0;
	int count = 0;

	printf("Please enter the number of asterisks you would like in your line: ");
	count = scanf("%d", &n);
	clear_keyboard_buffer();
	while (!count || n < 1 || n > 79) {

		printf("Integer out of range, please enter an integer in the range [1,79]: ");
		count = scanf("%d", &n);
		clear_keyboard_buffer();

	}

	draw_line(n);

	return 0;
}

void draw_line(int n) {

	int i = 0;
	while (i < n) {

		printf("*");
		i++;

	}
	printf("\n");

}

void clear_keyboard_buffer(void) {

	char c = ' ';

	scanf("%c", &c);
	while (c != '\n') {

		scanf("%c", &c);

	}
}