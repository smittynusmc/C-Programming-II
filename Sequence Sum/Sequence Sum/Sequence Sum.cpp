// Sequence Sum.cpp :  Abstract class AbstractSeq  has a pure virtual member function virtual int fun(int k) = 0;
// as a stand - in for an actual sequence, and two member functions
// void printSeq(int k, int m);
// int sumSeq(int k, int m)
// that are passed two integer parameters k and m, where k < m.
// The function printSeq prints all the terms fun(k) through fun(m) of the sequence, and likewise, 
// the function sumSeq returns the sum of those terms.
// Adam Tucker
// 06/23/18

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Prototype functions
int getNumberEvenOrOdd();

/*
AbstractSeq
A abstract class for outputting and summing a sequence of number between k and m (k < m)
*/
class AbstractSeq {
public:
	int sum = 0; // variable for sequence summation
	int low, high; // kth and mth terms

	/*
	printSeq
	Prints the an odd or even sequence from kth term of the sequence to the mth term
	Even Example - low = 2 and high = 5 sequence would be 4 6 8 10 and sum = 28
	Remember the 0th term is 0
	Param - low - kth term
			high - mth term
	*/
	void printSeq(int low, int high) {
		cout << "Your sequence from " << low << "th term to " << high << "th term is:" << endl;
		for (int lowNum = low; lowNum <= high; lowNum++) {
			cout << fun(lowNum) << " ";
			sum = sum + fun(lowNum);
		}
		cout << "\nThe sum of the sequence above is " << sum << endl;
	}

	/*
	sumSeq
	Assignment required a sumSeq method that takes to parameters.
	Another for loop could go in here but isnt needed since printSeq is already doing that
	Therefore sumSeq adds the kth number and mth number together and returns the results
	Param - low - kth term
			high - mth term
	Return = k + m
	*/
	int sumSeq(int k, int m) {
		return  k + m;
	}

	/*
	setLow
	Mutator method sets low by getting input from user
	*/
	void setLow() {
		low = getLowInput();
	}

	/*
	setHigh
	Mutator method sets high by getting input from user
	*/
	void setHigh(int min) {
		high = getHighInput(min);
	}

	/*
	getLowInput
	Asks the user the for the kth value in the sequence to start
	and checks if the user entered a positive
	and returns kth value
	*/
	int getLowInput()
	{
		int number; // init number of test scores
		cout << "Please input the kth term." << endl;
		while (!(cin >> number) || number < 0) { // check if the user input a number and check it is greater than zero
			cout << "Bad Input!!! Please enter an positive number or zero." << endl; // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		return number; // return positive integer
	}

	/*
	getHighInput
	Asks the user the for the mth value in the sequence to end
	and checks if the user entered a positive greater the low memeber variable
	and returns mth value
	*/
	int getHighInput(int min)
	{
		int number; // init number of test scores
		cout << "Please input the mth." << endl;
		while (!(cin >> number) || min > number) { // check if the user input a number and check it is greater than zero
			cout << "Bad Input!!! Please enter a number greater than " << min << endl; // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		return number; // return positive integer
	}

	/*
	fun
	Pure virtual function that will return the kth number in the sequence
	Param:  k - kth element in the sequence
	*/
	virtual int fun(int k) = 0;

};

/*
Odd - Odd class represents a sequence of odd numbers
*/
class Odd : public AbstractSeq {
public:

	/*
	fun
	Pure virtual function that will return the kth number in an odd sequence
	Param:  k - kth element in the sequence
	*/
	virtual int fun(int k) {
		return 2 * k + 1; // return next odd number
	}
};

/*
Even - Even class represents a sequence of even numbers
*/
class Even : public AbstractSeq {
public:

	/*
	fun
	Pure virtual function that will return the kth number in an even sequence
	Param:  k - kth element in the sequence
	*/
	virtual int fun(int k) {
		return 2 * k; // return next even number
	}
};
//

int main()
{
	AbstractSeq* sequence; // save memory for classes the implement AbstractSeq
	bool done = false; // flag for program loop
	char choice; // choice to end program
	cout << "Welcome to the Odd or Even Sequence Program!" << endl;

	while (!done) { // Main Program loop
		if (getNumberEvenOrOdd()) { // asks user if they want an odd or even sequence of numbers
			sequence = new Odd(); // init odd class
		}
		else {
			sequence = new Even(); // init even class
		}
		sequence->setLow(); // set the kth value
		sequence->setHigh(sequence->low); // set the mth value in the sequence
		sequence->printSeq(sequence->low,sequence->high); // Requirements said printSeq must take two parameters
														  // In the real world I would have just used the member variables
														  // PrintSeq prints the sequence and its summation
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
getNumberEvenOrOdd
Asks the user if they want an odd to input 0 or even number sequence to input 1
and returns 1 for even and 0 for odd and otherwise asks the user to input a 1 or 0 again
*/
int getNumberEvenOrOdd()
{
	int number; // init number of test scores
	cout << "Please input a 0 for a even sequence or 1 for Odd sequence" << endl;
	while (!(cin >> number) || number < 0 || number > 1) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please either 1 for even or 0 for Odd." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return number; // return positive integer
}

