// NameArranger.cpp : The program asks for the user’s first, middle, and last names. 
// The names are stored in three different character arrays. 
// The program stores in a fourth array the name arranged in the following manner: 
// The last name followed by a comma and a space, followed by the first name and a space, followed by the middle name. 
// For example, if the user entered “Carol Lynn Smith”, it should store “Smith, Carol Lynn” in the fourth array. 
// Contents of the fourth array are displayed on the screen.
// Adam Tucker
// 05/27/18

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void setArrays(char *ptr[]); // set first, middle and last names to appropriate char arrays
string getName(string); // get the name requested and check for proper name (i.e no numbers)
void retrieveInput(char*,string); // go through array of pointers to c-strings, get names and put in char arrays
template<class InputIterator, class UnaryPredicate>
bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred); // any_of checks if input from user contains numbers

// Main Function
int main() {
	char firstName[100], middleName[100], lastName[100]; // 3 characters arrays
	char nameArranged[300]; // fourth character array
	char comma[3] = { ',' , ' ' , '\0' }; // comma used in final display. Null termintor allows for proper char array
	char space[2] = { ' ' , '\0'}; // space used in final display. Null termintor allows for proper char array
	char *ptr[] = { firstName, middleName, lastName }; // pointer to char arrays
	bool done = false; // flag for program loop
	char choice; // choice to continue or end program
	cout << "-----------------------------------------------------------" << endl;
	cout << "Welcome to the Name Arranger Program!" << endl;
	cout << "Where a full name is converted to something special" << endl;
	cout << "Amazingly John Joe Smith is converted to Smith, John Joe!!!" << endl;
	cout << "-----------------------------------------------------------" << endl;
	while (!done) { // Main Program loop
		setArrays(ptr); // Go set first, middle and last name char arrays from user input
		strcpy_s(nameArranged, lastName); // copy middle name to front of name arranged fourth char array
		strcat_s(nameArranged, comma); // add a comma/space to fourth char array
		strcat_s(nameArranged, firstName); // add first name to fourth char array
		strcat_s(nameArranged, space); // add space to fourth char array
		strcat_s(nameArranged, middleName); // add last name to fourth char array
		cout << "Wow, the full name entered has been converted to: " << nameArranged << "\nThat is a amazing!" << endl; // display final conversion to screen
		cout << "\nWould you like see another full name to be converted? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
		cin >> choice;
		choice = toupper(choice);
		while (!(choice == 'Y' || choice == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to enter another Full Name or N or n to quit." << endl; // prompt user input correct choice
			cin >> choice;
		}
		if (choice == 'Y') { // user choose to run program again
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		else {
			done = true; // user quit program
		}
	}

}

/*
setArrays
Loops through pointer to character arrays and retrieves input from user
Param: pointer to character arrays 
*/
void setArrays(char *ptr[]) {
	string nameTypes[] = { "first","middle","last" }; // strings of names being asked for input
	for (int i = 0; i < sizeof(nameTypes) / sizeof(nameTypes[0]); i++) { // loop through pointer to character arrays. Size of nameTypes is loop condition 
		cout << "Please enter a " << nameTypes[i] << " name: "; /// prompt user
		retrieveInput(ptr[i], nameTypes[i]); // retrieve input
	}
}

/*
getName
Gets the user input and checks if myName contains digits
Param: The name the user is to input (i.e. firstName)
*/
string getName(string whichName) {
	string myName; // name to be returned
	while (!(cin >> myName) || any_of(myName.begin(), myName.end(), isdigit)) // check if the user input a string
	{
		cout << "Bad Input!!! Check to see if your name contained numbers!!!\nPlease enter a " << whichName << " name: ";  // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return myName;
}

/*
retrieveInput
Get whichName (first, middle, last etc) from user and copy into temp which is pointer to whichNames respective character arrays 
Param: ptr - pointer to character arrays 
	   whichName - for prompt to tell user which part of name is expected (i.e. first name)
*/
void retrieveInput(char *ptr, string whichName) {
	string myName = getName(whichName); // Get input from user
	char *temp = ptr; // assign a temp char ptr
	for (int j = 0; j < myName.length(); j++) {
		temp[j] = myName[j]; // copy string to char array
	}
	temp[myName.length()] = '\0'; // Null termintor allows for proper char array
}

/*
any_of
Compiler wasn't recognizing any_of so I found the implented version and added it
Copied from:
http://www.cplusplus.com/reference/algorithm/any_of/
*/
template<class InputIterator, class UnaryPredicate>
bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred)
{
	while (first != last) {
		if (pred(*first)) return true;
		++first;
	}
	return false;
}