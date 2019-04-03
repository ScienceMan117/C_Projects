//**************************************************************************** 
// File name:	Employee.h
// Author:		Doug Ryan
// Date:		  4/5/2016
// Class:		  CS 250
// Assignment: Inheritance Lab
// Purpose:		Demonstrate Inheritance
//*****************************************************************************

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Employee
{
  public:
    Employee (string name = "");
    string getName () const;
    void setName (string);

    friend ostream& operator<<(ostream &, const Employee &cEmp);

  private:
    string mName;
};

