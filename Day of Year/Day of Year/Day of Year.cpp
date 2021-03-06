// Day of Year.cpp : Assuming that a year has 365 days, input an integer 
// representing a day of the year and the program translates it to a string consisting of the month followed by day of the month. 
//  Adam Tucker
//  05/19/18
// (Gaddis 810)
// Gaddis, Tony.Starting Out With C++, 9th Edition.Pearson, 20160406. VitalBook file.
// Code adapted from:
// https://stackoverflow.com/questions/17634282/how-can-i-convert-the-day-of-the-year-1-365-to-its-equivalent-date-ie-januar?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

#include "stdafx.h"
#include "DayOfYear.h"

int getDayOfYear(); // Gets number to be input by user

int main() {

	bool done = false; // flag for program
	char choice; // choice by user

	while (!done)
	{
		cout << "Welcome to the Day of Year Converter!" << endl;
		int numberToConvert = getDayOfYear(); // User inputs a number to convert
		DayOfYear dayOfYear = DayOfYear(numberToConvert); // init DayOfYear object
		while (!dayOfYear.isProperDayOfYear()){ // while user hasnt input a proper day of year
			numberToConvert = getDayOfYear(); // User inputs a number to convert
			dayOfYear = DayOfYear(numberToConvert); // init DayOfYear object
		}
		dayOfYear.print(numberToConvert); // print the number to a date
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
	int numberToConvert; // init number to convert
	cout << "Please enter a positive number day of the year you would like to convert." << endl; // Prompt user
	while (!(cin >> numberToConvert) || numberToConvert < 0) // check if the user input a number and check if it is less than zero
	{
		cout << "Bad Input!!! Please enter a positive number to convert." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberToConvert; // return positive integer for number to convert
}
