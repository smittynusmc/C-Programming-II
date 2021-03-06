// Sequence Accumulation.cpp : Contains a function that forms and returns the “sum” 
// of all items in the vector v passed to it. For example, if T is a numeric type such as int or double, 
// the numeric sum will be returned, and if T represents the STL string type, then the result of concatenation is returned.
// Also, includes a driver program that asks the user to enter three integers, uses accum to compute the sum, 
// and prints out the sum. The program than asks the user to enter three strings, 
// uses accum to concatenate the strings, and prints the result.
// Adam Tucker
// 07/20/18

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
int accumInt(int);
double accumDouble(int);
string accumString(int);

// Template accummulation function
template <class T>
T accum(vector<T> numbers) {
	T* sum_of_elems = new T(); // result for variable
	for (int i = 0; i < numbers.size(); i++) { // sum each numbers in the vector
		*sum_of_elems += numbers[i];
	}
	return *sum_of_elems; // return the result
}


// Main Function
int main()
{
	bool done = false; // flag for program loop
	char choice; // choice to end program

	cout << "Welcome to Sequence Accumulation!" << endl;

	while (!done) { // Main Program loop
		cout << "The sum is: " << accumInt(3) << endl; // accumulatuion for int
		cout << "The sum is: " << accumDouble(3) << endl; // accummulation for double
		cout << "The sum is: " << accumString(3) << endl; // accummulation for string
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
accumInt
Asks the user the number of numbers to they will input
and checks if the user entered a positive number greater than zero
and returns the accumulated result
*/
int accumInt(int size) {
	vector<int> numbers;
	for (int count = 0; count < size; count++) {
		int value;
		cout << "Please enter your integer. Negative Numbers are ok!\n#" << (count + 1) << ". "; /// prompt user
		while (!(cin >> value)) // check if the user input a positive number
		{
			cout << "Bad Input!!! Please enter a number!\n#" << (count + 1) << ". "; // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		numbers.push_back(value); // input positive number into array
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return accum(numbers);
}

/*
accumDouble
Asks the user the number of numbers to they will input
and checks if the user entered a positive number greater than zero
and returns the accumulated result
*/
double accumDouble(int size) {
	vector<double> numbers;
	for (int count = 0; count < size; count++) {
		double value;
		cout << "Please enter your decimal. Negative Numbers are ok!\n#" << (count + 1) << ". "; /// prompt user
		while (!(cin >> value)) // check if the user input a positive number
		{
			cout << "Bad Input!!! Please enter a number!\n#" << (count + 1) << ". "; // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		numbers.push_back(value); // input positive number into array
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return accum(numbers);
}

/*
accumString
Asks the user the number of numbers to they will input
and checks if the user entered a positive number greater than zero
and returns the accumulated result
*/
string accumString(int size) {
	vector <string> myString;
	for (int count = 0; count < size; count++) {
		string value;
		cout << "Please enter a word. Sentences are ok! If you want space at the end or beginning you must add them!\n#" << (count + 1) << ". "; /// prompt user
		getline(cin,value);
		myString.push_back(value); // input positive number into array
	}
	return accum(myString);
}