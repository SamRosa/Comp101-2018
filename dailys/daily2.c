/*
	Author: Sam Rosa
	Date: 9/7/2018
	
	Output: The program opened up a terminal window and it output this text
	This program has the executable name: C:\Users\Sam\Desktop\Comp 101 Files\daily2\Debug\daily2.exe
	That is all!
	Press any key to continue . . .

*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("This program has the executable name: %s\n", argv[0]);
	printf("That is all!\n");
	return 0;
}