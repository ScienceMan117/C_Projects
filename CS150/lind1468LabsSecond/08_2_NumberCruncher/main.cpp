//******************************************************************************
// File Name:		main.cpp
// Author:			Aidan Lindsey
// Date:				10/15/13
// Class:				CS150-01
// Assignment:	Files & Loops Lab 2
// Purpose:			Read in a number of integers from a text file named numbers.txt
//							and performs some calculations on the file. 
//******************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ()
{
	int number, largestnumber, smallestnumber;
	int count = 0;
	int even = 0;
	int numbersum = 0;
	const int TOTAL_NUMBERS = 3;
	const int TWO = 2;
	const int ONE = 1;
	const int ZERO = 0;
	const int SENTINEL_VALUE = -999;

	cout << "*** Number Cruncher ***" << endl << endl;

	fstream inputFile;
	inputFile.open ("numbers.txt");

	if (inputFile.fail())
	{
		exit (EXIT_FAILURE);
	}

	inputFile >> number;
	while (number != SENTINEL_VALUE)
	{
		numbersum = numbersum + number;
		count = count + ONE;
		
		if (count == ONE)
		{
			largestnumber = number;
		}
		if (number > largestnumber)
		{
			largestnumber = number;
		}
		if (count == ONE)
		{
			smallestnumber = number;
		}
		if (number < smallestnumber)
		{
			smallestnumber = number;
		}
		if (ZERO == number % TWO)
		{
			cout << number << " ";
			even = even + ONE;
		}
		if (ZERO == even % TOTAL_NUMBERS)
		{
			cout << endl;
		}
		inputFile >> number;
	}

	cout << endl << endl << "Count: " << count << endl;
	cout << "Number of evens: " << even << endl;
	cout << "Sum: " << numbersum << endl;
	cout << "Largest: " << largestnumber << endl;
	cout << "Smallest: " << smallestnumber << endl;

	return EXIT_SUCCESS;
}
