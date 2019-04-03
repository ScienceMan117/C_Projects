//**************************************************************************** 
// File name:	Direction2D.cpp
// Author:		Doug Ryan
// Date:		  1/13/2016
// Class:		  CS 250
// Assignment:SDL_MovingCircle
// Purpose:		Represent a direction
//*****************************************************************************

#include "Direction2D.h"
#include <string>

const string Direction2D::CompassDirectionNames[] =
{
    "NORTH", "NORTHEAST", "EAST", "SOUTHEAST",
    "SOUTH", "NORTHWEST", "WEST", "SOUTHWEST"
};


//****************************************************************************
// Constructor:	Direction2D
//
// Description:	Initialize the Direction to the argument given
//
// Parameters:	CompassDirection - the direction to use
//
// Returned:		none
//***************************************************************************
Direction2D::Direction2D (CompassDirection direction)
{

    mCompassDirection = direction;

    setMoveByCompassDirection ();
}

//****************************************************************************
// Method:	    setMoveByCompassDirection
//
// Description:	Set the x and y movement based on the current 
//              compass direction
//
// Parameters:  none
//
// Returned:	  none
//***************************************************************************
void Direction2D::setMoveByCompassDirection ()
{
    int x = 0, y = 0;

    switch (mCompassDirection)
    {
    case NORTH:
        x = 0;
        y = -1;
        break;
    case NORTHEAST:
        x = 1;
        y = -1;
        break;
    case EAST:
        x = 1;
        y = 0;
        break;
    case SOUTHEAST:
        x = 1;
        y = 1;
        break;
    case SOUTH:
        x = 0;
        y = 1;
        break;
    case SOUTHWEST:
        x = -1;
        y = 1;
        break;
    case WEST:
        x = -1;
        y = 0;
        break;
    case NORTHWEST:
        x = -1;
        y = -1;
        break;
    }

    mXMove = x;
    mYMove = y;
}

//****************************************************************************
// Method:	    getCompassDirection
//
// Description:	get the current compass direction
//
// Parameters:  none
//
// Returned:	  CompassDirection - the current compass direction
//***************************************************************************
const Direction2D::CompassDirection Direction2D::getCompassDirection () const
{
    return mCompassDirection;
}


//****************************************************************************
// Method:	    reflectOnSide
//
// Description:	change the compass direction to reflect a bounce off the side
//              of the screen
//
// Parameters:  none
//
// Returned:	  CompassDirection - the new compass direction
//***************************************************************************
const Direction2D Direction2D::reflectOnSide () const
{
    int dir = mCompassDirection;

    dir += 4;
    dir %= 8;

    return Direction2D (static_cast<Direction2D::CompassDirection>(dir));
}

//****************************************************************************
// Method:	    reflectOnTop
//
// Description:	change the compass direction to reflect a bounce off the top
//              of the screen
//
// Parameters:  none
//
// Returned:	  CompassDirection - the new compass direction
//***************************************************************************
const Direction2D Direction2D::reflectOnTop () const
{
    int dir = mCompassDirection;

    if (dir % 2 == 0)
    {
        dir += 4;
        dir %= 8;
    }
    else
    {
        dir += 2;
        dir %= 8;
    }
    return Direction2D (static_cast<Direction2D::CompassDirection>(dir));
}

//****************************************************************************
// Method:	    reflectOnBottom
//
// Description:	change the compass direction to reflect a bounce off the 
//              bottom of the screen
//
// Parameters:  none
//
// Returned:	  CompassDirection - the new compass direction
//***************************************************************************
const Direction2D Direction2D::reflectOnBottom () const
{
    int dir = mCompassDirection;

    if (dir % 2 == 0)
    {
        dir += 4;
        dir %= 8;
    }
    else
    {
        dir -= 2;
        dir %= 8;
    }

    return Direction2D (static_cast<Direction2D::CompassDirection>(dir));
}

//****************************************************************************
// Method:	    getXMove
//
// Description:	get the current X move
//
// Parameters:  none
//
// Returned:	  int - the x move
//***************************************************************************
int Direction2D::getXMove () const
{

    return mXMove;

}

//****************************************************************************
// Method:	    getYMove
//
// Description:	get the current Y move
//
// Parameters:  none
//
// Returned:	  int - the y move
//***************************************************************************
int Direction2D::getYMove () const
{
    return mYMove;
}

//****************************************************************************
// Function:	  operator>> (friend of the class)
//
// Description:	Re in a direction from the stream. The direction in the file
//              must be written as a string that matches a value in
//              Direction2D::CompassDirectionNames
//
// Parameters:  in - the stream to read from
//              cDir - the direction to fill
//
// Returned:	  istream& - the stream read from
//***************************************************************************

istream& operator>>(istream& in, Direction2D &cDir)
{
    string compassDir;

    in >> compassDir;

    cDir.setCompassDirection (compassDir);

    return in;
}

//****************************************************************************
// Method:	    setCompassDirection
//
// Description:	Set the compass direction based on a string that matches
//              a value in Direction2D::CompassDirectionNames and also
//              set the x and y move.
//
// Parameters:  string - the name of the direction
//
// Returned:	  none
//***************************************************************************
void Direction2D::setCompassDirection (string compassDir)
{
    for (int i = 0; i < NUMBER_OF_DIRECTIONS; i++)
    {
        if (CompassDirectionNames[i] == compassDir)
        {
            mCompassDirection = static_cast<CompassDirection>(i);
        }
    }
    setMoveByCompassDirection ();
}
