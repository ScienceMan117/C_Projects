//**************************************************************************** 
// File name:	main.cpp
// Author:		Doug Ryan
// Date:		  4/5/2016
// Class:		  CS 250
// Assignment: Inheritance Lab
// Purpose:		Demonstrate Inheritance
//*****************************************************************************

#include "Employee.h"
#include "HourlyEmployee.h"
#include <iostream>
#include <iomanip>

using namespace std;


//****************************************************************************
// Function:    main
//
// Description:	Demonstrate Inheritance
//              Declare a base class object and a derived class object.
//              call functions on both objects.
//
// Parameters:	none
//
// Returned:		int - EXIT_SUCCESS
//***************************************************************************

int main()
{

  // the base class
  // passing in a name
  Employee cEmployee ("Jane Smith");

  // the derived class
  HourlyEmployee cHourlyEmployee ("Jim Stuart", 10.0, 40.0);


  cout << cEmployee << "\n\n";

  cout << cHourlyEmployee << "\n\n";
  
  // call a function from the base class
  cout << cHourlyEmployee.getName() << "\t$" ;

  // call a function from the derived class
  cout << fixed << setprecision(2) << cHourlyEmployee.getPay() << "\n";

  return EXIT_SUCCESS;
}