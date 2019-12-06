/***************
Author: Sam Rosa
Date: 9/19/2018

Purpose: To convert base 10 numbers to binary
***************/

#include <stdio.h>

void print_binary(int number);

int main(int argc, char* argv[]) {

	print_binary(42);
	printf("\n");
	return 0;

}

void print_binary(int number) {

	if (number > 0) {

		print_binary(number / 2);
		printf("%d", number % 2);

	}

}
