//******************************************************************************
// File Name:	main.cpp
// Author:		Aidan Lindsey
// Date:		09/29/2013
// Class:		CS150-01
// Assignment1:	Assignment number Mortage Calculator
// Purpose:		To calculate the purchase price, amount financed, months the loan 
//				is for, monthly payment, and monthly amount of private mortgage 
//				insurance, for purchasing a house using different mortgage rates.
//******************************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main ()
{
	// List all variables.
	string firstname, lastname;
	int price, duration, down, months;
	double APR, purchaseprice, financed, loanvalue, insurancerate, 
	fixedmonthlypayment,financerate, value, loan, powconversion,
	interestrateconversion, fixedmonthconversion,fixedmonthvalueconversion, 
	monthlyinterestrate, PMIcost, PMI, percentinsurancerate;
	const int YEARS_TO_MONTHS_CONVERSION = 12;
	const int PERCENTAGE = 100;
	const int HIGH_HIGH_LOAN_VALUE = 97;
	const int MEDIUM_HIGH_LOAN_VALUE = 95;
	const int LOW_HIGH_LOAN_VALUE = 90;
	const int LOWEST_HIGH_LOAN_VALUE = 85;
	const int YEAR_CONSTANT = 30;
	const int ONE = 1;
	const double PRICE_TO_AMOUNT_FINANCED_CONVERSION = 100.00;
	const double THIRTY_YEAR_HIGH_INSURANCE_RATE = .90;
	const double THIRTY_YEAR_MEDIUM_INSURANCE_RATE = .78;
	const double THIRTY_YEAR_LOW_INSURANCE_RATE = .52;
	const double THIRTY_YEAR_LOWEST_INSURANCE_RATE = .32;
	const double TEN_TO_TWENTY_YEAR_HIGH_INSURANCE_RATE = .79;
	const double TEN_TO_TWENTY_YEAR_MEDIUM_INSURANCE_RATE = .26;
	const double TEN_TO_TWENTY_YEAR_LOW_INSURANCE_RATE = .23;
	const double TEN_TO_TWENTY_YEAR_LOWEST_INSURANCE_RATE = .19;
	const double PRICE_INTEGER_TO_DOUBLE_CONVERSION = 1.00;
	const double HIGH_LOW_LOAN_VALUE = 95.01;
	const double MEDIUM_LOW_LOAN_VALUE = 90.01;
	const double LOW_LOW_LOAN_VALUE = 85.01;
	const double LOWEST_LOW_LOAN_VALUE = 80.01;
	
	//Input First name, last name, price, mortgage rate, and duration of loan.
	cout << "*************************" << endl << setw(20) 
	<< "Mortgage Calculator" << endl << "**************************" << endl 
	<< endl;

	cout << "Enter borrower's first name: ";
	cin >> firstname;

	cout << "Enter borrower's last name: ";
	cin >> lastname;

	cout << "Enter purchase price: ";
	cin >> price;

	cout << "Enter Mortgage rate (APR): ";
	cin >> APR;

	cout << "Enter percent down: ";
	cin >> down;

	cout << "Enter duration of loan (in years): ";
	cin >> duration;

	cout << endl << endl << firstname << " " << lastname << endl;

	cout << "-------------------------------------" << endl;

	// Calculate purchase price.
	purchaseprice = price / PRICE_INTEGER_TO_DOUBLE_CONVERSION;

	// Display purchase Price.
	cout << "Purchase Price = " << setw(11) << "$ " << setw(2) << fixed << 
	setprecision(2) << purchaseprice << endl;
	
	// Calculate the Loan.
	financerate = down / PRICE_TO_AMOUNT_FINANCED_CONVERSION;
	
	financed = price * financerate;

	loan = price - financed;

	// Display the loan. 
	cout << "Amount Financed = " << setw(10) << "$ " << setw(2) << fixed <<
	setprecision(2) << loan << endl;

	// Calculate the duration of loan in months.
	months = duration * YEARS_TO_MONTHS_CONVERSION;
	
	// Display the duration of loan in months.
	cout << "Months = " << setw(28) << months << endl;

	// Calculate the fixed monthly payment.
	monthlyinterestrate = (APR / YEARS_TO_MONTHS_CONVERSION) / PERCENTAGE;
	
	powconversion = ONE + monthlyinterestrate;

	value = pow (powconversion, months);

	interestrateconversion = monthlyinterestrate * value;

	fixedmonthconversion = loan * interestrateconversion;

	fixedmonthvalueconversion = value - ONE;

	fixedmonthlypayment = fixedmonthconversion / fixedmonthvalueconversion;

	// Display the fixed monthly payment.
	cout << "Monthly Payment = " << setw(10) << "$ " << setw(9) << fixed << setprecision(2)	
	<< fixedmonthlypayment << endl;

	loanvalue = PERCENTAGE - down;
	
	// Determine the loan value, depending on loan duration and quantity of loan.
	if (loanvalue <= HIGH_HIGH_LOAN_VALUE && HIGH_LOW_LOAN_VALUE
	<= loanvalue && duration == YEAR_CONSTANT)
	insurancerate = THIRTY_YEAR_HIGH_INSURANCE_RATE;
	else if (duration < YEAR_CONSTANT)
	{
	insurancerate = TEN_TO_TWENTY_YEAR_HIGH_INSURANCE_RATE;
	}

	if (loanvalue <= MEDIUM_HIGH_LOAN_VALUE && MEDIUM_LOW_LOAN_VALUE
	<= loanvalue && duration == YEAR_CONSTANT)
	insurancerate = THIRTY_YEAR_MEDIUM_INSURANCE_RATE;
	else if (duration < YEAR_CONSTANT)
	{
	insurancerate = TEN_TO_TWENTY_YEAR_MEDIUM_INSURANCE_RATE;
	}

	if (loanvalue <= LOW_HIGH_LOAN_VALUE && LOW_LOW_LOAN_VALUE
	<= loanvalue && duration == YEAR_CONSTANT)
	insurancerate = THIRTY_YEAR_LOW_INSURANCE_RATE;
	else if (duration < YEAR_CONSTANT)
	{
	insurancerate = TEN_TO_TWENTY_YEAR_LOW_INSURANCE_RATE;
	}

	if (loanvalue <= LOWEST_HIGH_LOAN_VALUE && LOWEST_LOW_LOAN_VALUE
	<= loanvalue && duration ==YEAR_CONSTANT)
	insurancerate = THIRTY_YEAR_LOWEST_INSURANCE_RATE;
	else if (duration < YEAR_CONSTANT) 
	{
	insurancerate = TEN_TO_TWENTY_YEAR_LOWEST_INSURANCE_RATE;
	}

	// Calculate the PMI.
	percentinsurancerate = insurancerate / PERCENTAGE;

	PMIcost = (loan * percentinsurancerate);

	PMI = PMIcost / YEARS_TO_MONTHS_CONVERSION;

	// Display the PMI.
	cout << "Monthly PMI = " << setw(14) << "$ " << setw(9) << fixed << setprecision(2)
	<< PMI << endl << endl;

	return EXIT_SUCCESS;
}