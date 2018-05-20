// Check Writing
// Program dynamically allocates an array of students surveyed structs large enough to hold a user-defined number of number of movies seen and student names.
// Once all the movies seen are entered, the array is sorted in ascending order.
// An average function is called that calculates the average movies seen, mode of movies seen and median of movies seen.
// Program displays the sorted list of movies seen, names and the movies seen average, mode and median with appropriate headings.
// (Gaddis 701)
// Author: Adam Tucker
// https://github.com/trodevel/HumanizerCpp
// 05/20/18

#include <iostream>
#include <string>
using namespace std;

#include "EnglishNumberToWordsConverter.h"  // EnglishNumberToWordsConverter

using namespace Humanizer::Localisation::NumberToWords;

int getNumberOfToConvert(); // Gets number of students surveyed to be input by user

int main()
{
	bool done = false; // flag for program
	char choice; // choice by user

	while (!done)
	{
		cout << "Welcome to the Check Converter!" << endl;
		int numberToConvert = getNumberOfToConvert(); // User inputs a number to convert
		EnglishNumberToWordsConverter e = EnglishNumberToWordsConverter(numberToConvert);
		string res = e.Convert(); // convert the number
		e.print(numberToConvert, res);
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
getNumberOfStudentsSurveyed
Asks the user the number to convert to be input
and checks if the user entered a positive number greater than or equal to zero
and returns the number to convert
*************************************/
int getNumberOfToConvert()
{
	int numberOfStudentsSurveyed; // init number to convert
	cout << "Please enter a positive number between 0 and 9999 you would like to convert.\n$"; // Prompt user
	while (!(cin >> numberOfStudentsSurveyed) || numberOfStudentsSurveyed < 0) // check if the user input a number and check if it is less than zero
	{
		cout << "Bad Input!!! Please enter a positive number to convert." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfStudentsSurveyed; // return positive integer for number to convert
}
