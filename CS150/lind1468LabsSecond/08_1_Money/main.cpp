//******************************************************************************
// File Name:		main.cpp
// Author:			Aidan Lindsey
// Date:				10/15/13
// Class:				CS150-01
// Assignment:	Files & Loops Lab 1
// Purpose:			Determine whether yiu'd prefer to be paid $1,000.00 a day for 25
//							days or a penny the first day, two pennies the second, four 
//							pennies the third day and so on, doubling the amount you made 
//							the previous day. No user input and must use a for loop.
//******************************************************************************
#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	double totalthousands = 0;
	double totaldoubling = 0;
	double doubling = .01;
	double thousands = 1000.00;
	const int DAY_ONE = 1;
	const int DAY_TWENTYFIVE = 25;
	const double TWO = 2.00;

	cout << "*** Makin' Money ***" << endl << endl;

	cout << setw(5) << "Day" << setw(12) << "Thousands" << setw(12) << "Doubling"
	<< endl;

	for (int day = DAY_ONE; day <= DAY_TWENTYFIVE; day++)
	{
		cout << setw(5) << day << setw(12) << fixed << setprecision(2) << thousands
		<< setw(12) << fixed << setprecision(2) << doubling << endl;
		totalthousands = totalthousands + thousands;
		totaldoubling = totaldoubling + doubling;
		doubling = doubling * TWO;
	}
	cout << endl << "Total" << setw(12) << fixed << setprecision(2) 
	<< totalthousands << setw(12) << fixed << setprecision(2) 
	<< totaldoubling << endl;

	return EXIT_SUCCESS;
}