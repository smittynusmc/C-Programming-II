// Iterative Factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Maximum number of digits in output
#define MAX 500

int multiply(int x, int res[], int res_size);
void calculateFactorial(int n);
int getInput();

int main()
{
	bool isDone = false; // flag for main loop
	int userInput;

	cout << "Welcome to FACTORIAL!" << endl;

	while (!isDone) { // main loop
		char choice; // int user choice to continue program
		userInput = getInput(); // get the user file name
		calculateFactorial(userInput); // open the file
		cout << "\nWould you like preview another file? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice); // take user choice and capitializes the choice
		while (!(choice == 'Y' || choice == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to enter another file or N or n to quit." << endl; // prompt user input correct choice
			cin >> choice;
		}
		if (choice == 'Y') { // user choose to run program again
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		else {
			isDone = true; // user quit program
		}
	}
    return 0;
}

/*
getInout
Gets the user input and checks number input is not negative
*/
int getInput() {
	int factorial; // name to be returned
	cout << "Please input the factorial you would like to compute." << endl;
	while (!(cin >> factorial) || factorial <= 0) // check if the user input a string
	{
		cout << "Bad Input!!! Please enter a number greater than zero!";  // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return factorial;
}

// This function finds factorial of large numbers
// and prints them
void calculateFactorial(int n)
{
	int res[MAX];

	// Initialize result
	res[0] = 1;
	int res_size = 1;

	// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
	for (int x = 2; x <= n; x++)
		res_size = multiply(x, res, res_size);

	cout << "Factorial of given number is \n";
	for (int i = res_size - 1; i >= 0; i--) {
		cout << res[i];
	}
}

// This function multiplies x with the number 
// represented by res[].
// res_size is size of res[] or number of digits in the 
// number represented by res[]. This function uses simple 
// school mathematics for multiplication.
// This function may value of res_size and returns the 
// new value of res_size
int multiply(int x, int res[], int res_size)
{
	int carry = 0;  // Initialize carry
					
	for (int i = 0; i<res_size; i++) // One by one multiply n with individual digits of res[]
	{
		int prod = res[i] * x + carry; // multiple the current decimal place by the current multiple and add carry if neccesary

		// Store last digit of 'prod' in res[]  
		res[i] = prod % 10; // gives you the digit the belongs in res array 
							// which is equivalent where the number belongs in the larger number
							// i.e. res[3] is the 100th place and res[6] is 100,000th place 
							// 6 % 10 would and i = 3 would mean the res is 600 and change

		// Put rest in carry
		carry = prod / 10; // this will be added to the next product
						   //  if greater than 10 then carry is will be added to next product
						   // otherwise there is not a carry
	}

	// Put carry in res and increase result size
	// If carry is not zero it needs to be added to the array
	while (carry)
	{
		res[res_size] = carry % 10; // new value added to array
		carry = carry / 10; // set carry to zero
		res_size++; // increase the size of the number array
	}
	return res_size;
}