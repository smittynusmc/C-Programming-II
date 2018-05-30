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




static const int TOTAL_NUMBER_OF_ROWS = 15;
static const int TOTAL_NUMBER_OF_COLUMNS = 30;
char arrayOfSeats[TOTAL_NUMBER_OF_ROWS][TOTAL_NUMBER_OF_COLUMNS];

void openFile(fstream &);


int main()
{
	// Object to read from file
	fstream seatAvaliabilityIn;

	openFile(seatAvaliabilityIn);

	FILE * mySeats;
	mySeats = fopen("SeatAvailability.dat","r");

}

void openFile(fstream &seatAvaliabilityIn) {
	// Opening file in input mode
	seatAvaliabilityIn.open("SeatAvailability.dat");
	char tempSeat;
	for (int currentRow = 0; currentRow < TOTAL_NUMBER_OF_ROWS; currentRow++) {
		for (int currentColumn = 0; currentColumn < TOTAL_NUMBER_OF_COLUMNS; currentColumn++) {
			seatAvaliabilityIn >> tempSeat;
			arrayOfSeats[currentRow][currentColumn] = tempSeat;
		}
	}
}
