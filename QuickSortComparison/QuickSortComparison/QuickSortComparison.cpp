// QuickSortComparison.cpp : Class AbstractSort that can be used to analyze the number of comparisons performed by a sorting algorithm
// The class has a member function compare that is capable of comparing two array elements, and a means of keeping track of the number of comparisons performed
// The class is an abstract class with a pure virtual member function void sort(int* arr, int size)
// Sort is a subclass of AbstractSort that uses a QUICKSORT algorithm to implement the sort function
// The class has a member function that can be called after the sorting is done to retrieve the number of comparisons performed
// Adam Tucker
// 06/23/18

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Prototype Functions
int getNumberOfInputs();
void inputNumbers(int *, int);

/*
AbstractSort
A abstract class for sorting an array
*/
class AbstractSort {
public:
	int numberOfComparisons = 0; // number of comparison member variable

	/*
	compare
	Member function that increments number of comparisons and compares two numbers and
	returns the results
	Param:  a - number to compared
			b - number to compare too
	Return: True if a < b and false otherwise
	*/
	bool compare(int a, int b) {
		numberOfComparisons++;
		return a < b;
	}

	/*
	sortArr
	Pure virtual function that will sort an array
	Param:  arr - array to be sorted
	size - size of the array
	*/
	void virtual sortArr(int* arr, int size) = 0;
};

class Sort : public AbstractSort {
public:

	/*
	getComparison
	Gets the comparison member variable and returns its value
	*/
	int getComparison() {
		return numberOfComparisons;
	}

	/*
	sortArr
	Sorts an array of number using quickSort algorithm found at:
	https://www.geeksforgeeks.org/cpp-program-for-quicksort/
	*/
	void sortArr(int* arr, int size) {
		Sort::quickSort(arr, 0, size-1); // sort test scores in ascending with helper function compare
	}

	/* 
	partition
	This function takes last element as pivot, places
	the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
	to left of pivot and all greater elements to right
	of pivot 
	Param:  arr - pointer to array to be sorted
			low - lowest index in array
			high - highest in index in array
	adapted from: https://www.geeksforgeeks.org/cpp-program-for-quicksort/ */
	int partition(int* arr, int low, int high)
	{
		int pivot = *(arr + high);    // pivot
		int i = (low - 1);  // Index of smaller element

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than or
			// equal to pivot
			if (*(arr + j) <= pivot)
			{
				i++;    // increment index of smaller element
				swap(arr+i, arr + j);
			}
		}
		swap(arr + i + 1, arr + high);
		return (i + 1);
	}

	/* 
	quickSort
	The main function that implements QuickSort
	Param:  arr - array to be sorted
			low - Starting index
			high - Ending index 
	adapted from: https://www.geeksforgeeks.org/cpp-program-for-quicksort/ */
	void quickSort(int *arr, int low, int high)
	{
		if (compare(low, high))
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

	/* 
	swap
	A utility function to swap two elements
	Param:  a - int to be swapped with b
			b - int to be swapped with a
	adapted from : https://www.geeksforgeeks.org/cpp-program-for-quicksort/ */
	void swap(int* a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
};

int main()
{
	Sort* sort = new Sort();
	bool done = false; // flag for program loop
	char choice; // choice to end program
	int numInputs; // number from user
	int* arrayOfNumbers; // pointer to a int
	cout << "Welcome to the Array Sorting Program using Quick Sort!" << endl;

	while (!done) { // Main Program loop
		numInputs = getNumberOfInputs(); // get the how many numbers will be input
		arrayOfNumbers = new int[numInputs]; // make memory for numbers in array
		inputNumbers(arrayOfNumbers, numInputs); // get the numbers from the user and put them in the array
		sort->sortArr(arrayOfNumbers, numInputs); // print array in ascending order
		cout << "Here is the sorted array [ ";
		for (int count = 0; count < numInputs; count++)   // print numbers in ascending order
		{
			cout << *(arrayOfNumbers + count) << " "; // print current number
		}
		cout << "]\nThe sorter made " << sort->getComparison() << " comparisons." << endl; // output number of comparison
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
			sort->numberOfComparisons = 0; // reset number of comparisons
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
	int number; // init 
	cout << "Please enter a positive number for the amount of numbers to be sorted." << endl; // Prompt user
	while (!(cin >> number) || number <= 0) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please enter a positive number." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return number; // return positive integer
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
			cout << "Bad Input!!! Please enter a number you want to be added.\n" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		*(numbers + count) = myNumber; // input positive number into array
	}
}