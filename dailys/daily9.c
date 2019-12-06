/***********************************************
Author: Sam Rosa
Date: 9/27/18

Answer to question: It is able to print out all of the numbers since there is not more functions being called like in daily 7
so there is no stack overflow that occurs
***********************************************/

#include <stdio.h>

void loop_down_to_zero(int n) {

	while (n >= 0) {

		printf("%d\n", n);
		--n;

	}

}

void loop_up_to_int(int n) {

	int x = 0;

	while (n >= x) {

		printf("%d\n", x);
		++x;

	}

}

int main(int argc, char* argv[]) {

	int n;
	
	printf("Please enter a positive integer: ");
	scanf("%d", &n);

	loop_down_to_zero(n);
	printf("***\n");
	loop_up_to_int(n);

	return 0;
}