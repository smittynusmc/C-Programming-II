// Punch Line.cpp : Program that reads and prints a joke and its punch line from two different files. 
// The first file contains a joke but not its punch line. The second file has the punch line as its last line, preceded by “garbage.” 
// The main function opens the two files and then calls two functions, passing each one the file it needs. 
// The first function reads and display each line in the file it is passed (the joke file). 
// The second function displays only the last line of the file it is passed (the punch line file). 
// Data for the program can be found in the joke.dat and punchline.dat files.
// Adam Tucker
// 06/03/18

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void askJoke(ifstream &); // prints jokes in file
void givePunchLine(ifstream &); // prints last line in ifstream

int main()
{
	ifstream jokes("joke.txt"); // init ifstream with jokes file
	ifstream punchLines("punchline.txt",ios_base::ate); // init ifstream with punchline file
	ifstream jokesTwo("joke2.txt"); // init ifstream with jokes file
	ifstream punchLinesTwo("punchline2.txt", ios_base::ate); // init ifstream with punchline file

	cout << "Welcome to the Punch Line Comedy Club! Let's start with a simple joke!\n" << endl;

	askJoke(jokes); // call function that prints jokes in joke file
	cout << "\n";
	givePunchLine(punchLines); // call function the prints punchline 
	jokes.close(); // close jokes ifstream
	punchLines.close(); // close punchline ifstream
	cout << "\nHaha! Hope that was funny enough! Here comes a knock knock joke!\n" << endl;
	askJoke(jokesTwo); // call function that prints jokes in joke file
	cout << "\n";
	givePunchLine(punchLinesTwo); // call function the prints punchline 
	jokes.close(); // close jokes ifstream
	punchLines.close(); // close punchline ifstream
	cout << "\nHope you had some luaghs!" << endl;
	return 0;
}

/*
askJoke
Prints all jokes in joke file line by line
*/
void askJoke(ifstream &jokes) {
	string line; // string for each line
	while (!jokes.eof()) { // while not at end of file
		getline(jokes, line); // get the current line
		cout << line << endl; // print to screen
	}
}
/*
givePunchLine
Starting at the end of the file looks for the first escape character 
and the prints the last line
//http://www.programmersbook.com/page/7/Get-last-line-from-a-file-in-C/
*/
void givePunchLine(ifstream &punchLine) {
	string tmp; // string to hold last line
	int length = 0; // length of file
	char isEscape = '\0'; // init 

	if (punchLine) {
		length = punchLine.tellg();//Get file size

		for (int i = length - 2; i > 0; i--) { // loop backwards over the file
			punchLine.seekg(i); // set position of next character to be extracted from file
			isEscape = punchLine.get(); // get the current character in file
			if (isEscape == '\r' || isEscape == '\n') // if found an escape character end of file was found
				break;
		}

		getline(punchLine, tmp);// read last line
		cout << tmp << endl; // print the last lune

	}
}