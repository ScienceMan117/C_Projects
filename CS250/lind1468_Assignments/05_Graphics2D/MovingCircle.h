//**************************************************************************** 
// File name:	MovingCircle.h
// Author:		Aidan Lindsey
// Date:		4/15/2016
// Class:		CS 250
// Assignment:  06_MovingCircle
// Purpose:		Derived class of Circle which creates the interface for drawing
//               moving circles to the screen that is the base class.
// Hours:       12
//*****************************************************************************
#pragma once

#include <iostream>
#include "Circle.h"
#include "Direction2D.h"
#include "Speed.h"
#include "ExpandingCircle.h"


class MovingCircle : public Circle
{
public:
    MovingCircle ();
    MovingCircle (int XPosition, int YPosition, int cRadius, int colorR, 
                  int colorG, int colorB, int colorA, Direction2D cDirection, 
                  Speed cSpeed);

    Direction2D getDirection () const;
    void setDirection (Direction2D Direction);
    Speed getSpeed () const;
    void setSpeed (Speed Speed);
    void moveCircle (int windowSizeX, int windowSizeY);
    friend istream& operator >> (istream& in, MovingCircle &cMovingCircle);  
    void setRandomDirection ();
    void bounceMovingCircle (int top, int bottom, int left, int right);
    void randomSpeed ();
    void pauseSpeed ();
    void moveTheCircles ();

private:
    static int const MAX_EXPANSIONS = 15;
    Direction2D cDirection;
    Speed cSpeed;
};