// Min and Max Templates.cpp : Templates for the two functions min and max.
// Min accepts two arguments and return the value of the argument that is the lesser of the two
// Max accepts two arguments and return the value of the argument that is the greater of the two. 
// Adam Tucker
// 06/26/18

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// Prototype functions
int getUserInput(); 
int getNumberMaxorMin();

/*
min Template function
Returns the minumum of the two numbers
adapted from
http://www.cplusplus.com/reference/algorithm/max/
*/
template <class T>
T min(T numOne, T numTwo) {
	return !(numTwo<numOne) ? numOne : numTwo;
}

/*
max Template function
Returns the maximum of the two numbers
adapted from http://www.cplusplus.com/reference/algorithm/max/
*/
template <class T>
T max(T numOne, T numTwo) {
	return (numOne<numTwo) ? numTwo : numOne;
}

// Main Function
int main()
{
	int numOne, numTwo;
	int maxNum, minNum;
	int squareNum; // number to find square root
	bool done = false; // flag for program loop
	char choice; // choice to end program
	cout << "Welcome to Max or Min!" << endl;

	while (!done) { // Main Program loop
		cout << "Please enter a number!" << endl;
		numOne = getUserInput(); // get one of the numbers from the user
		cout << "Please enter another number!" << endl;
		numTwo = getUserInput(); // get the second number from the user
		if (getNumberMaxorMin()) { // see what function the user wants to use either 1 for max and 0 for min
			cout << "The max of the two numbers is " << max(numOne, numTwo) << endl; // find max of two numbers and print result
		}
		else {
			cout << "The min of the two numbers is " << min(numOne, numTwo) << endl; // find min of two numbers and print result
		}
		cout << "\nWould you like to find the min or max of two numbers again! Enter Y or y for yes and N or n for no!" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice);
		while (!(choice == 'Y' || choice == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to find the min or max of two numbers or N or n to quit." << endl; // prompt user input correct choice
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
Asks the user the for the value
and returns a number
*/
int getUserInput()
{
	int number; // init number of test scores
	while (!(cin >> number)) { // check if the user input a number
		cout << "Bad Input!!! Please input a number" << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return number; // return integer
}
/*
getNumberMaxorMin
Asks the user if they want to find minimum to input 0 or to find maximum input 1
and returns 1 for max function and 0 for min function and otherwise asks the user to input a 1 or 0 again
*/
int getNumberMaxorMin()
{
	int number; // init number of test scores
	cout << "Please input a 0 to find the minimum or 1 to find the maximum" << endl;
	while (!(cin >> number) || number < 0 || number > 1) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please either 1 for minimum or 0 for maximum." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return number; // return positive integer
}
