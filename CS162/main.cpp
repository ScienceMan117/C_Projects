//******************************************************************************
// File Name:		main.cpp
// Author:			Aidan Lindsey
// Date:				1/24/15
// Class:				CS150-01
// Assignment:	Binary Calculator
// Purpose:			Use functions to turn decimal numbers into binary numbers.
//******************************************************************************
#include <iostream>

using namespace std;

int main ()
{
  double decimalNumber;
  int powerOf;
  int binaryNumber;

  cout << "Input a decimal number: " << endl;
  cin >> decimalNumber;

  for (int substriptCounter = 0; substriptCounter <= decimalNumber; ++substriptCounter)
  {
    powerOf = 2 ^ substriptCounter;
  }

  cout << endl << powerOf;

  return EXIT_SUCCESS;
}