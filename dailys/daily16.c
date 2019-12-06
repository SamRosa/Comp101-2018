/***********************************************
Author: Samuel Rosa
Date: 11/13/18
Purpose: Merges two lists of numbers in ascending order
Sources of Help: <Please list any sources that you used
for help: tutors, web sites, lab assistants etc.>
Time Spent: Way to long
***********************************************/

#include <stdio.h>
#include <stdlib.h>

void mergeFiles(FILE* input1, FILE* input2, FILE* output);
void grabNums(FILE* input1, FILE* input2, int* fileOneNum, int* fileTwoNum, int* fileToRead, int* noc1, int* noc2);
void compareNums(int fileOneNum, int fileTwoNum, int* fileToRead, int noc1, int noc2, int* numToWrite);
void writeToOutput(FILE* output, int numToWrite);

int main(int argc, char* argv[])
{

	FILE *fp1;
	FILE *fp2;
	FILE *fpOutput;

	fp1 = fopen("numbers1.txt", "r");

	if (fp1 == NULL)
	{

		printf("Failed to open numbers1.txt");
		exit(1);

	}

	fp2 = fopen("numbers2.txt", "r");

	if (fp2 == NULL)
	{

		printf("Failed to open number2.txt");
		exit(2);

	}

	fpOutput = fopen("output.txt", "w");

	if (fpOutput == NULL)
	{

		printf("Failed to open output file");
		exit(3);

	}

	mergeFiles(fp1, fp2, fpOutput);

	fclose(fp1);
	fclose(fp2);
	fclose(fpOutput);

	return 0;
}


/**
 *Merges the two files
 *
 *param input1
 *Address of the first input file that will be read
 *
 *param input2
 *Address of the second input file that will be read
 *
 *param output
 *Address of the output file
 */
void mergeFiles(FILE* input1, FILE* input2, FILE* output)
{

	int fileToRead = 0; //Will be used to let function know which file needs to be read from
	int fileOneNum;
	int fileTwoNum;
	int numToWrite;
	int noc1 = 0;
	int noc2 = 0;

	do
	{

		grabNums(input1, input2, &fileOneNum, &fileTwoNum, &fileToRead, &noc1, &noc2);

		compareNums(fileOneNum, fileTwoNum, &fileToRead, noc1, noc2, &numToWrite);

		//printf("%d %d\n", noc1, noc2);

		if (noc1 == 1 || noc2 == 1)
			writeToOutput(output, numToWrite);
		else
			return;

	} while (noc1 == 1 || noc2 == 1);

}

void grabNums(FILE* input1, FILE* input2, int* fileOneNum, int* fileTwoNum, int* fileToRead, int* noc1, int* noc2)
{
	
	if (*fileToRead == 0) {
		*noc1 = fscanf(input1, "%d", fileOneNum);
		//printf("Grabbed %d\n", *fileOneNum);
		//printf("NOC1 = %d\n", *noc1);
		*noc2 = fscanf(input2, "%d", fileTwoNum);
		//printf("Grabbed %d\n", *fileTwoNum);
		//printf("NOC2 = %d\n", *noc2);
	}

	if (*fileToRead == 1) {
		*noc1 = fscanf(input1, "%d", fileOneNum);
		//printf("Grabbed %d\n", *fileOneNum);
		//printf("NOC1 = %d\n", *noc1);
	}

	if (*fileToRead == 2) {
		*noc2 = fscanf(input2, "%d", fileTwoNum);
		//printf("Grabbed %d\n", *fileTwoNum);
		//printf("NOC2 = %d\n", *noc2);
	}

}
void compareNums(int fileOneNum, int fileTwoNum, int* fileToRead, int noc1, int noc2, int* numToWrite)
{

	//printf("Num 1: %d\n", fileOneNum);
	//printf("Num 2: %d\n", fileTwoNum);

	if (noc1 == 1 || noc2 == 1) {
		if (fileOneNum >= fileTwoNum) {
			*numToWrite = fileTwoNum;
			*fileToRead = 2;
		}
		else if (fileTwoNum >= fileOneNum) {
			*numToWrite = fileOneNum;
			*fileToRead = 1;
		}
	}
	if (noc1 == -1 && noc2 != -1) {
		*numToWrite = fileTwoNum;
		*fileToRead = 2;
	}
	if (noc2 == -1 && noc1 != -1){
		*numToWrite = fileOneNum;
		*fileToRead = 1;
	}

	//printf("Returning %d\n", *numToWrite);

}
void writeToOutput(FILE* output, int numToWrite)
{

	//printf("Wrote to %d to file\n", numToWrite);

	fprintf(output, "%d", numToWrite);

}