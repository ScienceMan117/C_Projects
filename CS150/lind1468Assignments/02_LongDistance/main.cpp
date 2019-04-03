//********************************************************************************
// File Name:	main.cpp
// Author:		Aidan Lindsey
// Date:		09/19/2013
// Class:		CS150-01
// Assignment:	Long Distance Call Calculator
// Purpose:		Write a complete C++ program that asks the user for a starting 
//				time and the number of minutes of the call. As output, print the 
//				charges for the call.
//********************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{ 
	
	char colon;
	int duration, hours, minutes;
	double price, cost;
	const double time1 = .10;
	const double time2 = .50;
	const double time3 = .25;
	
	
	cout << "***********************" << endl << "* Long-Distance Calls *" << endl 
		 << "***********************" << endl << endl;
	
	// Enter the starting time of the call
	cout << "Enter Starting Time Of Call: ";
	cin >> hours >> colon >> minutes;

	// Enter Call Duration in minutes
	cout << endl << "Enter Call Duration <in minutes>: ";
	cin >> duration;

	if (hours < 7)
	{
	cost = time1;
	}

	if (hours < 19)
	{ 
	if (7 <= hours)
	{
	cost = time2;
	}
	}

	if (hours < 24)
	{
	if (19 <= hours)
	{
	cost = time3;
	}
	}

	// Calculate the price of the call
	price = cost * duration;

	// Display the price of the call
	cout << endl<< "Price Of Call: $" << fixed << setprecision(2) << price <<  endl << endl;

	return EXIT_SUCCESS;

}