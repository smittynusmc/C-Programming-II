//  DayOfYear.cpp Takes a day of the year and convert to a date. Also, can print out that date
//  Adam Tucker
//  05/19/18
#include "stdafx.h"
#include "DayOfYear.h"

#include <iostream>
#include <string>


DayOfYear::DayOfYear(int dayOfYear)
{
	int year = 2018; // hard coded for this year
	int leapYearIndex = leapyear(year) ? 1 : 0; // checks if it is a leap year
	this->daysInYear = leapYearIndex ? 366 : 365; // sets days in a year

	this->year = year; // sets year
	this->dayOfYear = dayOfYear; // sets day in the year

	if (dayOfYear >= 1 && dayOfYear <= daysInYear) { // is it a day in the year
		this->properDayOfYear = 1; // flag indicating dayOfYear is valid
		for (int mon = 0; mon < MONTHS_IN_YEAR; mon++) {// loop through months in year
			if (dayOfYear <= __mon_yday[leapYearIndex][mon + 1]) { // dayOfYear is less than current month. Found current month
				month = months[mon]; // set current month
				dayOfMonth = dayOfYear - __mon_yday[leapYearIndex][mon]; // day in month
				break;
			}
		}
	}
	else { // improper day of the year
		this->properDayOfYear = 0;
		cerr << "Day of year must be between 1 and " << daysInYear << endl;
		month = months[0];
		dayOfMonth = 0;
	}
}

// Prints to the console day input and month and day of the year
void DayOfYear::print(int numberToConvert) {
	cout << "Your day of year converstion of " << numberToConvert << " is " << month + " " << dayOfMonth << endl;
}