/***********************************************
Author: Samuel Rosa
Date: 11/4
Purpose: Converts lengths and weights
Sources of Help: <Please list any sources that you used
for help: tutors, web sites, lab assistants etc.>
Time Spent: 3 hours
***********************************************/

#include <stdio.h>


typedef enum { US_LENGTH, US_WEIGHT, METRIC_LENGTH, METRIC_WEIGHT } Unit;

void clearKeyboardBuffer();
void getUserInput(int* pInput);
int handleInput(int input);
void convertLength();
void convertWeight();
void lengthToMetric();
void lengthToUS();
void weightToMetric();
void weightToUS();
void inputValues(int* pBigUnit, double* pSmallUnit, Unit unitType);
void displayOutput(int bigUnit, double smallUnit, Unit outputType);
void convertMetricLength(int meters, double centimeters, int* pFeet, double* pInches);
void convertUSLength(int feet, double inches, int* pMeters, double* pCentimeters);
void convertMetricWeight(int kilos, double grams, int* pPounds, double* pOunces);
void convertUSWeight(int pounds, double ounces, int* pKilos, double* pGrams);

int main(int argc, char* argv[]) {

	int input = 0;

	do {
		getUserInput(&input);
	} while (handleInput(input));


	return 0;
}

void clearKeyboardBuffer()
{

	char c = ' ';

	while (c != '\n')
	{

		scanf("%c", &c);

	}

}

/**
*Gets user input and assigns it to a variable
*
*@param input
*   The address of the variable having the input assigned
*/
void getUserInput(int* pInput)
{
	int input = -1;

	do {
		printf("Convert length: 1\n");
		printf("Convert weights: 2\n");
		printf("Exit program: 0\n");
		printf("Enter and option: ");
		scanf("%d", &input);
		clearKeyboardBuffer();
	} while (input > 2 || input < 0);

	*pInput = input;

}

/*
 *Handles input from the main menu and calls appropriate functions
 *
 *@param input
 *   Value to be compared to call appropiate function
 *
 *Return
 *   Returns 1 if the user did not enter 0 so that the loop in main will continue
 */
int handleInput(int input)
{

	if (input == 1)
	{

		convertLength();
		return 1;

	}
	if (input == 2)
	{

		convertWeight();
		return 1;

	}
	else {
		return 0;
	}

}

/**
 *Gets user input for length conversion and calls the appropriate function
 */
void convertLength()
{

	int input = -1;

	do {

		printf("Convert feet/inches to meters/centimeters: 1\n");
		printf("Convert meters/centimeters to feet/inches: 2\n");
		printf("Return to main: 0\n");
		printf("Enter and option: ");
		scanf("%d", &input);
		clearKeyboardBuffer();

	} while (input < 0 || input > 2);

	switch (input)
	{

	case 1:
		lengthToMetric();
		break;
	case 2:
		lengthToUS();
		break;
	case 0:
		return;

	}

}


/**
*Gets user input for weight conversion and calls the appropriate function
*/
void convertWeight()
{

	int input = -1;

	do {

		printf("Convert pounds/ounces to kilograms/grams: 1\n");
		printf("Convert kilograms/grams to pounds/ounces: 2\n");
		printf("Return to main: 0\n");
		printf("Enter and option: ");
		scanf("%d", &input);
		clearKeyboardBuffer();

	} while (input < 0 || input > 2);

	switch (input)
	{

	case 1:
		weightToMetric();
		break;
	case 2:
		weightToUS();
		break;
	case 0:
		return;

	}

}


/*
 *Handles US to Metric Conversion for length
 */
void lengthToMetric()
{

	int meters = 0, feet = 0;
	double centimeters = 0.0, inches = 0.0;

	//printf("Converted length to metric\n\n");

	inputValues(&feet, &inches, US_LENGTH);
	convertUSLength(feet, inches, &meters, &centimeters);
	displayOutput(meters, centimeters, METRIC_LENGTH);

}

/*
*Handles Metric to US Conversion for length
*/
void lengthToUS()
{

	int meters = 0, feet = 0;
	double centimeters = 0.0, inches = 0.0;

	inputValues(&meters, &centimeters, METRIC_LENGTH);
	convertMetricLength(meters, centimeters, &feet, &inches);
	displayOutput(feet, inches, US_LENGTH);

}

/*
*Handles US to Metric Conversion for weight
*/
void weightToMetric()
{
	int kilos = 0, pounds = 0;
	double grams = 0.0, ounces = 0.0; 

	inputValues(&pounds, &ounces, US_WEIGHT);
	convertUSWeight(pounds, ounces, &kilos, &grams);
	displayOutput(kilos, grams, METRIC_WEIGHT);

}

/*
*Handles Metric to US Conversion for weight
*/
void weightToUS()
{

	int kilos = 0, pounds = 0;
	double grams = 0.0, ounces = 0.0;

	inputValues(&kilos, &grams, METRIC_WEIGHT);
	convertMetricWeight(kilos, grams, &pounds, &ounces);
	displayOutput(pounds, ounces, US_WEIGHT);

}

/**
 *Takes the values for the conversion
 *
 *@param pBigUnit
 *   Holds the address of the larger unit, feet/meters/pounds/kilograms
 *
 *@param pSmallUnit
 *	 Holds the address of the smaller unit, inches/centimeters/ounces/grams
 *
 *@param unitType
 *   Enum that will allow function to print the correct prompts
 */
void inputValues(int* pBigUnit, double* pSmallUnit, Unit unitType)
{

	int bigUnit = -1;
	double smallUnit = -1.0;


	switch (unitType)
	{

	case US_LENGTH:

		do {

			printf("How many feet: ");
			scanf("%d", &bigUnit);
			clearKeyboardBuffer();

		} while (bigUnit < 0);

		do {

			printf("How many inches: ");
			scanf("%lf", &smallUnit);
			clearKeyboardBuffer();

		} while (smallUnit < 0.0);
		break;

	case US_WEIGHT:

		do {

			printf("How many pounds: ");
			scanf("%d", &bigUnit);
			clearKeyboardBuffer();

		} while (bigUnit < 0);

		do {

			printf("How many ounces: ");
			scanf("%lf", &smallUnit);
			clearKeyboardBuffer();

		} while (smallUnit < 0.0);
		break;

	case METRIC_LENGTH:

		do {

			printf("How many meters: ");
			scanf("%d", &bigUnit);
			clearKeyboardBuffer();

		} while (bigUnit < 0);

		do {

			printf("How many centimeters: ");
			scanf("%lf", &smallUnit);
			clearKeyboardBuffer();

		} while (smallUnit < 0.0);
		break;

	case METRIC_WEIGHT:

		do {

			printf("How many kilograms: ");
			scanf("%d", &bigUnit);
			clearKeyboardBuffer();

		} while (bigUnit < 0);

		do {

			printf("How many grams: ");
			scanf("%lf", &smallUnit);
			clearKeyboardBuffer();

		} while (smallUnit < 0.0);
		break;

	}

	*pBigUnit = bigUnit;
	*pSmallUnit = smallUnit;

}

/**
 *Displays the output for the conversions
 *
 *@param bigUnit
 *   The larger of the two units to be displayed
 *
 *@param smallUnit
 *   The smaller of the two units to be displayed
 *
 *@param outputType
 *   Enum that will tell the function how to format the output
 */
void displayOutput(int bigUnit, double smallUnit, Unit outputType)
{

	switch (outputType)
	{

	case US_LENGTH:
		printf("\nFeet: %d\n", bigUnit);
		printf("Inches: %f\n\n", smallUnit);
		break;
		
	case US_WEIGHT:
		printf("\nPounds: %d\n", bigUnit);
		printf("Ounces: %f\n\n", smallUnit);
		break;

	case METRIC_LENGTH:
		printf("\nMeters: %d\n", bigUnit);
		printf("Centimeters: %f\n\n", smallUnit);
		break;

	case METRIC_WEIGHT:
		printf("\nKilos: %d\n", bigUnit);
		printf("Grams: %f\n\n", smallUnit);
		break;

	}

}

/**
 *Converts metric length to US length
 *
 *@param meters
 *   The amount of meters for the conversion
 *
 *@param centimeters
 *   The amount of centimeters for the conversion
 *
 *@param pFeet
 *   address of the variable being used to store feet
 *
 *@param pInches
 *   address of the variable being used to store inches
 */
void convertMetricLength(int meters, double centimeters, int* pFeet, double* pInches)
{
	double metricTotal = 0.0; //Will hold the total metric length in meters
	int feet = 0;
	double inches = 0.0;

	metricTotal += centimeters / 100; //Converts centimeters to meters and adds it to metricTotal
	metricTotal += meters;

	feet = metricTotal / 0.3048; //Converts meters to feet and cuts off remainder because of truncation
	inches = ((metricTotal / 0.3048) - feet) * 12; //Gets the decimals that feet ignored and multiplies by 12 to get inches

	//Assigns feet and inches to the outside values to be printed
	*pFeet = feet;
	*pInches = inches;

}

/**
*Converts US length to metric length
*
*@param feet
*   The amount of feet for the conversion
*
*@param inches
*   The amount of inches for the conversion
*
*@param pMeters
*   address of the variable being used to store meters
*
*@param pCentimeters
*   address of the variable being used to store centimeters
*/
void convertUSLength(int feet, double inches, int* pMeters, double* pCentimeters)
{

	double usTotal = 0.0; //Will hold the total US length in feet
	int meters = 0;
	double centimeters = 0.0;

	usTotal += inches / 12; //Converts inches to feet and adds it to usTotal
	usTotal += feet;

	meters = usTotal * 0.3048; //Converts feet to meters and cuts off remainder because of truncation
	centimeters = ((usTotal * 0.3048) - meters) * 100; //Gets the decimals that meters ignored and multiplies by 100 to get centimeters

	//Assigns meters and centimeters to the outside values to be printed
	*pMeters = meters;
	*pCentimeters = centimeters;

}

/**
*Converts Metric weight to US weight
*
*@param kilos
*   The amount of kilos for the conversion
*
*@param grams
*   The amount of grams for the conversion
*
*@param pPounds
*   address of the variable being used to store pounds
*
*@param pOunces
*   address of the variable being used to store ounces
*/
void convertMetricWeight(int kilos, double grams, int* pPounds, double* pOunces)
{

	double metricTotal = 0.0; //Will hold the total metric weight in kilos
	int pounds = 0;
	double ounces = 0.0;

	metricTotal += grams / 1000; //Converts grams to kilograms and adds it to metricTotal
	metricTotal += kilos;

	pounds = metricTotal * 2.2046; //Converts kilos to pounds and cuts off remainder because of truncation
	ounces = ((metricTotal * 2.2046) - pounds) * 16; //Gets the decimals that pounds ignored and multiplies by 16 to get ounces

	//Assigns pounds and ounces to the outside values to be printed
	*pPounds = pounds;
	*pOunces = ounces;

}

/**
*Converts US weight to metric weight
*
*@param pounds
*   The amount of pounds for the conversion
*
*@param ounces
*   The amount of ounces for the conversion
*
*@param pKilos
*   address of the variable being used to store kilos
*
*@param pGrams
*   address of the variable being used to store grams
*/
void convertUSWeight(int pounds, double ounces, int* pKilos, double* pGrams)
{

	double usTotal = 0.0; //Will hold the total us weight in pounds
	int kilos = 0;
	double grams = 0.0;

	usTotal += ounces / 16; //Converts ounces to pounds and adds it to usTotal
	usTotal += pounds;

	kilos = usTotal / 2.2046; //Converts pounds to kilos and cuts off remainder because of truncation
	grams = ((usTotal / 2.2046) - kilos) * 1000; //Gets the decimals that kilos ignored and multiplies by 1000 to get grams

	//Assigns kilos and grams to the outside values to be printed
	*pKilos = kilos;
	*pGrams = grams;

}