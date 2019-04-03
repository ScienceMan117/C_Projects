//**************************************************************************** 
// File name:	Circle.cpp
// Author:		Aidan Lindsey
// Date:		4/6/2016
// Class:		CS 250
// Assignment:  SDL Introduction
// Purpose:		To implement the functions created in Circle.h to be used in
//              the 05_CircleTestDriver.cpp
// Hours:       8
//*****************************************************************************
#include <iostream>
#include "Circle.h"

using namespace std;

/******************************************************************************
Constructor:  Circle

Description:  Default constructor that initalizies the position, size and color
              of the circle.

Parameters:   None

Returned:     None
******************************************************************************/
Circle::Circle ()
{
    mXPosition = 0;
    mYPosition = 0;
    mRadius = 0;
    mRed = 0;
    mGreen = 0;
    mBlue = 0;
    mAlpha = 0;
}
/******************************************************s************************
Constructor:  Circle

Description:  Build a circle based on the provided parameters.

Parameters:   None

Returned:     None
******************************************************************************/
Circle::Circle (int cXPosition, int cYPosition, int cRadius, int cColorR, int cColorG, int cColorB, int cColorA)
: mXPosition (cXPosition), mYPosition (cYPosition), mRadius (cRadius), mRed (cColorR), mGreen (cColorG), mBlue (cColorB), mAlpha (cColorA)
{
}
/******************************************************************************
Function:       istream &operator >>

Description:    extracts the information from the file and puts it into the 
                specific elements

Parameters:     istream& in - reads the file from Circle.txt to be read and
                used
                Circle &cCircle - Object array of the class Circle

Returned:       in - allows the information from the text file to be 
                     manipulated and used elsewhere
******************************************************************************/
istream &operator >> (istream& in, Circle &cCircle)
{
    if (in.peek () == EOF)
    {
        return in;
    }
    in >> cCircle.mXPosition;
    in >> cCircle.mYPosition;
    in >> cCircle.mRadius;
    in >> cCircle.mRed;
    in >> cCircle.mGreen;
    in >> cCircle.mBlue;
    in >> cCircle.mAlpha;

    return in;
}
/******************************************************************************
Function:    draw

Description: Draws circles to the screen depending on the circle information

Parameters:  SDL_Renderer *pRenderer - the background color 

Returned:    None
******************************************************************************/
void Circle::draw (SDL_Renderer *pRenderer) const
{
    filledCircleRGBA (pRenderer, mXPosition, mYPosition, mRadius, mRed, 
                      mGreen, mBlue, mAlpha);
}
/******************************************************************************
Function:    getRadius

Description: Get the radius

Parameters:  None

Returned:    mRadius
******************************************************************************/
int Circle::getRadius () const
{
    return mRadius;
}
/******************************************************************************
Function:    setXPosition

Description: Set the X position

Parameters:  int cXPosition - x coordinate of the circle

Returned:    None
******************************************************************************/
void Circle::setXPosition (int cXPosition)
{
    mXPosition = cXPosition;
}
/******************************************************************************
Function:    setYPosition

Description: Set the Y position

Parameters:  int cYPosition - y coordinate of the circle

Returned:    None
******************************************************************************/
void Circle::setYPosition (int cYPosition)
{
    mYPosition = cYPosition;
}
/******************************************************************************
Function:    setRadius

Description: Set the radius

Parameters:  int cRadius - radius of the circle

Returned:    None
******************************************************************************/
void Circle::setRadius (int cRadius)
{
    mRadius = cRadius;
}
/******************************************************************************
Function:    setColorR

Description: Set the color red

Parameters:  int cColorR - red color of the circle

Returned:    None
******************************************************************************/
void Circle::setColorR (int cColorR)
{
    mRed = cColorR;
}
/******************************************************************************
Function:    setColorG

Description: Set the color green

Parameters:  int cColorG - green color of the circle

Returned:    None
******************************************************************************/
void Circle::setColorG (int cColorG)
{
    mGreen = cColorG;
}
/******************************************************************************
Function:    setColorB

Description: Set the color blue

Parameters:  int cColorB - blue color of the circle

Returned:    None
******************************************************************************/
void Circle::setColorB (int cColorB)
{
    mBlue = cColorB;
}
/******************************************************************************
Function:    setColorA

Description: Set the color alpha

Parameters:  int cColorG - alpha color of the circle

Returned:    None
******************************************************************************/
void Circle::setColorA (int cColorA)
{
    mAlpha = cColorA;
}
/******************************************************************************
Function:    getXPosition

Description: Get the x position

Parameters:  None

Returned:    mXPosition
******************************************************************************/
int Circle::getXPosition () const
{
    return mXPosition;
}
/******************************************************************************
Function:    getYPosition

Description: Get the y position

Parameters:  None

Returned:    mYPosition
******************************************************************************/
int Circle::getYPosition () const
{
    return mYPosition;
}
/******************************************************************************
Function:    getColorR

Description: Get the color red

Parameters:  None

Returned:    mRed
******************************************************************************/
int Circle::getColorR () const
{
    return mRed;
}
/******************************************************************************
Function:    getColorG

Description: Get the color green

Parameters:  None

Returned:    mGreen
******************************************************************************/
int Circle::getColorG () const
{
    return mGreen;
}
/******************************************************************************
Function:    getColorB

Description: Get the color blue

Parameters:  None

Returned:    mBlue
******************************************************************************/
int Circle::getColorB () const
{
    return mBlue;
}
/******************************************************************************
Function:    getColorA

Description: Get the color alpha

Parameters:  None

Returned:    mAlpha
******************************************************************************/
int Circle::getColorA () const
{
    return mAlpha;
}