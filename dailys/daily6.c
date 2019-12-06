/*********************************
Author: Sam Rosa
Date: 9/18/18

Answer to Question: To many functions are called and the stack can't handle anymore so the program crashes
*********************************/

#include <stdio.h>

void recursive_down_to_int(int n) {

	if (n >= 0) {

		printf("%d\n", n);
		recursive_down_to_int(n-1);

	}

}

void recursive_up_to_int(int n) {

	if (n >= 0) {

		recursive_up_to_int(n - 1);
		printf("%d\n", n);

	}

}

int main(int argc, char* argv[]) {

	recursive_down_to_int(10);
	printf("*****\n");
	recursive_up_to_int(10);
	return 0;

}