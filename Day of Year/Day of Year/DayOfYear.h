//  DayOfYear.cpp Takes a day of the year and convert to a date. Also, can print out that date
//  Adam Tucker
//  05/19/18
#pragma once
#include <iostream>
using namespace std;

#define MONTHS_IN_YEAR 12

#define TM_YEAR_BASE 1900

/* Return 1 if YEAR + TM_YEAR_BASE is a leap year.  */
static inline int
leapyear(int year)
{
	/* Don't add YEAR to TM_YEAR_BASE, as that might overflow.
	Also, work even if YEAR is negative.  */
	return
		((year & 3) == 0
			&& (year % 100 != 0
				|| ((year / 100) & 3) == (-(TM_YEAR_BASE / 100) & 3)));
}

const unsigned short int __mon_yday[2][13] =
{
	/* Normal years.  */
	{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
	/* Leap years.  */
	{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
};

// Months in a year
const string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

class DayOfYear {
public:
	DayOfYear(int);

	// Get month 1=January, 12=December       
	inline string getMonth() { return month; }

	// Get day of month
	inline int getDayOfMonth() { return dayOfMonth; }

	// Get year
	inline int getYear() { return year; }

	// Get day of yar
	inline int getDayOfYear() { return dayOfYear; }

	// Get days in year
	inline int getDaysInYear() { return daysInYear; }

	// Get proper day of year
	inline bool isProperDayOfYear() { return properDayOfYear; }

	void print(int);

private:
	string month; // Current month
	int dayOfMonth; // day in current month
	int year; // current year
	int dayOfYear; // day in the year
	int daysInYear; // number of days in current year
	bool properDayOfYear; // ensures object is created with proper day in year
};

