// SequenceVector Mod.cpp : SearchableVector class template that performs a binary search instead of a linear search
// Adam Tucker
// 07/21/18

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std; 
// Exception for index out of range
struct IndexOutOfRangeException { 
	const int index;
	IndexOutOfRangeException(int ix) : index(ix) {}
};

// Simple Class Vector from book
template <class T>
class SimpleVector { 

	int arraySize;

public:
	
	unique_ptr<T[]> aptr;
	SimpleVector(int);
	SimpleVector(const SimpleVector &);
	int size() const { return arraySize; }
	T &operator[](int); // Overloaded [] operator
	void print() const; // Outputs the array elements
}; 

//*******************************************************
// Constructor for SimpleVector class. Sets the size *
// of the array and allocates memory for it. *
//*******************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s) {
	arraySize = s;
	aptr = make_unique<T[]>(s);
	for (int count = 0; count < arraySize; count++) {
		aptr[count] = T();
	}
}

//******************************************************
// Copy Constructor for SimpleVector class. *
//******************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
	arraySize = obj.arraySize;
	aptr = make_unique<T[]>(arraySize);
	for (int count = 0; count < arraySize; count++) {
		//obj.aptr[count];
		aptr[count] = obj.aptr[count];
	}
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element *
// in the array indexed by the subscript. *
//*******************************************************
template <class T>
T &SimpleVector<T>::operator[](int sub) {
	if (sub < 0 || sub >= arraySize) {
		throw IndexOutOfRangeException(sub);
		return aptr[sub];
	}
}

//********************************************************
// prints all the entries is the array.
//*************************************************
template <class T>
void SimpleVector<T>::print() const {
	for (int k = 0; k < arraySize; k++) {
		cout << aptr[k] << " ";
		cout << endl;
	}
}

 template <class T>
 class SearchableVector : public SimpleVector<T>
 { 
 
	public:
		// Constructor.
		SearchableVector(int s) : SimpleVector<T>(s) { } 
		// Copy constructor.
		SearchableVector(const SearchableVector &);
		// Additional constructor.
		SearchableVector(const SimpleVector<T> &obj) : SimpleVector<T>(obj) { } 
		int findItem(T,T,T);
 };
 
 //******************************************
 // Definition of the copy constructor. *
 //******************************************
 template <class T>
 SearchableVector<T>::SearchableVector(const SearchableVector &obj) : SimpleVector<T>(obj) { }
 //******************************************
 // findItem takes a parameter of type T *
 // and searches for it within the array. *
 // Implemented like binary search
 // https://www.geeksforgeeks.org/binary-search/
 //******************************************
 template <class T> 
 int SearchableVector<T>::findItem(T l, T r, T item) {
	 if (r >= l)
	 {
		 int mid = l + (r - l) / 2;

		 // If the element is present at the middle 
		 // itself
		 if (this->aptr[mid] == item) {
			 return mid;
		 }

		 // If element is smaller than mid, then 
		 // it can only be present in left subarray
		 if (this->aptr[mid] > item) {
			 return findItem(l, mid - 1, item);
		 }

		 // Else the element can only be present
		 // in right subarray
		 return findItem(mid + 1, r, item);
	 }

	 // We reach here when element is not 
	 // present in array
	 return -1;

 }

 // Helper Function prototypes
int getInput();
double getDoubleInput();
void inputDoubleNumbers(SearchableVector<double>*, int);
void inputIntegerNumbers(SearchableVector<int>*, int);


int main()
{
		bool done = false; //flag for program loop 
		char choice; // user choice to continue program
		int numInputs, searching, found; // size of numbers to be put in array
		cout << "Welcome to Addition Calculator" << endl;

		while (!done) { // Main Program loop
			cout << "Numbers of integers you want to input?" << endl; // Ask user for number of inputs
			numInputs = getInput(); // get number from user
			SearchableVector<int> intTable(numInputs); // init searchable vector
			inputIntegerNumbers(&intTable, numInputs); // get the array of numbers from the user
			cout << "What number integer would you like to search for?" << endl;
			searching = getInput(); // get the number to be searched for
			found = intTable.findItem(0, intTable.size(), searching); // find the the number
			if (!(found == -1)) { // if number not found "found" is -1
				cout << "WE FOUND " << searching << " at index " << found <<"! YAY!" << endl;
			}
			else {
				cout << "WAWAWA!!! No luck finding the number!" << endl;
			}
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
getInput
Asks the user the number of numbers to they will input
and checks if the user entered a positive number greater than zero
and returns the number input by the user
*/
int getInput()
{
	int numberOfInputs; // init number for user input
	cout << "Please enter a positive number." << endl; // Prompt user
	while (!(cin >> numberOfInputs) || numberOfInputs <= 0) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please enter a positive number for the amount of numbers to be added together." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfInputs; // return positive integer for number input by user
}

/*
getDoubleInput
Asks the user the number of numbers to they will input
and checks if the user entered a positive number greater than zero
and returns the number input by the user
*/
double getDoubleInput()
{
	double numberOfInputs; // init number for user input
	cout << "Please enter a positive number." << endl; // Prompt user
	while (!(cin >> numberOfInputs) || numberOfInputs <= 0) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please enter a positive number for the amount of numbers to be added together." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfInputs; // return positive integer for number input by user
}

/*
inputDoubleNumbers
Asks the user for each number of type double to be input
and puts the number in array
Param: numbers - the object to hold numbers input by the user
size - the size of the array
*/
void inputDoubleNumbers(SearchableVector<double>* numbers, int size)
{
	double myNumber; // init temp number variable
	for (int count = 0; count < size; count++) {
		cout << "Please enter your number. Negative Numbers are ok!\n#" << (count + 1) << ". "; /// prompt user
		while (!(cin >> myNumber)) { // check if the user input a number
			cout << "Bad Input!!! Please enter a number you want to be added with the other numbers.\n#" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		numbers->aptr[count] = myNumber; // put number in vector array
	}
}

/*
inputIntegerNumbers
Asks the user for each number of type int to be input
and puts the number in array
Param: numbers - the object to hold numbers input by the user
size - the size of the array
*/
void inputIntegerNumbers(SearchableVector<int>* numbers, int size)
{
	int myNumber; // init temp number variable
	for (int count = 0; count < size; count++) {
		cout << "Please enter your number. Negative Numbers are ok!\n#" << (count + 1) << ". "; /// prompt user
		while (!(cin >> myNumber)) { // check if the user input a number
			cout << "Bad Input!!! Please enter a number you want to be added with the other numbers.\n#" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		numbers->aptr[count] = myNumber; // put number in vector array
	}
}
