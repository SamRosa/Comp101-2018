/*
 Author: Samuel Rosa
 Course: COMP 1010 201, Computing I
 Date: 12/11/18
 Description: This file implements the
 functionality required by
 Program 3.
*/

#include <stdio.h>
#include <ctype.h>

int grabName(FILE* input, FILE* output);
void getGrades(FILE* input, FILE* output);
void combineNames(char firstName[], char lastName[], char fullName[], int size);

void copyCat(FILE* input, FILE* output);

char* read_string(FILE* fp, char* buffer, int size);

int main(int argc, char* argv[])
{

	FILE * fpOutput;
	FILE * fpInput; 


	fpInput = fopen("quiz.txt", "r");
	if (fpInput == NULL)
	{
		printf("Failed to open quiz.txt\n");
		exit(1);
	}
	 
	fpOutput = fopen("average.txt", "w");
	if (fpOutput == NULL)
	{
		printf("Failed to open average.txt\n");
		exit(1);
	}

	while(grabName(fpInput, fpOutput))
	{

		getGrades(fpInput, fpOutput);

		fprintf(fpOutput, "\n");

	}

	fclose(fpInput);
	fclose(fpOutput);

	fopen("average.txt", "r", fpInput);
	fopen("quiz.txt", "w", fpOutput);

	copyCat(fpInput, fpOutput);

	fclose(fpInput);
	fclose(fpOutput);

	return 0;

}

int grabName(FILE* input, FILE* output)
{

	char firstName[21];
	char lastName[21];
	char fullName[21];

	if (read_string(input, firstName, 21))//If there is no first name it will return 0
	{
		if (read_string(input, lastName, 21))//If there is no last name it will return 0
		{
			combineNames(firstName, lastName, fullName, 21);
			fprintf(output, "%20s", fullName);
			return 1;
		}
	}
	return 0;
}

void getGrades(FILE* input, FILE* output)
{

	int noc;
	int i = 0;
	int grade;
	int sum = 0;

	noc = fscanf(input, "%d", &grade); //Try
	if (noc != 1)
	{
		return;
	}
	while (noc == 1 && i < 10)//Check
	{

		sum += grade; //do
		fprintf(output, "%4d", grade);
		i++;
		noc = fscanf(input, "%d", &grade);//Try

	}

	fprintf(output, "%10.2f", sum / (double)i);

}

char* read_string(FILE* fp, char* buffer, int size)
{
	int c;
	c = getc(fp);
	int i = 0;

	while (c != EOF && isspace(c))
	{
		c = getc(fp);
	}

	if (c == EOF || size <= 1)
	{
		return NULL;
	}

	buffer[i] = (char)c;
	i++;

	c = getc(fp);//try
	while (c != EOF && !isspace(c) && i < size - 1) //check
	{
		buffer[i] = c; //do
		i++;
		c = getc(fp);//try
	}

	if (c != EOF)
	{
		ungetc(c, fp);
	}

	buffer[i] = '\0';
	return buffer;
}

void combineNames(char firstName[], char lastName[], char fullName[], int size)
{

	int i;
	int j = 0;

	for (i = 0; i < (size / 2) && lastName[i] != '\0'; i++)
	{

		fullName[i] = lastName[i];

	}

	//Adds a comma and prepares index for next loop
	fullName[i++] = ',';
	fullName[i++] = ' ';
	
	for (; i < size-1 && fullName[i] != '\0'; i++)
	{

		fullName[i] = firstName[j];

		j++;

	}

	fullName[i] = '\0';

}

void copyCat(FILE* input, FILE* output)
{

	char c = ' ';
	int noc;


	noc = fscanf(input, "%c", &c);
	while (noc != EOF)
	{

		fprintf(output, "%c", c);
		noc = fscanf(input, "%c", &c);

	}

}