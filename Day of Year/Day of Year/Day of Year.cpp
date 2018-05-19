// Day of Year.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DayOfYear.h"
#include <time.h>       /* time_t, struct tm, time, mktime */
//#include <strings.h>    /* bzero */

int getDayOfYear(); // Gets number of students surveyed to be input by user

int main() {
	time_t loctime;
	struct tm timeinfo, *loctimeinfo;
	int year, day;

	bool done = false; // flag for program
	char choice; // choice by user

	while (!done)
	{
		cout << "Welcome to the Day of Year Converter!" << endl;
		int numberToConvert = getDayOfYear(); // User inputs a number to convert
		DayOfYear dayOfYear = DayOfYear(numberToConvert);
		while (!dayOfYear.isProperDayOfYear()){
			numberToConvert = getDayOfYear(); // User inputs a number to convert
			dayOfYear = DayOfYear(numberToConvert);
		}
		dayOfYear.print(numberToConvert);
		cout << "\nWould you like enter another number to convert? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
		cin >> choice;
		while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')) // User input a character or string or an incorrect value
		{
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to enter numbers to convertor N or n to quit." << endl; // prompt user input correct choice
			cin >> choice;
		}
		if (choice == 'y' || choice == 'Y')   // user choose to enter more numbers to convert
		{
			continue;
		}
		else
		{
			done = true; // change flag to quit program
		}
	}

	return 0;
}

/************************************
getDayOfYear
Asks the user the number to convert to be input
and checks if the user entered a positive number greater than or equal to zero
and returns the number to convert
*************************************/
int getDayOfYear()
{
	int numberOfStudentsSurveyed; // init number to convert
	cout << "Please enter a positive number day of the year you would like to convert." << endl; // Prompt user
	while (!(cin >> numberOfStudentsSurveyed) || numberOfStudentsSurveyed < 0) // check if the user input a number and check if it is less than zero
	{
		cout << "Bad Input!!! Please enter a positive number to convert." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfStudentsSurveyed; // return positive integer for number to convert
}
