// Week4_Initial_Post_Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <sstream> // stringstream
#include <iomanip>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;

#pragma warning(disable : 4996)


static const int TOTAL_NUMBER_OF_ROWS = 15;
static const int TOTAL_NUMBER_OF_COLUMNS = 30;
char arrayOfSeats[TOTAL_NUMBER_OF_ROWS][TOTAL_NUMBER_OF_COLUMNS];

void openFile(ifstream &);


int main()
{
	// Object to read from file
	ifstream userFile;
	string line;
	seatAvaliabilityIn.open("SeatAvailability.dat");
	openFile(seatAvaliabilityIn);
	return 0;

}

void openFile(ifstream &seatAvaliabilityIn) {
	char stuff[TOTAL_NUMBER_OF_ROWS][TOTAL_NUMBER_OF_COLUMNS];
	for (int currentRow = 0; currentRow < TOTAL_NUMBER_OF_ROWS; currentRow++) {
		seatAvaliabilityIn >> stuff[currentRow];
		cout << stuff[currentRow] << endl;
	}
	seatAvaliabilityIn.close();
}
