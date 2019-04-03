//**************************************************************************** 
// File name:	Direction2D.h
// Author:		Doug Ryan
// Date:		  1/13/2016
// Class:		  CS 250
// Assignment:SDL_MovingCircle
// Purpose:		Represent a direction
//*****************************************************************************

#pragma once

#include <iostream>

using namespace std;

class Direction2D
{
public:
    static const int NUMBER_OF_DIRECTIONS = 8;

    static enum CompassDirection {
        NORTH, NORTHEAST, EAST, SOUTHEAST,
        SOUTH, NORTHWEST, WEST, SOUTHWEST
    };

    static const string CompassDirectionNames[];


    Direction2D (CompassDirection = NORTH);

    const Direction2D reflectOnSide () const;
    const Direction2D reflectOnTop () const;
    const Direction2D reflectOnBottom () const;

    int getXMove () const;
    int getYMove () const;

    const CompassDirection getCompassDirection () const;

    friend istream& operator>>(istream& in, Direction2D &cDir);

private:
    CompassDirection mCompassDirection;
    int mXMove;
    int mYMove;

    void setCompassDirection (string compassDir);
    void setMoveByCompassDirection ();

};
