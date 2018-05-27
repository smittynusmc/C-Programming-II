// Name Arranger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string line;
	char first[100], middle[100], last[100];
	char conversion[300];
	char comma[3] = { ',' , ' ' , '\0' };
	char space[2] = { ' ' , '\0'};
	char *ptr[3];
	ptr[0] = first;
	ptr[1] = middle;
	ptr[2] = last;
	bool done = false;
	char choice;
	while (!done) {
		cout << "Please enter your First, Middle and Last name. Example, John Lee Smith." << endl; // Prompt user
		getline(cin, line);
		istringstream iss(line);
		for (int i = 0; i < 3; i++) {
			getline(iss, line, ' ');
			char *temp = ptr[i];
			for (int j = 0; j < line.length(); j++) {
				temp[j] = line[j];
			}
			temp[line.length()] = '\0';
		}
		strcpy_s(conversion, last);
		strcat_s(conversion, comma);
		strcat_s(conversion, first);
		strcat_s(conversion, space);
		strcat_s(conversion, middle);
		cout << conversion << endl;
		cout << "\nWould you like enter another full name? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
		cin >> choice;
		while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to continue the Lottery or N or n to quit." << endl; // prompt user input correct choice
			cin >> choice;
		}
		if (choice == 'y' || choice == 'Y') { // user choose to run lottery for next week
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		else {
			done = true; // user felt unlucky and quit program
		}
	}

}

