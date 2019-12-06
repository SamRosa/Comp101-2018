/***************************
Author: Sam Rosa
Date: 9/25/18


Purpose: See if a integer is positive or odd and if positive divide by 2 and if odd multiply by 3 and add 1


****************************/

#include <stdio.h>

void checkInt(int num) {

	if (num % 2) {

		printf("The next value of the number is: %d\n", num * 3 + 1);

	}
	else {

		printf("The next value of the number is %d\n", num / 2);

	}

}

int main(int argc, char* argv[]) {

	int x;

	printf("Please enter a positive integer: ");
	scanf("%d", &x);

	checkInt(x);

	//printf("%d\n", x);
	
	return 0;

}