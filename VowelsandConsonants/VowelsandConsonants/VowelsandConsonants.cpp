// Theater Ticket Sales.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

static bool userChoice();


int countVowels(const char*); // counts the number of vowels in c-string
int countConsonants(const char*); // counts the number of vowels in c-string
bool isVowel(char); // returns true if vowel and false otherwise
bool isConsonant(char); // returns true if consonant and false otherwise



int main()
{
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

bool isVowel(char ch)
{
	return std::strchr("aeiouAEIOU", ch) != NULL; 

}

bool isConsonant(char ch)
{
	return std::strchr("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", ch) != NULL;

}
