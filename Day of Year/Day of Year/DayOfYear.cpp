#include "stdafx.h"
#include "DayOfYear.h"

#include <iostream>
#include <string>


DayOfYear::DayOfYear(int dayOfYear)
{
	int year = 2018;
	int yearOffset = dayOfYear - TM_YEAR_BASE;
	int leapYearIndex = leapyear(year) ? 1 : 0;
	this->daysInYear = leapYearIndex ? 366 : 365;

	this->year = year;
	this->dayOfYear = dayOfYear;

	if (dayOfYear >= 1 && dayOfYear <= daysInYear) {
		this->properDayOfYear = 1;
		for (int mon = 0; mon < MONTHS_IN_YEAR; mon++) {
			if (dayOfYear <= __mon_yday[leapYearIndex][mon + 1]) {
				month = months[mon];
				dayOfMonth = dayOfYear - __mon_yday[leapYearIndex][mon];
				break;
			}
		}
	}
	else {
		this->properDayOfYear = 0;
		cerr << "Day of year must be between 1 and " << daysInYear << endl;
		month = months[0];
		dayOfMonth = 0;
	}
}

void DayOfYear::print(int numberToConvert) {
	cout << "Your day of year converstion of " << numberToConvert << " is " << month + " " << dayOfMonth << endl;
}