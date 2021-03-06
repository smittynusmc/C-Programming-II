// Recursive_Sum.cpp : A program that asks the user to enter an array of numbers and a value to be searched for.
// Adam Tucker
// 06/16/18

#include "stdafx.h"
#include <iostream>
using namespace std;

// Prototype Functions
bool isMember(int*, int, int);
int getNumberOfInputs();
int getNumSearchedFor();
void inputNumbers(int *, int);

int main()
{
	bool done = false; // flag for program loop
	char choice; // choice to end program
	int numInputs, numSearchedFor; // number from user
	int* arrayOfNumbers; // pointer to a double
	cout << "Welcome to the Number Locator!" << endl;

	while (!done) { // Main Program loop
		numInputs = getNumberOfInputs(); // get the how many numbers will be input
		numSearchedFor = getNumSearchedFor(); // get the number the user wants to find in the array
		arrayOfNumbers = new int[numInputs]; // make memory for numbers in array
		inputNumbers(arrayOfNumbers, numInputs); // get the numbers from the user and put them in the array
		if (isMember(arrayOfNumbers, numInputs, numSearchedFor)) { // look for the number in the array if true found and false otherwise
			cout << "The number " << numSearchedFor << " was found in the array!" << endl; // prompt when number found
		}
		else {
			cout << "The number " << numSearchedFor << " was not found in the array...Boo!" << endl; // prompt when number not found
		}
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

/*
isMember
The function returns true if the value is found in the array or false if the value is not found.
Parameters: arr - an array of doubles
            size - an integer indicating the number of elements in the array,
			numSearchedFor - an integer value to be searched for
*/
bool isMember(int* arr, int size, int numSearchedFor)
{ // must be recursive
	if (*arr == numSearchedFor) { // if the number is the one we are searching for return true
		return true;
	}
	if (size == 0) {
		return false; // size is 0 than we searched through the array and didn't find the number. Return false
	}
	return isMember(arr + 1, size - 1, numSearchedFor); // recursive call
}

/*
getNumberOfInputs
Asks the user the number of numbers to be input
and checks if the user entered a positive number greater than zero
and returns the number to numbers the user will input
*/
int getNumberOfInputs()
{
	int numberOfTestScores; // init number of test scores
	cout << "Please enter a positive number for the amount of numbers to be searched through." << endl; // Prompt user
	while (!(cin >> numberOfTestScores) || numberOfTestScores <= 0) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please enter a positive number for the amount of numbers to be searched through." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfTestScores; // return positive integer
}

/*
getNumSearchedFor
Asks the user the number to found in the array
and checks if the user entered a number and returns the number input by the user
*/
int getNumSearchedFor()
{
	int numberOfTestScores; // init number of test scores
	cout << "Please enter a number to search for in the array." << endl; // Prompt user
	while (!(cin >> numberOfTestScores)) { // check if the user input a number
		cout << "Bad Input!!! Please enter a number to search for in the array." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfTestScores; // return number to search for in the array
}

/*
inputNumbers
Asks the user for each number to be input
and puts the number in array
Param: numbers - the initialized array to hold numbers input by the user
	   size - the size of the array
*/
void inputNumbers(int *numbers, int size)
{
	double myNumber; // init temp number variable
	for (int count = 0; count < size; count++) {
		cout << "Please enter your number. Negative Numbers are ok!\n#" << (count + 1) << ". "; /// prompt user
		while (!(cin >> myNumber)) { // check if the user input a number and check it is greater than zero
			cout << "Bad Input!!! Please enter a number you want to be added with the other numbers.\n" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		*(numbers + count) = myNumber; // input positive number into array
	}
}
