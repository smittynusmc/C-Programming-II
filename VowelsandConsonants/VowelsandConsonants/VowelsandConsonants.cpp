// VowelsandConsonants.cpp : The program should count the number of vowels and consonants appearing in the string and return that number.
// The menu allows the user to choose to count vowels, consonants and vowels/consonants, enter a new string and end the program
// Adam Tucker
// 05/27/18

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

	bool isDone = false; // flag for main loop
	char sentence[500] = { '\0' };// init char array with enough space. Null terminator allows to check for empty
	int numVowels, numConsonants, numLetters, charLength; // init number variables for vowels, consonants and full length


	cout << "Welcome to Vowels and Consonant Counter!" << endl;
	cout << "Type the letter for the menu choice you want then press 'Enter'" << endl;

	while (!isDone) { // main loop
		char menuChoice; // int user choice to continue program
		// Print menu per instructions
		cout << "----------------------------------------" << endl;
		cout << "A. Count Number of Vowels" << endl;
		cout << "B. Count Number of Consonants" << endl;
		cout << "C. Count Number of Consonants and Vowels" << endl;
		cout << "D. Enter another string" << endl;
		cout << "E. Exit Program" << endl;
		cout << "----------------------------------------" << endl;
		cin.get(menuChoice); // Get first char of menu choice. If more than one char choices first one and ignores others
		cin.clear(); // clear extra char
		cin.ignore(INT_MAX, '\n'); // reset cin
		menuChoice = toupper(menuChoice); // capitilaize menuChoice if user input lower case
		switch (menuChoice) // switch on menu choice
		{
		case 'A':
			if (sentence[0] != '\0') { // check if array still has null term meaning sentence has not been entered
				numVowels = countVowels(sentence); // count number of vowels
				cout << "Number of vowels in the sentence: " << sentence << " is " << numVowels << endl; // print number of vowels
			}
			else {
				cout << "You have not entered a sentence. Choose D to enter a sentence" << endl; // if sentence[0] has null term inform user
			}
			break;

		case 'B':
			if (sentence[0] != '\0') { // check if array still has null term meaning sentence has not been entered
				numConsonants = countConsonants(sentence); // count number of consonants
				cout << "Number of consonants in the sentence: " << sentence << " is " << numConsonants << endl;
			}
			else {
				cout << "You have not entered a sentence. Choose D to enter a sentence" << endl; // if sentence[0] has null term inform user
			}
			break;

		case 'C':
			if (sentence[0] != '\0') {  // check if array still has null term meaning sentence has not been entered
				numLetters = countVowels(sentence) + countConsonants(sentence); // count number of vowels and consonants
				cout << "Number of consonants and vowels in the sentence: " << sentence << " is " << numLetters << endl; // if sentence[0] has null term inform user
			}
			else {
				cout << "You have not entered a sentence. Choose D to enter a sentence" << endl; // if sentence[0] has null term inform user
			}
			break;

		case 'D':
			cout << "Please, enter your sentence: "; // promt user for sentence
			cin.getline(sentence, 256); // get the full sentence
			break;

		case 'E':
			// quit program
			cout << "Thanks! Have a nice life!!!" << endl;
			isDone = true; // set flag to end loop
			break;
		default:
			// user input something other than A,B,C,D or E
			cout << "Incorrect Menu Choice. Try again!" << endl;
		}
	}
	return 0;
}

/*
countVowels
Counts the number of vowels in a char array
Param: C-string (char array)
Return: Number of vowels in char array
*/
int countVowels(const char *ch)
{
	int numVowel = 0; // number of vowel variable
	for (int i = 0; i < strlen(ch); i++) { // loop through char array
		if (isVowel(ch[i])) { // check if it is a vowel
			numVowel++; // if a vowel increment numVowel by 1
		}
	}
	return numVowel; // return number of vowels
}

/*
countConsonants
Counts the number of consonants in a char array
Param: C-string (char array)
Return: Number of constonants in char array
*/
int countConsonants(const char *ch)
{
	int numConsonant = 0; // number of consonants variable
	for (int i = 0; i < strlen(ch); i++) { // loop through char array
		if (isConsonant(ch[i])) { // check if it is a consonants
			numConsonant++; // if a consonants increment numConsonant by 1
		}
	}
	return numConsonant; // return number of consonants
}


/*
isVowel
Checks if the character paramater is containted in the string with all vowels
Param: Character to evaluated if it is in string of vowels
Return: True of ch is in string of vowels. False otherwise.
Adapted from: https://stackoverflow.com/questions/21810895/vowels-in-string-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
bool isVowel(char ch)
{
	// strchr returns pointer to first location of ch in the string.
	// If the pointer returned is not null than ch is in the string of vowels and function returns true
	// Otherwise it returns false because the pointer is null since strchr did not find an occurance of ch
	return std::strchr("aeiouAEIOU", ch) != NULL; 

}

/*
isConsonant
Checks if the character paramater is containted in the string with all consonants
Param: Character to evaluated if it is in string of consonants
Return: True if ch is in string of consonants. False otherwise.
Adapted from: https://stackoverflow.com/questions/21810895/vowels-in-string-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
bool isConsonant(char ch)
{
	// strchr returns pointer to first location of ch in the string.
	// If the pointer returned is not null than ch is in the string of consonants and function returns true
	// Otherwise it returns false because the pointer is null since strchr did not find an occurance of ch
	return std::strchr("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", ch) != NULL;

}
