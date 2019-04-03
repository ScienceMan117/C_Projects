//*****************************************************************************
// File name:	main.cpp
// Author:		Aidan Lindsey
// Date:		09/12/13
// Class:		CS150-01
// Assignment:	A Grade School Fraction Calculator
// Purpose:		Write a complete program with Visual Studio 2010, and use 
//				input, output and arithmetic operators.
// Hours:		One and half hours spent on project.
//*****************************************************************************
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int numerator1, denominator1, numerator2, denominator2, numerator3, 
		denominator3;

	cout << "***********************" << endl << "* Fraction Calculator *" <<
	endl << "***********************" << endl << endl;

	// Enter the first fraction's numerator
	cout << "Enter Fraction #1's numerator: ";
	cin >> numerator1;

	// Enter the first fraction's denominator
	cout << "Enter Fraction #1's denominator: ";
	cin >> denominator1;

	// Enter the second fraction's numerator
	cout << endl << "Enter Fraction #2's numerator: ";
	cin >> numerator2;

	// Enter the second fraction's denominator
	cout << "Enter Fraction #2's denominator: ";
	cin >> denominator2;

	// Calculate what sum of fraction 1 and fraction 2
	denominator3 = denominator1 * denominator2;
	numerator3 = (denominator1 * numerator2) + (numerator1 * denominator2);

	// Display the sum of fraction 1 and fraction 2
	cout << endl << numerator1 << "/" << denominator1 << " + " << numerator2 
	<< "/" << denominator2 << " = " << numerator3 << "/" << denominator3 << 
	endl;

	return EXIT_SUCCESS;
}


