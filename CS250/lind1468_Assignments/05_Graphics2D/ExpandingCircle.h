//**************************************************************************** 
// File name:	ExpandingCircle.h
// Author:		Aidan Lindsey
// Date:		4/29/2016
// Class:		CS 250
// Assignment:  07_Boomshine
// Purpose:		Create the interface for the expanding circles   
// Hours:       17   
//*****************************************************************************
#pragma once

#include <iostream>
#include "Circle.h"

using namespace std;

class ExpandingCircle : public Circle
{
public:
    static const int INITIAL_RADIUS = 15;
    ExpandingCircle ();
    ExpandingCircle (int XPosition, int YPosition, int cRadius, int colorR,
        int colorG, int colorB, int colorA, int increaseExpansion, int rateExpansion, int timeExpansion, int bounce);
    void expandCircle ();
    void setIncreaseExpansion (int increaseExpansion);
    void setRateExpansion (int rateExpansion);
    void setTimeExpansion (int timeExpanison);
    int getCounter () const;
    int getTimeExpansion () const;

protected:
    static const int TEST = 15;
    static const int ZERO = 0;
    int mIncreaseExpansion;
    int mRateExpansion;
    int mTimeExpansion;
    int mBounce;
};