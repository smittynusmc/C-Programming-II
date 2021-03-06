// Iterative Factorial.cpp :iterative version (using a loop instead of recursion) of the factorial function 
// Adam Tucker
// 06/09/18

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Maximum number of digits in factorial result
#define MAX 500

int multiply(int x, int res[], int res_size); // multiply muliplicand times current factorial result
void calculateFactorial(int n); // calculate factorial
int getInput(); // get user input

int main()
{
	bool isDone = false; // flag for main loop
	int userInput;

	cout << "Welcome to FACTORIAL!" << endl;

	while (!isDone) { // main loop
		char choice; // int user choice to continue program
		userInput = getInput(); // get the users inputs
		calculateFactorial(userInput); // Calculate factorial
		cout << "\nWould you like preview another file? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice); // take user choice and capitializes the choice
		while (!(choice == 'Y' || choice == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to enter another file or N or n to quit." << endl; // prompt user input correct choice
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
			cin >> choice;
			choice = toupper(choice); // take user choice and capitializes the choice
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
getInput
Gets the user input and checks number input is not negative
*/
int getInput() {
	int factorial; // number to be returned
	cout << "Please input the factorial you would like to compute." << endl;
	while (!(cin >> factorial) || factorial <= 0) // check if the user input a positive number
	{
		cout << "Bad Input!!! Please enter a number greater than zero!" << endl
			;  // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return factorial;
}

/*
calculateFactorial
This function finds factorial of large numbers and prints them
Param: the number to calculate its factorial
*/
void calculateFactorial(int factorialSeed)
{
	int factorial[MAX];

	// Initialize result of factorial
	factorial[0] = 1; // set to one so if n = 1 then 1 will be returned
					  // Please note factorial result will be backwards (i.e. 4! = 24)
					  // Therfore factorial[] = [4,2]
	int factorial_size = 1; // set size of result to one

	// Apply simple factorial formula factorialSeed! = 1 * 2 * 3 * 4 * ... * factorialSeed
	// If factorialSeed is 1 loop will be skipped because 1! = 1
	for (int x = 2; x <= factorialSeed; x++) { // loop through 2 * 3 * 4 * ... * factorialSeed
		factorial_size = multiply(x, factorial, factorial_size);
	}

	cout << "Factorial of given number is: " << factorialSeed << "! = ";
	for (int i = factorial_size - 1; i >= 0; i--) { // print factorial result starting at end of factorial[]
													// since factorial[] last number is the first number in factorial result 
		cout << factorial[i];
	}
}

/*
multiply
This function multiplies multiplicand with the number 
represented by factorial[i].
factorial_size is size of factorial[] or number of digits in the
number represented by factorial[]. This function uses simple 
school mathematics for multiplication meaning it multilies the factorial by multiplicand
one by one and checks if there is a carry (i.e. 6 * 4 has a carry of 2).
This function returns the new value of factorial_size
adapted from: https://www.geeksforgeeks.org/factorial-large-number/
Param:
multiplicand is the multiplicand to by whichever decimal place factorial[i] is currently
factorial[] is the result array. Increases in size when carry isnt 0 after multiplying each number in array
factorial_size is the size of the array
*/
int multiply(int multiplicand, int factorial[], int factorial_size)
{
	int carry = 0;  // Initialize carry to added to product if prod is greater than 9
					
	for (int i = 0; i<factorial_size; i++) // One by one multiply the multiplicand with individual digits of res[]
	{
		int product = factorial[i] * multiplicand + carry; // multiple the current decimal place by the current multiplicand and add carry if neccesary

		// Store last digit of 'product' in res[]  
		factorial[i] = product % 10; // gives you the digit the belongs in res array 
							// which is equivalent where the number belongs in the larger number
							// i.e. factorial[3] is the 100th place and factorial[6] is 100,000th place 
							// 6 % 10 would and i = 3 would mean the factorial is 600 and change

		// Put rest in carry
		carry = product / 10; // this will be added to the next product
						   // if greater than 10 then carry is will be added to next product
						   // otherwise there is not a carry because of interger division the remainder isnt a factor

	}

	// Put carry in res and increase result size
	// If carry is not zero it needs to be added to the array
	// Loop while execute until carry reaches zero
	while (carry)
	{
		factorial[factorial_size] = carry % 10; // new value added to array
		carry = carry / 10; // set carry to be added to next product until carry is zero to exits loop
		factorial_size++; // increase the size of the number array
	}
	return factorial_size;
}