//*****************************************************************************
// File Name:		main.cpp
// Author:			Aidan Lindsey
// Date:				09/29/2013
// Class:				CS150-01
// Assignment:  A Retirement Calculator
// Purpose:			Calculate how money a person will have saved after a certain 
//							number of years investing in a retirement plan.
// Hours:				3 hours.
//*****************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	char menuChoice;
	double investPercentage, fixedInterestrate, investment, 
	interestEarned, endingBalance;
	double beginningBalance = 0.00;
	double interestYearly = 0.00;
	double  yearlyBalance = 0.00;
	int income, retirement, month;
	int monthCount = 0;	
	const int MONTH_CONVERSION = 12;
	const int ONE = 1;
	const char CHOICE_YEARLY = 'Y';
	const char CHOICE_MONTHLY = 'M';
	const double ONE_DOUBLE = 1.00;
	const double ZERO = 0.00;

	cout << "*********************************" << endl
	<< "*     Retirement Calculator     *" << endl 
	<< "*********************************" << endl << endl;

	cout << "Enter your annual income: $";
	cin >> income;

	cout << "Enter the percentage of your income you want to invest: ";
	cin >> investPercentage;

	cout << "Enter the fixed annual interest rate you make on your investment: ";
	cin >> fixedInterestrate;

	cout << "Enter the number of years until retirement: ";
	cin >> retirement;

	cout << endl << "Print Results [ M)onth, Y)early ] : ";
	cin >> menuChoice;

	cout << endl << setw(12) << "Beginning" << setw(15) << "Additional" 
	<< setw(15)
	<< "Interest" << setw(17) << "Ending";
	if (CHOICE_MONTHLY == menuChoice)
	{
		cout << setw(9) << "Month";
	}
	if (CHOICE_YEARLY == menuChoice)
	{
		cout << setw(9) << "Year";
	}
	cout << endl << setw(12) << "Balance" << setw(15) << "Investment" << setw(15) 
	<< "Earned" << setw(17) << "Balance" << endl << "------------" << setw(15)
	<< "----------" << setw(15) << "----------" << setw(17) << "-----------" 
	<< setw(9) << "----" << endl;

	month = MONTH_CONVERSION * retirement;
	
	while (monthCount <= month)
	{
		investment = (income * investPercentage) / MONTH_CONVERSION;
		interestEarned = (beginningBalance + investment) * 
		(fixedInterestrate / MONTH_CONVERSION);
		endingBalance = (beginningBalance + investment) + interestEarned;
		beginningBalance = endingBalance;
		monthCount = monthCount + ONE;
		interestYearly = interestEarned + interestYearly;
		if ( CHOICE_MONTHLY == menuChoice && monthCount <= month)
		{
			cout << "$" << setw(11) << fixed << setprecision(2) << beginningBalance;
			cout << setw(6) << "$" << setw(9) << fixed << setprecision(2) 
			<< investment;
			cout << setw(6) << "$" << setw(9) << fixed << setprecision(2) 
			<< interestEarned;
			cout << setw(6) << "$" << setw(11) << fixed << setprecision(2) 
			<< endingBalance;
			cout << setw(9) << monthCount << endl;
		}
		if (CHOICE_YEARLY == menuChoice && monthCount % MONTH_CONVERSION == ZERO)
		{
			cout << "$" << setw(11) << fixed << setprecision(2) << yearlyBalance;
			cout << setw(6) << "$" << setw(9) << fixed << setprecision(2) 
			<< investment * MONTH_CONVERSION;
			cout << setw(6) << "$" << setw(9) << fixed << setprecision(2) 
			<< interestYearly;
			cout << setw(6) << "$" << setw(11) << fixed << setprecision(2) 
			<< endingBalance;
			cout << setw(8) << monthCount / 12 << endl;
			interestYearly = ZERO;
			yearlyBalance = endingBalance;
		}
	}

	return EXIT_SUCCESS;
}

	
	
