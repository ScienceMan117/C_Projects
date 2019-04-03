//**************************************************************************** 
// File name:	HourlyEmployee.cpp
// Author:		Doug Ryan
// Date:		  4/5/2016
// Class:		  CS 250
// Assignment: Inheritance Lab
// Purpose:		Demonstrate Inheritance
//*****************************************************************************

#include "HourlyEmployee.h"
#include <iostream>

using namespace std;

//****************************************************************************
// Constructor:	HourlyEmployee
//
// Description:	Call the Employee default constructor, set mWageRate 
//              and mHoursWorked both to zero.
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
HourlyEmployee::HourlyEmployee() : Employee(), mWageRate(0), mHoursWorked(0)
{
}

//****************************************************************************
// Constructor:	HourlyEmployee
//
// Description:	Call the Employee constructor with name, set mWageRate 
//              and mHoursWorked both the given parameters.
//
// Parameters:	name - the name of the Employee
//              hourlyRate - the wage of the Employee
//              hoursWorked - the hours the Employee worked
//
// Returned:		none
//***************************************************************************
HourlyEmployee::HourlyEmployee (string name, double hourlyRate, 
                                double hoursWorked) :
                                /*Calling Employee constructor*/Employee (name), mWageRate (hourlyRate),
                                mHoursWorked (hoursWorked)
{
}

//****************************************************************************
// Method:	    getPay
//
// Description:	Retrieve the pay of the HourlyEmployee
//              calculated by wages * hours
//
// Parameters:	none
//
// Returned:		double - the a pay of the Employee
//***************************************************************************
double HourlyEmployee::getPay() const
{
  return mWageRate * mHoursWorked;
}

//****************************************************************************
// Function:	  operator<<
//
// Description:	Output the HourlyEmployee to the stream. Call the 
//              Employee operator<< first.
//
// Parameters:	out - the stream to output to
//              cEmp - the HourlyEmployee to output
//
// Returned:		ostream - the output stream
//***************************************************************************

ostream& operator<<(ostream &out, const HourlyEmployee &cEmp)
{ // const Employee & needs to match parameters in the derived class Employee friend function
  out << static_cast<const Employee &>(cEmp); // static cast temporarily cast it to an employee and then cast it to the output operator
  out << "\t" << cEmp.getPay();
  return out;
}