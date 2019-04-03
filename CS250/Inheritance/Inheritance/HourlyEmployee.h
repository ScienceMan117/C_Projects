//**************************************************************************** 
// File name:	HourlyEmployee.h
// Author:		Doug Ryan
// Date:		  4/5/2016
// Class:		  CS 250
// Assignment: Inheritance Lab
// Purpose:		Demonstrate Inheritance
//*****************************************************************************

#pragma once

#include "Employee.h"
#include <string>
#include <iostream>

using namespace std;

class HourlyEmployee : public Employee
{
  public:
    HourlyEmployee ();
    HourlyEmployee(string name, double hourlyRate, double hoursWorked);

    double getPay() const;

//    friend ostream& operator<<(ostream &out, const HourlyEmployee &cEmp);

  private:
    double mWageRate;
    double mHoursWorked;
};
