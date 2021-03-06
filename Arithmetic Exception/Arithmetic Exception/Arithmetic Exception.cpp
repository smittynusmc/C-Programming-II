// Arithmetic Exception.cpp : Write a function that accepts an integer parameter and returns its integer square root. The function should 
// throw an exception if it is passed an integer that is not a perfect square. 
// Adam Tucker
// 06/26/18

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
// Prototype functions
int getUserInput();
int calculateSquare(int) throw(string);

// Main Function
int main()
{

	int squareNum; // number to find square root
	bool done = false; // flag for program loop
	char choice; // choice to end program
	cout << "Welcome to the Square Root! Warning the calculator only calculates perfect squares! " << endl;

	while (!done) { // Main Program loop
		squareNum = getUserInput(); // get the number the user wants to attempt to find the square root of squareNum
		try { // try to find the square root
			cout << "The square root of " << squareNum << " is " << calculateSquare(squareNum) << endl; // Print out the square root
		}
		catch (string error) { // if squareNum isn't a perfect square print error to screen
			cout << error << endl;
		}

		cout << "\nWould you like input another number and finds it square root! Enter Y or y for yes and N or n for no!" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice);
		while (!(choice == 'Y' || choice == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to input another square root or N or n to quit." << endl; // prompt user input correct choice
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
			cin >> choice; // get user input
			choice = toupper(choice); // upper case input
		}
		if (choice == 'Y') { // user choose to run program again
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		else {
			done = true; // user quit program
		}
	}
	return 0;
}

/*
getUserInput
Asks the user the for the value to find the square root
and checks if the user entered a positive
and returns the positive number
*/
int getUserInput()
{
	int number; // init number of test scores
	cout << "Please input the positive perfect square." << endl;
	while (!(cin >> number) || number <= 0) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please input the positive perfect square" << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return number; // return positive integer
}

/*
calculateSquare
Calculates the square root
If squareNum is a perfect square than the square root of squareNum is returned
Otherwise an error is thrown indicating squareNum is not a perfect square
*/
int calculateSquare(int squareNum) throw(string) // throws a string error
{
	int result = sqrt(squareNum); // find the square root of squareNum

	if (result*result == squareNum) { // if the result square is equal to sqaureNum then return the sqaure root
		return result; // return square root
	}
	else { // squareNum is not a perfect square
		string error = "The value " + to_string(squareNum) + " is not a perfect square!"; // setup error string
		throw error; // throw the error
	}
}
