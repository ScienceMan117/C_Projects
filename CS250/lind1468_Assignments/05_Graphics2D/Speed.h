//**************************************************************************** 
// File name:	Speed.h
// Author:		Aidan Lindsey
// Date:		4/15/2016
// Class:		CS 250
// Assignment:  06_MovingCircle
// Purpose:		Derived class of Circle that creates interface needed to obtain 
//              the individual speeds of the X and Y axis
// Hours:       12
//*****************************************************************************
#pragma once

#include <iostream>
#include "Circle.h"

using namespace std;

class Speed : public Circle
{
public:
    Speed ();
    int getXSpeed () const;
    void setXSpeed (int XSpeed);
    int getYSpeed () const;
    void setYSpeed (int YSpeed);
    friend istream& operator >> (istream &in, Speed &cSpeed);

private:
    int mXSpeed;
    int mYSpeed;
};