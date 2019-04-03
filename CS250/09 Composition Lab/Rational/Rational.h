//**************************************************************************** 
// File name:	Rational.h
// Author:		Doug Ryan
// Date:		  2/24/2016
// Class:		  CS 250
// Assignment:Rational Lab
// Purpose:		Demonstrate classes
//****************************************************************************

#pragma once

#include <ostream>

using namespace std;

class Rational
{
  public:
    Rational (int = 0, int = 1);

    void print (ostream &output) const;
    bool equals (const Rational &cRational) const;
    Rational multiply (const Rational &cRational) const;


    friend istream& operator >> (istream& in, Rational &cRational);
    friend ostream& operator << (ostream& out, const Rational &cRational);
    friend Rational operator*(const Rational &cLeft, const Rational &cRight);

  private:
    int mNumerator;
    int mDenominator;

    void setNumerator(int);
    void setDenominator(int);

};
