//**************************************************************************** 
// File name:	Speed.cpp
// Author:		Aidan Lindsey
// Date:		4/15/2016
// Class:		CS 250
// Assignment:  06_MovingCircle
// Purpose:		To implement the functions created in the interface 
//              Speed.h
// Hours:       12
//*****************************************************************************
#include <iostream>
#include "Speed.h"

using namespace std;
/******************************************************************************
Constructor:    Speed 

Description:    Initiates the X and Y axis speeds

Parameters:     None

Returned:       None

******************************************************************************/
Speed::Speed ()
{
    mXSpeed = 0;
    mYSpeed = 0;
}
/******************************************************************************
Function:       getXSpeed

Description:    Get the XSpeed for moving Circle

Parameters:     None

Returned:       mXSpeed

******************************************************************************/
int Speed::getXSpeed () const
{
    return mXSpeed;
}
/******************************************************************************
Function:       setXSpeed

Description:    Sets the X speed for moving circle from the getXSpeed function

Parameters:     int XSpeed - the XSpeed of the moving circle

Returned:       None

******************************************************************************/
void Speed::setXSpeed (int XSpeed)
{
    mXSpeed = XSpeed;
}
/******************************************************************************
Function:       getYSpeed

Description:    Gets the Y Speed of the moving circle

Parameters:     None

Returned:       None

******************************************************************************/
int Speed::getYSpeed () const
{
    return mYSpeed;
}
/******************************************************************************
Function:       setYSpeed

Description:    Sets the Y speed for moving circle from the getYSpeed function

Parameters:     int YSpeed - the YSpeed of the moving circle

Returned:       None

******************************************************************************/
void Speed::setYSpeed (int YSpeed)
{
    mYSpeed = YSpeed;
}
/******************************************************************************
Function:       istream& operator >>

Description:    Extracts X speed and Y speed from the file and puts into the 
                Speed object

Parameters:     istream &in - reads the file from MovingCircle.txt to be read 
                              and used
                Speed &cSpeed - Object of the derived class Speed

Returned:       in

******************************************************************************/
istream& operator >> (istream &in, Speed &cSpeed)
{
    if (in.peek () == EOF)
    {
        return in;
    }

    in >> cSpeed.mXSpeed;
    in >> cSpeed.mYSpeed;

    return in;
}
