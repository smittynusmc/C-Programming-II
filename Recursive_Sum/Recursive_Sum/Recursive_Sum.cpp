// Recursive_Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double arr_sum(double*,int);
int getNumberOfInputs();
void inputNumbers(double *numbersToSum, int size);
void print(double*, double, int);

int main()
{
	bool done = false;
	char choice;
	int numInputs;
	double* arrayOfNumbers;
	double result;
	cout << "Welcome to Addition Calculator" << endl;
	
	while (!done) { // Main Program loop
		int numInputs = getNumberOfInputs();
		arrayOfNumbers = new double[numInputs];
		inputNumbers(arrayOfNumbers, numInputs);
		print(arrayOfNumbers,arr_sum(arrayOfNumbers, numInputs), numInputs); // run recursive addition program
		cout << "\nWould you like input more numbers to add together! Enter Y or y for yes and N or n for no!" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice);
		while (!(choice == 'Y' || choice == 'N')) { // User input a character or string or an incorrect value
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

double arr_sum(double* arr, int n)
{ // must be recursive
	if (n == 1) {
		return arr[0];
	}
	return *arr + arr_sum(arr+1, n - 1);
}

/************************************
getNumberOfTestScores
Asks the user the number of test scores to be input
and checks if the user entered a positive number greater than zero
and returns the number of test scores
*************************************/
int getNumberOfInputs()
{
	int numberOfTestScores; // init number of test scores
	cout << "Please enter a positive number for the amount of numbers to be added together." << endl; // Prompt user
	while (!(cin >> numberOfTestScores) || numberOfTestScores <= 0) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please enter a positive number for the amount of numbers to be added together." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfTestScores; // return positive integer for number of test scores
}

/************************************
inputTestScores
Asks the user for the test scores to be input
and checks if the user entered a positive number greater than zero
and puts the test in array
*************************************/
void inputNumbers(double *numbersToSum, int size)
{
	double myTestScore; // init temp test score variable
	for (int count = 0; count < size; count++) {
		cout << "Please enter your number. Negative Numbers are ok!\n#" << (count + 1) << ". "; /// prompt user
		while (!(cin >> myTestScore)) { // check if the user input a number and check it is greater than zero
			cout << "Bad Input!!! Please enter a number you want to be added with the other numbers.\n" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		*(numbersToSum + count) = myTestScore; // input positive number into array
	}
}

void print(double* numbers, double result, int size) {
	cout << "Here are your results of the numbers entered added together!\n" << endl;
	for (int index = 1; index <= size; index++) {
		int tempNum = *(numbers + (index - 1));
		if (index == size) {
			cout << tempNum;
		}
		else {
			cout << tempNum << " + ";
		}
	}
	cout << " = " << result << endl;
}