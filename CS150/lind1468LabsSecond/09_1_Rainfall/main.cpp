//******************************************************************************
// File Name:		main.cpp
// Author:			Aidan Lindsey
// Date:				10/22/13
// Class:				CS150-01
// Assignment:	Nested Loops and Files
// Purpose:			Determine the average amount of rainfall for the month of March
//							2011 using a file from a resource. 
//******************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	int weeks;
	int weekDays = 0;
	int startingWeek = 1;
	int startingValue = 0;
	int fileValue = 5;
	int totalDays = 0;
	double precipitation, averagePrecipitation;
	double totalPrecipitation = 0.00;
	double totalAveragePrecipitation = 0.00;
	double sumPrecipitation = 0.00;
	double rainfall = .01;

	cout << fixed << setprecision(2);

	cout << setw(21) << " " <<  "**************************" << endl;
	cout << setw(21) << " " <<  "*        Rainfall        *" << endl;
	cout << setw(21) << " " <<  "**************************" << endl;
	cout << endl;

	cout << setw(6) << "Week" << setw(15) << "Days in Week" 
		   << setw(26) << "Weekly Precipitation" 
		   << setw(26) << "Average Precipitation" << endl;
	cout << setfill('-') << setw(73) << "";
	cout << setfill(' ') << endl;

	fstream inputFile;
	inputFile.open ("rainfall.txt");

	if (inputFile.fail())
	{
		exit (EXIT_FAILURE);
	}

	inputFile >> weeks;

	for (int week = startingWeek; week <= weeks ; week++)
	{
		inputFile >> weekDays;
		sumPrecipitation = startingValue;
		averagePrecipitation = startingValue;
		for (int weekDay = startingWeek; weekDay <= weekDays; weekDay++)
		{
			inputFile >> precipitation;
			sumPrecipitation += precipitation;
			averagePrecipitation = sumPrecipitation / weekDays;
		}
		cout << setw(6) << week;
		cout << setw(15) << weekDays;
		cout << setw(26) << sumPrecipitation;	
		cout << setw(26) << averagePrecipitation;
		cout << endl;		
		totalDays += weekDays;
		totalPrecipitation += sumPrecipitation;
		totalAveragePrecipitation += averagePrecipitation;
	}

	totalAveragePrecipitation = totalPrecipitation / totalDays;

	cout << endl << "Total days in the month: " << totalDays << endl;
	cout << "Total rainfall for the month: " << totalPrecipitation << " inches"
			 << endl;
	cout << "Average daily rainfall: "   << totalAveragePrecipitation << " inches"
			 << endl << endl;

	inputFile.close ();

	return EXIT_SUCCESS;
}