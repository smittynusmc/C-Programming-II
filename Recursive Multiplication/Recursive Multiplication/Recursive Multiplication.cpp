// Recursive Multiplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

long long calculate(long long, long long);
void multiply();
long getInput();

int main()
{
	bool done = false;
	char choice;
	cout << "Welcome to Multiplication Calculator" << endl;
	while (!done) { // Main Program loop
		multiply();
		cout << "\nWould you like multiply two more numbers! Enter Y or y for yes and N or n for no!" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice);
		while (!(choice == 'Y' || choice == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to enter multiply two numbers or N or n to quit." << endl; // prompt user input correct choice
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
			cin >> choice;
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
getInout
Gets the user input and checks number input is not negative
*/
void multiply() {
	long long firstNum, secondNum; // name to be returned
	cout << "Please input your first number would like to compute." << endl;
	firstNum = getInput();
	cout << "Please input your second number would like to compute." << endl;
	secondNum = getInput();
	cout << firstNum << " * " << secondNum << " = " << calculate(firstNum, secondNum) << endl;
}

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

long long calculate(long long firstNum, long long secondNum)
{
	if (secondNum == 0) {
		return 0;
	}
	if (secondNum < 0) {
			return -calculate(firstNum, -secondNum);
	}
	if (secondNum > 0) {
		return firstNum + calculate(firstNum, secondNum - 1);
	}
	
}
