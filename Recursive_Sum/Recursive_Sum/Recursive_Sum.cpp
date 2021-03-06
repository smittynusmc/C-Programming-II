// Recursive_Sum.cpp : The function recursively calculates the sum of all the numbers in the array. 
// The program asks the user to enter an array of numbers and prints its sum.
// Adam Tucker
// 06/16/18

#include "stdafx.h"
#include <iostream>
using namespace std;

//Prototype functions
double sum(double*,int);
int getNumberOfInputs();
void inputNumbers(double*, int);
void print(double*, double, int);

int main()
{
	bool done = false; //flag for program loop 
	char choice; // user choice to continue program
	int numInputs; // size of numbers to be put in array
	double* arrayOfNumbers; // doube pointer
	double result; // result of summation
	cout << "Welcome to Addition Calculator" << endl;
	
	while (!done) { // Main Program loop
		numInputs = getNumberOfInputs(); // get the number of inputs the user will need to fill the array
		arrayOfNumbers = new double[numInputs]; // allocate memory for array
		inputNumbers(arrayOfNumbers, numInputs); // get the numbers from the user
		print(arrayOfNumbers, sum(arrayOfNumbers, numInputs), numInputs); // run recursive summation program and print results
		cout << "\nWould you like input more numbers to add together! Enter Y or y for yes and N or n for no!" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice); // make choice uppercase
		while (!(choice == 'Y' || choice == 'N')) { // User input a character correctly. OR user input an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to input more numbers to add together or N or n to quit." << endl; // prompt user input correct choice
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
sum
Recursively sums an array of doubles
Param: arr - an pointer to an array of doubles
	   size - size of the array of doubles
Adapted from: https://stackoverflow.com/questions/15801957/recursive-sum-of-an-array-in-c
*/
double sum(double* numbers, int size)
{
	if (size == 1) { // size is 1 when an array has one element
		return numbers[0]; // return the first element in th array
	}
	return *numbers + sum(numbers + 1, size - 1); // recursively sums with the current numbers dereference pointer
}

/*
getNumberOfInputs
Asks the user the number of numbers to they will input
and checks if the user entered a positive number greater than zero
and returns the number input by the user
*/
int getNumberOfInputs()
{
	int numberOfInputs; // init number for user input
	cout << "Please enter a positive number for the amount of numbers to be added together." << endl; // Prompt user
	while (!(cin >> numberOfInputs) || numberOfInputs <= 0) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please enter a positive number for the amount of numbers to be added together." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfInputs; // return positive integer for number input by user
}

/*
inputNumbers
Asks the user for each number to be input
and puts the number in array
Param: numbers - the double pointer to the initialized array to hold numbers input by the user
	   size - the size of the array
*/
void inputNumbers(double *numbersToSum, int size)
{
	double myNumber; // init temp number variable
	for (int count = 0; count < size; count++) {
		cout << "Please enter your number. Negative Numbers are ok!\n#" << (count + 1) << ". "; /// prompt user
		while (!(cin >> myNumber)) { // check if the user input a number and check it is greater than zero
			cout << "Bad Input!!! Please enter a number you want to be added with the other numbers.\n#" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		*(numbersToSum + count) = myNumber; // input positive number into array
	}
}

/*
print
Loops through array and prints 1 + 2 + ... + *(numbers + size) = result
Param: numbers - pointer to beginning of an array of doubles
	   result - result of recursive summation
	   size - size of the array of doubles
*/
void print(double* numbers, double result, int size) {
	cout << "Here are your results of the numbers entered added together!\n" << endl; // output statement
	for (int index = 1; index <= size; index++) { // loop through array
		double tempNum = *(numbers + (index - 1)); // get current number in loop using pointer arithmetic
		if (index == size) { // we are at the last number in the array
			cout << tempNum; // print the last number without a "+" sign
		}
		else { // end of the array hasn't been reached
			cout << tempNum << " + "; // print the current number with a "+" sign
		}
	}
	cout << " = " << result << endl; // print the results at the end of "equation"
}