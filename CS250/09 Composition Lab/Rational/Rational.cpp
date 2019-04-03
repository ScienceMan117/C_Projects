//**************************************************************************** 
// File name:	Rational.cpp
// Author:		Doug Ryan
// Date:		  2/24/2016
// Class:		  CS 250
// Assignment:Rational Lab
// Purpose:		Demonstrate classes
//****************************************************************************

#include "Rational.h"
#include <ostream>
#include <iostream>

using namespace std;

//****************************************************************************
// Constructor:	Rational
//
// Description:	Initialize a Rational object
//
// Parameters:  numerator - the numerator to use
//              denominator - the denominator to use
//
// Returned:	  none
//***************************************************************************
Rational::Rational (int numerator, int denominator)
{
  setNumerator(numerator);
  setDenominator(denominator);
}

//****************************************************************************
// Method:	    print
//
// Description:	print a rational number to the screen.
//              The format is: numerator/denominator
//
// Parameters:  output - the stream to write to
//
// Returned:	  none
//***************************************************************************
void Rational::print (ostream &output) const
{
  output << mNumerator << "/" << mDenominator;
}


//****************************************************************************
// Method:	    setNenominator
//
// Description:	set the numerator to the provided value.
//
// Parameters:  int - the numerator
//
// Returned:	  none
//***************************************************************************

void Rational::setNumerator (int numerator)
{
  mNumerator = numerator;
}

//****************************************************************************
// Method:	    setDenominator
//
// Description:	set the denominator to the provided value.
//
// Parameters:  int - the denominator
//
// Returned:	  none
//***************************************************************************

void Rational::setDenominator (int denominator)
{
  if (denominator > 0)
  {
    mDenominator = denominator;
  }
}

//****************************************************************************
// Method:	    equals
//
// Description:	test if the provided Rational is equal to the current Rationl
//
// Parameters:  cRational - the Rational to test against
//
// Returned:	  bool - true if equal, false otherwise
//***************************************************************************

bool Rational::equals (const Rational &cRational) const
{
  return  (cRational.mNumerator == mNumerator && 
           cRational.mDenominator == mDenominator);
}

//****************************************************************************
// Method:	    multiply
//
// Description:	multiply the current Rational with the provided Rational
//
// Parameters:  cRational - the Rational to multiply with
//
// Returned:	  Rational - the result of multiplication
//***************************************************************************

Rational Rational::multiply (const Rational &cRational) const
{
  Rational cRationalResult;
  cRationalResult.setNumerator(mNumerator * cRational.mNumerator);
  cRationalResult.setDenominator (mDenominator * cRational.mDenominator);
  return cRationalResult;
}
//istream& operator >> (istream& In, Rational &cRational)
//{
//    char ch;
//    In >> cRational.mNumerator;
//}
//Rational operator*(const Rational &cLeft, const Rational &cRight)
//{
//    Rational cNewRat(cLeft.)
//}
//Rational Rational::operator*(const Rational &cRight) const
//{
//    Rational cNewRat(mNumerator) * cRight.mNumerator;
//}