//**************************************************************************** 
// File name:	Employee.cpp
// Author:		Doug Ryan
// Date:		  4/5/2016
// Class:		  CS 250
// Assignment: Inheritance Lab
// Purpose:		Demonstrate Inheritance
//*****************************************************************************


#include "Employee.h"

#include <iostream>

using namespace std;

//****************************************************************************
// Constructor:	Employee
//
// Description:	Initialize the name with the parameter string
//
// Parameters:	name - the name to store in the object
//
// Returned:		none
//***************************************************************************
Employee::Employee (string name)
{
  mName = name;
}

//****************************************************************************
// Method:	    getName
//
// Description:	Retrieve the name of the Employee
//
// Parameters:	none
//
// Returned:		string - the name of the Employee
//***************************************************************************
string Employee::getName () const
{
  return mName;
}

//****************************************************************************
// Method:	    setName
//
// Description:	Set the name of the Employee
//
// Parameters:	string - the name of the Employee
//
// Returned:		none
//***************************************************************************

void Employee::setName (string name)
{
  mName = name;
}


//****************************************************************************
// Function:	  operator<<
//
// Description:	Output the Employee to the stream
//
// Parameters:	rcOutput - the stream to output to
//              cEmp - the Employee to output
//
// Returned:		ostream - the output stream
//***************************************************************************

ostream& operator<<(ostream & rcOutput, const Employee &cEmp)
{

  rcOutput << "Name: " << cEmp.getName ();
  return rcOutput;
}