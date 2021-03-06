// Movie Statistics
// Program dynamically allocates an array of students surveyed structs large enough to hold a user-defined number of number of movies seen and student names.
// Once all the movies seen are entered, the array is sorted in ascending order.
// An average function is called that calculates the average movies seen, mode of movies seen and median of movies seen.
// Program displays the sorted list of movies seen, names and the movies seen average, mode and median with appropriate headings.
// (Gaddis 701)
// Adam Tucker
// 05/11/18
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// Struct of MovieStats
struct MovieStats
{
	string name; // Student Name
	int numberOfMoviesSeen; // Student movies seen

	MovieStats(string myName = "", int myNumberOfMoviesSeen = 0.0) // MovieStats constructor with defaults
	{
		name = myName; // set name member value
		numberOfMoviesSeen = myNumberOfMoviesSeen;  // set movies seen member value
	}
};

// Prototype functions
float mean(MovieStats*, int); // Returns average of an array of movies seen
vector<int> mode(MovieStats*, int); // Returns mode(s) of an array of movies seen
float median(MovieStats*, int); // Returns median of an array of movies seen
int getNumberOfStudentsSurveyed(); // Gets number of students surveyed to be input by user
void inputMoviesSeen(MovieStats*, int); // Gets the movies seen input by user
bool moviesSeen_sorter(MovieStats&, MovieStats&); // prototype helper function to be used for sorting

int main()
{
	bool done = false; // flag for program
	char choice; // choice by user
	while (!done)
	{
		MovieStats* movieStats; // init a pointer to a TestScore
		cout << "Welcome to the Movie Statistics Calculator!" << endl;
		int numberOfStudentsSurveyed = getNumberOfStudentsSurveyed(); // User inputs number of students surveryed
		movieStats = new MovieStats[numberOfStudentsSurveyed]; // Allocate array of doubles and save ptr in testScores
		inputMoviesSeen(movieStats, numberOfStudentsSurveyed); // User inputs test scores
		sort(movieStats, movieStats + numberOfStudentsSurveyed, &moviesSeen_sorter); // sort test scores in ascending with helper function moviesSeenScore_sorter
		cout << fixed << setprecision(2); // set the precision for all doubles printed
		for (int count = 0; count < numberOfStudentsSurveyed; count++)   // print test scores in ascending order
		{
			cout << "Movies seen by " << (movieStats + count)->name << " is " << (movieStats + count)->numberOfMoviesSeen << endl; // print student name and number of movies seen
		}
		cout << "\nAverage movies seen: " << mean(movieStats, numberOfStudentsSurveyed) << endl; // print mean of number of movies seen
		cout << "\Median of movies seen: " << median(movieStats, numberOfStudentsSurveyed) << endl; // print the median of movies seen
		vector<int> resultMode = mode(movieStats, numberOfStudentsSurveyed);
		if (resultMode.size() == 1) { // only one mode
			cout << "\Mode of movies seen is: " << *resultMode.begin() << endl; // print single mode of movies seen
		}
		else if (resultMode.size() > 1) { // multiple modes
			cout << "You have a multi modal set of movies seen! The number of modes is " << resultMode.size()<< " modes." << endl; // print multiple modes of movies seen
			for (vector<int>::iterator it = resultMode.begin(); it != resultMode.end(); ++it) {
				cout << "Mode #" << (it - resultMode.begin()) + 1 << " is " << *it << endl;
			}
		}

		cout << "\nWould you like enter another set of test scores? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
		cin >> choice;
		while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')) // User input a character or string or an incorrect value
		{
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to enter more test scores or N or n to quit." << endl; // prompt user input correct choice
			cin >> choice;
		}
		if (choice == 'y' || choice == 'Y')   // user choose to enter more students surveyed and movies seen
		{
			continue;
		}
		else
		{
			done = true; // change flag to quit program
		}
	}
	return 0;
}

/************************************
mean
Calculates the average of an array of struct with number of movies seen
*************************************/
float mean(MovieStats* myArray, int size)
{
	float sum = 0; // init sum of doubles
	for (int count = 0; count < size; count++)
	{
		sum += (myArray + count)->numberOfMoviesSeen; // add all values together
	}
	return sum / (float)size; // calculate average and return average
}


/************************************
mode
Finds the mode or multiple modes of array of struct with number of movies seen
Adapted from:
http://www.cplusplus.com/forum/beginner/210951/
*************************************/
vector<int> mode(MovieStats* myArray, int size)
{
	vector<int> mode;
	int counter = 0; // counter holds the number of occurrences of current
	int max = counter; // max holds the maximum number of occurrences of any value
	int current = (myArray)->numberOfMoviesSeen; // initialise with start of the array
	mode.push_back(current); // mode holds the modes (i.e. the most frequent values)
	for (int pass = 0; pass < size; pass++) // loop through the remaining elements of myArray
	{
		if ((myArray + pass)->numberOfMoviesSeen == current) // if the same as the current value ...
		{
			counter++;
			if (counter > max) // new modal value
			{
				mode.clear(); // empty the old modal vector ...
				max = counter; // max to counter to indicate maximum count
				mode.push_back(current); // put the new mode in
			}
			else if (counter == max)  // if they have same as the modal value 
			{
				mode.push_back(current); // add to the list of modes
			}
		}
		else { // start counting on a new value
			current = (myArray + pass)->numberOfMoviesSeen;
			counter = 1; // reset counter.
			if (counter == max) { // add to modes only if modal count is 1
				mode.push_back(current);
			}
		}
	}
	if (max == 0) {
		mode.clear();
	}
	return mode;
}

/************************************
median
Finds the median of an array of struct with number of movies seen
*************************************/
float median(MovieStats * movieStats, int size)
{
	float resultMean = 0;
	if (size % 2 == 0) { // if the array size is even
		resultMean = (((movieStats + (size / 2 - 1))->numberOfMoviesSeen + (movieStats + (size / 2))->numberOfMoviesSeen)) / 2.0;
	}
	else { // if the array size is odd
		resultMean = (movieStats + (size / 2))->numberOfMoviesSeen;
	}
	return resultMean;
}

/************************************
getNumberOfStudentsSurveyed
Asks the user the number of students surveyed to be input
and checks if the user entered a positive number greater than zero
and returns the number of students surveyed
*************************************/
int getNumberOfStudentsSurveyed()
{
	int numberOfStudentsSurveyed; // init number of test scores
	cout << "Please enter a positive number of students surveyed." << endl; // Prompt user
	while (!(cin >> numberOfStudentsSurveyed) || numberOfStudentsSurveyed <= 0) // check if the user input a number and check it is greater than zero
	{
		cout << "Bad Input!!! Please enter a positive number of students surveyed." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfStudentsSurveyed; // return positive integer for number of test scores
}

/************************************
inputMoviesSeen
Asks the user for the movies seen to be input
and checks if the user entered a positive number greater than zero
and puts the number of movies seen in the struct
*************************************/
void inputMoviesSeen(MovieStats* movieStats, int size)
{
	int numMoviesSeen; // init temp movies seen variable
	string myName;
	for (int count = 0; count < size; count++)
	{
		cout << "Please enter a name for Student #" << (count + 1) << ". "; /// prompt user
		while (!(cin >> myName) || any_of(myName.begin(), myName.end(), isdigit)) // check if the user input a string
		{
			cout << "Bad Input!!! Check to see if your name contained numbers!!!\nPlease enter a name for Student #" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		(movieStats + count)->name = myName; // input positive number into array
		cout << "Please enter the number of movies seen by " << (movieStats + count)->name << ": "; /// prompt user
		while (!(cin >> numMoviesSeen) || numMoviesSeen <= 0) // check if the user input a number and check it is greater than zero or greater than 100
		{
			cout << "Bad Input!!! Please enter a positive number for number of movies seen.\nEnter number of movies seen by " << (movieStats + count)->name << ": ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		(movieStats + count)->numberOfMoviesSeen = numMoviesSeen; // input positive number into array

	}
}

/*
moviesSeen_sorter
Helper function used to sort an array of MovieStat structs
The Function checks if the left numberOfMoviesSeen is less than the right and returns true or false
*/
bool moviesSeen_sorter(MovieStats& lhs, MovieStats& rhs)
{
	return lhs.numberOfMoviesSeen < rhs.numberOfMoviesSeen; // True if lhs is less than and false otherwise
}