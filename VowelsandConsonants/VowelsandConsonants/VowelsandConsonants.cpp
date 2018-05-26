// Theater Ticket Sales.cpp : The program should count the number of vowels and consonants appearing in the string and return that number.
// The menu allows the user to choose to count vowels, consonants and vowels/consonants, enter a new string and end the program
// Adam Tucker
// 05/25/18

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int countVowels(const char*); // counts the number of vowels in c-string
int countConsonants(const char*); // counts the number of vowels in c-string
bool isVowel(char); // returns true if vowel and false otherwise
bool isConsonant(char); // returns true if consonant and false otherwise



int main()
{
	//
	bool isDone = false;
	char sentence[500] = { '\0' };
	int numVowels, numConsonants, numLetters, charLength;


	cout << "Welcome to Vowels and Consonant Counter!" << endl;
	cout << "Type the letter for the menu choice you want then press 'Enter' \n" << endl;

	while (!isDone) {
		char menuChoice;

		cout << "----------------------------------------" << endl;
		cout << "A. Count Number of Vowels" << endl;
		cout << "B. Count Number of Consonants" << endl;
		cout << "C. Count Number of Consonants and Vowels" << endl;
		cout << "D. Enter another string" << endl;
		cout << "E. Exit Program" << endl;
		cout << "----------------------------------------" << endl;
		cin.get(menuChoice);
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		menuChoice = toupper(menuChoice);
		switch (menuChoice)
		{
		case 'A':
			if (sentence[0] != '\0') {
				cout << "Current Sentence is: " << sentence << endl;
				numVowels = countVowels(sentence);
				cout << "Number of vowels are in sentence: " << sentence << " is " << numVowels << endl;
			}
			else {
				cout << "You have not entered a sentence. Choose D to enter a sentence" << endl;
			}
			break;

		case 'B':
			if (sentence[0] != '\0') {
				cout << "Current Sentence is: " << sentence << endl;
				numConsonants = countConsonants(sentence);
				cout << "Number of consonants are " << numConsonants << endl;
			}
			else {
				cout << "You have not entered a sentence. Choose D to enter a sentence" << endl;
			}
			break;

		case 'C':
			if (sentence[0] != '\0') {
				cout << "Current Sentence is: " << sentence << endl;
				numLetters = countVowels(sentence) + countConsonants(sentence);
				cout << "Number of consonants and vowels are " << numLetters << endl;
			}
			else {
				cout << "You have not entered a sentence. Choose D to enter a sentence" << endl;
			}
			break;

		case 'D':
			cout << "Please, enter your sentence: ";
			cin.getline(sentence, 256);
			cout << "\nCurrent Sentence is: " << sentence << endl;
			break;

		case 'E':
			//quit
			cout << "Thanks! Have a nice life!!!" << endl;
			isDone = true;
			break;
		default:
			
			cout << "Incorrect Menu Choice. Try again!" << endl;
		}
	}
	return 0;
}


int countVowels(const char *ch)
{
	int numVowel = 0;
	for (int i = 0; i < strlen(ch); i++) {
		if (isVowel(ch[i])) {
			numVowel++;
		}
	}
	return numVowel;
}

int countConsonants(const char *ch)
{
	int numConsonant = 0;
	for (int i = 0; i < strlen(ch); i++) {
		if (isConsonant(ch[i])) {
			numConsonant++;
		}
	}
	return numConsonant;
}


/*
Adapted from: https://stackoverflow.com/questions/21810895/vowels-in-string-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
bool isVowel(char ch)
{
	return std::strchr("aeiouAEIOU", ch) != NULL; 

}

/*
Adapted from: https://stackoverflow.com/questions/21810895/vowels-in-string-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
bool isConsonant(char ch)
{
	return std::strchr("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", ch) != NULL;

}
