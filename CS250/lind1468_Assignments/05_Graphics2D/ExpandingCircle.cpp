//**************************************************************************** 
// File name:	ExpandingCircle.cpp
// Author:		Aidan Lindsey
// Date:		4/29/2016
// Class:		CS 250
// Assignment:  07_Boomshine
// Purpose:		Implement the functions created in the ExpandingCircle 
//              interface              
// Hours:       17      
//*****************************************************************************
#include <iostream>
#include "ExpandingCircle.h"

/******************************************************************************
Construct:    ExpandingCircle

Description:  Initializes the mRadius value

Parameters:   None

Returned:     None
******************************************************************************/
ExpandingCircle::ExpandingCircle () : Circle (), mIncreaseExpansion (0), mRateExpansion (0), mTimeExpansion (0), mBounce (0)
{
    mRadius = INITIAL_RADIUS;
}
/******************************************************************************
Construct:      ExpandingCircle - Constructor

Description:    Initializes the values of the expanding circle

Parameters:     int XPosition - x position of circle
                int YPosition - y position of circle
                int cRadius - radius of circle
                int colorR - color red of circle
                int colorG - color green of circle
                int colorB - color blue of circle
                int colorA - color alpha of circle
                int increaseExpansion - how much circle expands
                int rateExpansion - speed of the expansion
                int timeExpansion - time of the expansion
                int bounce - the counter for the circle
              

Returned:
******************************************************************************/
ExpandingCircle::ExpandingCircle (int XPosition, int YPosition, int cRadius,
                                  int colorR, int colorG, int colorB, 
                                  int colorA, int increaseExpansion, 
                                  int rateExpansion, int timeExpansion, int bounce) 
                                  : Circle (XPosition, YPosition, cRadius, 
                                  colorR, colorG, colorB, colorA),
                                  mIncreaseExpansion (increaseExpansion), 
                                  mRateExpansion (rateExpansion), 
                                  mTimeExpansion (timeExpansion), mBounce (ZERO)
{
}
/******************************************************************************
Function:       ExpandCircle     

Description:    Expands the circle

Parameters:     none

Returned:       none

******************************************************************************/

void ExpandingCircle::expandCircle ()
{
    while (mRadius < 60)
    {
        mRadius++;
    }
}
/******************************************************************************
Function:       setIncreaseExpansion

Description:    sets increase of expansion of a circle

Parameters:     int increaseExpansion - how much circle expands
                int increaseExpansion - how much circle expands
                int rateExpansion - speed of the expansion
                int timeExpansion - time of the expansion
                int bounce - the counter for the circle

Returned:       none

******************************************************************************/
void ExpandingCircle::setIncreaseExpansion (int increaseExpansion)
{
    mIncreaseExpansion = increaseExpansion;
}
/******************************************************************************
Function:       setRateExpansion

Description:    sets rate of expansion of a circle

Parameters:     int rateExpansion - speed of the expansion

Returned:       none

******************************************************************************/
void ExpandingCircle::setRateExpansion (int rateExpansion)
{
    mRateExpansion = rateExpansion;
}
/******************************************************************************
Function:       setTimeExpansion

Description:    sets time of expansion of a circle

Parameters:     int timeExpansion - time of the expansion

Returned:       none

******************************************************************************/
void ExpandingCircle::setTimeExpansion (int timeExpanison)
{
    mTimeExpansion = timeExpanison;
}
/******************************************************************************
Function:       getCounter

Description:    gets the bounce of the circle

Parameters:     None

Returned:       mBounce

******************************************************************************/
int ExpandingCircle::getCounter () const
{
    return mBounce;
}
/******************************************************************************
Function:       getTimeExpansion

Description:    gets the time of expansion of the circle

Parameters:     None

Returned:       mTimeExpansion

******************************************************************************/
int ExpandingCircle::getTimeExpansion () const
{
    return mTimeExpansion;
}

