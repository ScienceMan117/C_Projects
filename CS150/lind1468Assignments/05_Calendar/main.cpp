//*****************************************************************************
// File Name:	main.cpp
// Author:		Aidan Lindsey
// Date:		10/20/2013
// Class:		CS150-01
// Assignment:  Calendar
// Purpose:		Have a user input the date so that the compiler can display   
//				a calendar.
// Hours:		3 hours.
//*****************************************************************************
#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	char menuChoice;

	
	int calendaryear, calendarmonth, calendarday, calendarweek;

	const int LEAP_YEAR = 4;
	const int MONTH_LIMIT = 12;
	const int ZERO = 0;
	const int JANUARY = 1;
	const int FEBRUARY = 2;
	const int MARCH = 3;
	const int APRIL = 4;
	const int MAY = 5;
	const int JUNE = 6;
	const int JULY = 7;
	const int AUGUST = 8;
	const int SEPTEMBER = 9;
	const int OCTOBER = 10;
	const int NOVEMBER = 11;
	const int DECEMBER = 12;
	const int MONTH_CAPACITY_ONE = 31;
	const int MONTH_CAPACITY_TWO = 28;
	const int MONTH_CAPACITY_THREE = 29;
	const int MONTH_CAPACITY_FOUR = 30;
	const int SUNDAY = 0;
	const int MONDAY = 1;
	const int TUESDAY = 2;
	const int WEDNESDAY = 3;
	const int THURSDAY = 4;
	const int FRIDAY = 5;
	const int SATURDAY = 6;
	const int WEEK_CAPACITY = 6;
	const int FIRST_DAY = 1;

	cout << "**********************************************************" << endl
	<< "*                        Calendar                        *" << endl 
	<< "**********************************************************" << endl 
	<< endl;

	do
	{
		cout << "Please enter the calendar year: ";
		cin >> calendaryear;
	} while (calendaryear < ZERO);

	cout << endl;

	do
	{
		cout << "Please enter the calendar month: ";
		cin >> calendarmonth;
	} while (calendarmonth > MONTH_LIMIT || calendarmonth < ZERO);
	
	if (calendarmonth == JANUARY)
	{
		menuChoice = MONTH_CAPACITY_ONE;
	}
	
	if (calendarmonth == FEBRUARY && calendaryear % LEAP_YEAR)
	{
		menuChoice = MONTH_CAPACITY_TWO;
	}
	else 
	{
		menuChoice = MONTH_CAPACITY_THREE;
	}

	if (calendarmonth == MARCH)
	{
		menuChoice = MONTH_CAPACITY_ONE;
	}

	if (calendarmonth == APRIL)
	{
		menuChoice = MONTH_CAPACITY_FOUR;
	}

	if (calendarmonth == MAY)
	{ 
		menuChoice = MONTH_CAPACITY_ONE;
	}

	if (calendarmonth == JUNE)
	{
		menuChoice = MONTH_CAPACITY_FOUR;
	}

	if (calendarmonth = JULY)
	{
		menuChoice = MONTH_CAPACITY_ONE;
	}
	
	if (calendarmonth = AUGUST)
	{
		menuChoice = MONTH_CAPACITY_ONE;
	}

	if (calendarmonth = SEPTEMBER)
	{
		menuChoice = MONTH_CAPACITY_FOUR;
	}

	if (calendarmonth = OCTOBER)
	{
		menuChoice = MONTH_CAPACITY_ONE;
	}

	if (calendarmonth = NOVEMBER)
	{
		menuChoice = MONTH_CAPACITY_FOUR;
	}

	if (calendarmonth = DECEMBER)
	{
		menuChoice = MONTH_CAPACITY_ONE;
	}

	cout << endl;

	do 
	{
		cout << "Please enter the calendar day: ";
		cin >> calendarday;
	} while (menuChoice < calendarday || calendarday < ZERO);

	cout << endl;

	do
	{
		cout << "Please enter the day of the week: ";
		cin >> calendarweek;
	} while (ZERO > calendarweek || WEEK_CAPACITY < calendarweek);

	system ("cls");
	system ("pause");

	cout << setw(24) << calendaryear << endl << endl;
	
	cout << setw(24) << calendarmonth << endl << endl;

	cout << setw(6) << "S" << setw(3) << "M" << setw(3) << "T" << setw(3) << "W"
	<< setw(3) << "T" << setw(3) << "F" << setw(3) << "S" << endl << endl;

	cout << setw(24) << "-------------------" << endl;

	cout << setw(3) << " ";

	cout << setw(3 * calendarweek) << " ";

	for (int dayCount = 1; dayCount <= menuChoice; dayCount++)
	{
		cout << setw(3) << dayCount;

	}

	return EXIT_SUCCESS;
}