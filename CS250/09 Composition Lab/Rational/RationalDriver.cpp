//**************************************************************************** 
// File name:	RationalDriver.cpp
// Author:		Doug Ryan
// Date:		  2/24/2016
// Class:		  CS 250
// Assignment:Rational Lab
// Purpose:		Demonstrate Classes
//****************************************************************************

#include "Rational.h"
#include <iostream>

/****************************************************************************
Function:			main

Description:	Demonstrate and test the class Rational

Parameters:		none

Returned:			int - EXIT_SUCCESS
************************************************************************/
int main()
{
  Rational cR1, cR2 (4,1);
  Rational cR3 (1,2), cR4 (2,3), cR5;

  cR1.print (cout);
  cout << endl;

  cR2.print (cout);
  cout << endl;

  // cR1.setNumerator(2); // illegal

  if (cR1.equals (cR2))
  {
    cout << " SAME ";
  }
  else
  {
    cout << " DIFFERENT ";
  }
  cout << endl;

  if (cR1.equals(cR5))
  {
    cout << " SAME ";
  }
  else
  {
    cout << " DIFFERENT ";
  }
  cout << endl;

  cR5 = cR3.multiply (cR4);
  cR5.print (cout);

  cout << endl;

  /*cout << cR5 << endl;
  cin >> cR1;
  cout << cR1 << endl;

  cR1 = cR1 = cR5;
  cout << cR1 * cR1 * cR1 << endl;
*/
  return EXIT_SUCCESS;
}