// File Reverser.cpp : Program that opens a text file and reads its contents into a stack of characters. 
// The program then pops the characters from the stack and save them in a second text file. 
// The order of the characters saved in the second file will be the reverse of their order in the first file.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	// create and link input file
	ifstream inputFile;
	inputFile.open("input.txt");
	// create and link output file
	ofstream outputFile;
	outputFile.open("output.txt");

	//error message for file open fail
	if (inputFile.fail())
		cout << "Error opening the file.\n";
	//string array and temporary-use string
	stack <char> x; // init stack
	char myChar; // 
	inputFile >> noskipws; // manipulator to disable the whitespace skipping behavior in streams
	while (inputFile >> myChar) // loop char in input file
	{
		x.push(myChar); // push char on stack
		cout << x.top(); // output in terminal showing correct push onto stack
	}
	inputFile.close(); // close input file
	cout << endl; // start newline

	while (!x.empty()) // loop while stack is not empty
	{
		
		cout << x.top(); // output in terminal showing correct input into output file
		outputFile << x.top(); // output top to output file
		x.pop(); // delete top value from stack
	}
	outputFile.close(); // close output file
	cout << endl;

	return 0;
}
