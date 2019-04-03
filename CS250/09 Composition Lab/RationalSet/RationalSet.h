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
#include "Rational.h"

using namespace std;

class RationalSet
{
public:
    RationalSet();

    void add (const Rational & cItem);
    void print(ostream &out) const;
    RationalSet set_union(const RationalSet & cOtherSet) const;
    bool RationalSet::contains(const Rational & cItem) const;

private:
    static const int MAX_SIZE = 100;
    int mSize;
    Rational mSetArray[MAX_SIZE];

};