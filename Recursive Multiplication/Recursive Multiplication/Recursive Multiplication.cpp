// Recursive Multiplication.cpp : A program with a recursive function that accepts two arguments into the parameters x and y. 
// The function will return the value of x times y.
// Adam Tucker
// 06/09/18

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void multiply(); // prompts user for input
long long calculate(long long, long long); // recursive function multiplies x times y
long getInput(); // get user input

int main()
{
	bool done = false;
	char choice;
	cout << "Welcome to Multiplication Calculator" << endl;
	while (!done) { // Main Program loop
		multiply(); // run multiplication program
		cout << "\nWould you like multiply two more numbers! Enter Y or y for yes and N or n for no!" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice);
		while (!(choice == 'Y' || choice == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to enter multiply two numbers or N or n to quit." << endl; // prompt user input correct choice
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
multiply
Program thats gets a multiplicand and multiplier and finds the product
*/
void multiply() {
	long long multiplicand, multiplier; // name to be returned
	cout << "Please input the multiplicand." << endl;
	multiplicand = getInput(); // get input
	cout << "Please input the multiplier." << endl;
	multiplier = getInput(); // get input
	cout << multiplicand << " * " << multiplier << " = " << calculate(multiplicand, multiplier) << endl; // print result
}

/*
 getInput
 Get the input from the user and check if it is a number. If not loop til correct input
 */
long getInput() {
	float input;
	while (!(cin >> input)) // check if the user input a string
	{
		cout << "Bad Input!!! Please enter a number greater than zero!" << endl;  // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	cin.clear(); // Clear cin of errors if entered a char after number
	cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	return input;
}

/*
calculate
Recursive function that finds the product of two numbers
Param: 
multiplicand is the first number (i.e. 7 * 8 multiplicand is 7)
multiplier is the second number (i.e. 7 * 8 multiplier is 8)
*/
long long calculate(long long multiplicand, long long multiplier)
{
	if (multiplier == 0) {
		return 0; // base case multiplier has reached 0
	}
	if (multiplier < 0) { // if multiplier is negative
			return -calculate(multiplicand, -multiplier); // call calculate with positive version 
														  // and then make negative open return up stack
	}
	if (multiplier > 0) { // if multiplier is positive
		return multiplicand + calculate(multiplicand, multiplier - 1); // call calculate with multiplier - 1
	}
	
}
