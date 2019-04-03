//**************************************************************************** 
// File name:	MovingCircle.cpp
// Author:		Aidan Lindsey
// Date:		4/15/2016
// Class:		CS 250
// Assignment:  06_MovingCircle
// Purpose:		To implement the functions created in the interface 
//              MovingCircle.h
// Hours:       12
//*****************************************************************************
#include <iostream>
#include "MovingCircle.h"

using namespace std;

/******************************************************************************
Construct:    MovingCircle

Description:  Default constructor, does nothing

Parameters:   None

Returned:     None
******************************************************************************/
MovingCircle::MovingCircle () : Circle (), cDirection (), cSpeed ()
{
}
/******************************************************************************
Construct:     MovingCircle - Constructor

Description:  Initializes the values in the Circles of the MovingCircle object

Parameters:   int XPosition - Position of the circle on the X axis
              int YPosition - Position of the circle on the Y axis
              int cRadius - radius of the circle
              int colorR - How much red the circle has
              int colorG -  How much green the circle has
              int colorB - how much blue the circle has
              int colorA - How bright the circle is
              Direction 2D cDirection - Direction2D object that holds the
                                        direction that a circle is moving
              Speed cSpeed - Speed object that holds the speed for moving on
                             the X axis and the Y axis

Returned:     None
******************************************************************************/
MovingCircle::MovingCircle (int XPosition, int YPosition, int cRadius, 
                            int colorR, int colorG, int colorB, int colorA, 
                            Direction2D cDirection, Speed cSpeed)
: Circle (XPosition, YPosition, cRadius, colorR, colorG, colorB, colorA), 
          cDirection (cDirection), cSpeed (cSpeed)
{
}
/******************************************************************************
Function:       istream &operator >>

Description:    extracts the information from the file and puts it into the
                MovingCircle Object

Parameters:     istream& in - reads the file from MovingCircle.txt to be read 
                              and used
                MovingCircle &cMovingCircle - Object of the class 
                                              MovingCircle

Returned:       in - allows the information from the text file to be
                     manipulated and used elsewhere
******************************************************************************/
istream& operator >> (istream& in, MovingCircle &cMovingCircle)
{
    if (in.peek () == EOF)
    {
        return in;
    }

    in >> cMovingCircle.mXPosition;
    in >> cMovingCircle.mYPosition;
    in >> cMovingCircle.mRadius;
    in >> cMovingCircle.mRed;
    in >> cMovingCircle.mGreen;
    in >> cMovingCircle.mBlue;
    in >> cMovingCircle.mAlpha;
    in >> cMovingCircle.cDirection;
    in >> cMovingCircle.cSpeed;

    return in;
}
/******************************************************************************
Function:       getDirection

Description:    Gets the Direction for the circle

Parameters:     None

Returned:       cDirection

******************************************************************************/
Direction2D MovingCircle::getDirection () const
{
    return cDirection;
}
/******************************************************************************
Function:       setDirection

Description:    Set the direction of the circle from the getDirection function

Parameters:     Direction2D Direction - Direction2D object that holds the 
                                        the direction of the circle

Returned:       None

******************************************************************************/
void MovingCircle::setDirection (Direction2D Direction)
{
    cDirection = Direction;
}
/******************************************************************************
Function:       getSpeed

Description:    get the X and Y speed for a circle

Parameters:     None

Returned:       cSpeed

******************************************************************************/
Speed MovingCircle::getSpeed () const
{
    return cSpeed;
}
/******************************************************************************
Function:       setSpeed

Description:    Sets the X and Y speed of a circle from the getSpeed function

Parameters:     Speed Speed - Speed object array that holds the speed of the 
                              circle for the X and Y axis.

Returned:       None

******************************************************************************/
void MovingCircle::setSpeed (Speed Speed)
{
    cSpeed = Speed;
}
/******************************************************************************
Function:       moveCircle

Description:    Updates the direction and X and Y values of the circles,
                allowing the circles to move across the screen

Parameters:     int windowSizeX - the X axis size of the display screen

Returned:       None

******************************************************************************/
void MovingCircle::moveCircle (int windowSizeX, int windowSizeY)
{

    if ((mXPosition - mRadius) <= 0 || (mXPosition + mRadius) >= windowSizeX)
    {
        cDirection = cDirection.reflectOnSide ();       
    }
    if ((mYPosition - mRadius) <= 0)
    {
        cDirection = cDirection.reflectOnTop ();
    }
    if ((mYPosition + mRadius) >= windowSizeY)
    {
        cDirection = cDirection.reflectOnBottom ();
    }


    mXPosition = mXPosition + (cDirection.getXMove () * cSpeed.getXSpeed ());
    mYPosition = mYPosition + (cDirection.getYMove () * cSpeed.getYSpeed ());
}
/******************************************************************************
Function:       setRandomDirection ()

Description:    Sets a random direction to the circle

Parameters:     None

Returned:       None

******************************************************************************/
void MovingCircle::setRandomDirection ()
{
    int number = rand () % 8;
    switch (number)
    {
    case 0: 
        cDirection = Direction2D::CompassDirection::NORTH;
        break;
    case 1:
        cDirection = Direction2D::CompassDirection::NORTHEAST;
        break;
    case 2:
        cDirection = Direction2D::CompassDirection::EAST;
        break;
    case 3:
        cDirection = Direction2D::CompassDirection::SOUTHEAST;
        break;
    case 4:
        cDirection = Direction2D::CompassDirection::SOUTH;
        break;
    case 5:
        cDirection = Direction2D::CompassDirection::SOUTHWEST;
        break;
    case 6:
        cDirection = Direction2D::CompassDirection::WEST;
        break;
    case 7:
        cDirection = Direction2D::CompassDirection::NORTHWEST;
        break;
    }
    moveTheCircles ();
}
/******************************************************************************
Function:       bounceMovingCircle

Description:    Bounces the circle depending on what side they hit

Parameters:     int top - top of the window
                int bottom - bottom of the window
                int left - left side of the window
                int right - right side of the window

Returned:       None
******************************************************************************/
void MovingCircle::bounceMovingCircle (int top, int bottom, int left, int right)
{
    if (mXPosition - mRadius <= top)
    {
        cDirection = cDirection.reflectOnTop ();
    }
    if (mYPosition + mRadius >= bottom)
    {
        cDirection = cDirection.reflectOnBottom ();
    }
    if (mXPosition - mRadius <= left)
    {
        cDirection = cDirection.reflectOnSide ();
    }
    if (mYPosition + mRadius >= right)
    {
        cDirection = cDirection.reflectOnSide ();
    }
    moveTheCircles ();
}
/******************************************************************************
Function:       randomSpeed

Description:    Sets a random speed to the circle

Parameters:     None

Returned:       None

******************************************************************************/
void MovingCircle::randomSpeed ()
{
    cSpeed.setXSpeed ((rand () % 3));
    cSpeed.setYSpeed ((rand () % 3));
}
/******************************************************************************
Function:       pauseSpeed ()

Description:    Temporarily slows the speed of the circle to 0

Parameters:     None

Returned:       None

******************************************************************************/
void MovingCircle::pauseSpeed ()
{
    cSpeed.setXSpeed (0);
    cSpeed.setYSpeed (0);
}
/******************************************************************************
Function:       moveTheCircle

Description:    Updates the direction and X and Y values of the circles,
                allowing the circles to move across the screen but without 
                any parameters

Parameters:     None

Returned:       None

******************************************************************************/
void MovingCircle::moveTheCircles ()
{
    mXPosition = mXPosition + (cDirection.getXMove () * cSpeed.getXSpeed ());
    mYPosition = mYPosition + (cDirection.getYMove () * cSpeed.getYSpeed ());
    int x = cDirection.getXMove ();
    int y = cDirection.getYMove ();
    int xSpeed = cSpeed.getXSpeed ();
    int ySpeed = cSpeed.getYSpeed ();
    mXPosition += (xSpeed * x);
    mYPosition += (ySpeed * y);
}