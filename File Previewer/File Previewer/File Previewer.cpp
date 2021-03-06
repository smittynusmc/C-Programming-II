// Week4_Initial_Post_Code.cpp : Program that asks the user for the name of a text file. 
// The program displays the first 10 lines of the file on the screen. 
// If the file has fewer than 10 lines, the entire file is displayed along with 
// a message indicating the entire file has been displayed.
// Adam Tucker
// 06/03/18

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void preview(ifstream &); // preview file
string getFileName(); // get file name from user
bool notContainsDotText(string &); // check if filename contains .txt extension


int main()
{
	bool isDone = false; // flag for main loop
	string fileName; // fileName input by user
	ifstream userFile; 	// file stream to read from file

	cout << "Welcome to File Previewer!" << endl;

	while (!isDone) { // main loop
		char choice; // int user choice to continue program
		fileName = getFileName(); // get the user file name
		userFile.open(fileName); // open the file
		preview(userFile); // preview first 10 or fewer lines of file 
		userFile.close(); // close file stream
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
preview
Displays first 10 lines or less of the user file selected.
Functions informs user if file contained 9 lines or less 
*/
void preview(ifstream &userFile) {
	string line; // line to printed
	for (int fileLine = 0; fileLine < 10; fileLine++) { // loop through first 10 lines
		if (!userFile.eof()) { // if end of file is not reached print line
			getline(userFile,line); // get current line
			cout << line << endl; // display line
		}
		else { // end of file was reached before 10 lines
			cout << "\n" << "Entire file has been displayed" << endl;
			break; // exit loop
		}
	}
}

/*
getName
Gets the user input and checks if fileName is a proper string.
Checks if input from user has .txt file extenstions and add .txt if needed
Return: the filename to read from
*/
string getFileName() {
	string fileName; // name to be returned
	cout << "Input the text file you would like to preview: ";
	getline(cin, fileName);
	while (fileName.empty()) { // get entire line from user
		cout << "You didnt entire a file name. Input the text file you would like to preview: ";
		getline(cin, fileName);
	}
	if (notContainsDotText(fileName)) { // check to see if input contains .txt extensions
		fileName = fileName + ".txt"; // if it doesn't add it to the file name
	}
	return fileName; // return the filename
}

/*
notContainsDotText
Checks if the string paramater has .txt file extensions
Param: String to evaluated if it contains .txt
Return: True of string contains .txt other false
Adapted from: https://stackoverflow.com/questions/21810895/vowels-in-string-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
bool notContainsDotText(string &fileName)
{
	return fileName.find(".txt") == string::npos;

}