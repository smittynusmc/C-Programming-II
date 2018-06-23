// Recursive_Sum.cpp : A program that asks the user to enter an array of numbers and a value to be searched for.
// Adam Tucker
// 06/16/18

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Prototype Functions
int getNumberOfInputs();
void inputNumbers(int *, int);

class AbstractSort {
public:
	static int numberOfComparisons; // number of comparison member variable

	static bool compare(int a, int b) {
		numberOfComparisons++;
		return a < b;
	}

	void virtual sortArr(int* arr, int size) = 0;
};

class Sort : public AbstractSort {
public:

	void sortArr(int* arr, int size) {
		Sort::quickSort(arr, 0, size); // sort test scores in ascending with helper function compare
	}

	/* This function takes last element as pivot, places
	the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
	to left of pivot and all greater elements to right
	of pivot */
	int partition(int* arr, int low, int high)
	{
		int pivot = *(arr + high);    // pivot
		int i = (low - 1);  // Index of smaller element

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than or
			// equal to pivot
			if (arr[j] <= pivot)
			{
				i++;    // increment index of smaller element
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i + 1], &arr[high]);
		return (i + 1);
	}

	/* The main function that implements QuickSort
	arr[] --> Array to be sorted,
	low  --> Starting index,
	high  --> Ending index */
	void quickSort(int arr[], int low, int high)
	{
		if (compare(low,high))
		{
			/* pi is partitioning index, arr[p] is now
			at right place */
			int pi = partition(arr, low, high);

			// Separately sort elements before
			// partition and after partition
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}

	// A utility function to swap two elements
	void swap(int* a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
};

int Sort::numberOfComparisons = 0;

int main()
{
	Sort* sort = new Sort();
	bool done = false; // flag for program loop
	char choice; // choice to end program
	int numInputs; // number from user
	int* arrayOfNumbers; // pointer to a double
	cout << "Welcome to the Number Locator!" << endl;

	while (!done) { // Main Program loop
		numInputs = getNumberOfInputs(); // get the how many numbers will be input
		arrayOfNumbers = new int[numInputs]; // make memory for numbers in array
		inputNumbers(arrayOfNumbers, numInputs); // get the numbers from the user and put them in the array
		sort->sortArr(arrayOfNumbers, numInputs);
		cout << "Here is the sorted array [";
		for (int count = 0; count < numInputs; count++)   // print test scores in ascending order
		{
			cout << *(arrayOfNumbers + count); // print student name and number of movies seen
		}
		cout << "]\nThe sorter made " << sort->numberOfComparisons << " comparisons." << endl;
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
getNumberOfInputs
Asks the user the number of numbers to be input
and checks if the user entered a positive number greater than zero
and returns the number to numbers the user will input
*/
int getNumberOfInputs()
{
	int numberOfTestScores; // init number of test scores
	cout << "Please enter a positive number for the amount of numbers to be sorted." << endl; // Prompt user
	while (!(cin >> numberOfTestScores) || numberOfTestScores <= 0) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please enter a positive number for the amount of numbers to be searched through." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfTestScores; // return positive integer
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
	int myNumber; // init temp number variable
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