#include <stdio.h>

/***********************************************
Author: Samuel Rosa
Date: 12/4/18
Purpose: Finds the index(s) containing 42 in a contiguous block of memory
Sources of Help: <Please list any sources that you used
 for help: tutors, web sites, lab assistants etc.>
Time Spent: 30 Minutes
***********************************************/

int * allocateMemory(int* blockSize);
void fillMemory(int* block, int blockSize);
void find42(int* block, int blockSize);
int getUserInput();
void clearKeyboardBuffer();

int main(void)
{

	int* p;
	int blockSize;

	//Seed the rand
	srand(time(NULL));

	//Do the stuff and such
	p = allocateMemory(&blockSize);
	fillMemory(p, blockSize);
	find42(p, blockSize);

	//Free the memory cause we done
	free(p);
	p = NULL;

	return 0;

}

int * allocateMemory(int* blockSize)
{

	int* block;

	*blockSize = getUserInput();

	//printf("Made block of %d size\n", *blockSize);

	block = malloc(sizeof(int) * *blockSize);

	return block;

}
void fillMemory(int* block, int blockSize)
{

	int i;

	for (i = 0; i < blockSize; i++)
	{

		block[i] = rand();

	}

}
void find42(int* block, int blockSize)
{

	int i;

	for (i = blockSize-1; i >= 0; i--)
	{

		if (block[i] == 42)
		{

			printf("%d\n", i);

		}

	}

}

int getUserInput()
{

	int num;
	int noc;

	do
	{

		printf("Please enter a number between 10,000 and 10,000,000: ");
		noc = scanf("%d", &num);
		clearKeyboardBuffer();

	} while (noc != 1 || num < 10000 || num > 10000000);

	return num;

}

void clearKeyboardBuffer()
{

	char c;

	do
	{

		scanf("%c", &c);

	} while (c != '\n');

}