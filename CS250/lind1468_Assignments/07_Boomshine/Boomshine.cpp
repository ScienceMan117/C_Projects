//**************************************************************************** 
// File name:	Boomshine.cpp
// Author:		Aidan Lindsey
// Date:		4/29/2016
// Class:		CS 250
// Assignment:  07_Boomshine
// Purpose:		Implement the functions created in the Boomshine
//              interface              
// Hours:       17      
//*****************************************************************************
#include "Boomshine.h"
#include <ctime>

using namespace std;
/******************************************************************************
Construct:    Boomshine

Description:  Initializes values for boomshine

Parameters:   None

Returned:     None
******************************************************************************/
Boomshine::Boomshine ()
{
    mXWindowSize = X_WINDOW;
    mYWindowSize = Y_WINDOW;
    mLevel = DEFAULT_LEVEL;
    mNumberMovingCircles = mLevel * NUMBER_CIRCLES_MULTIPLER;
    mNumberExpandingCircles = ZERO;
    
}
/******************************************************************************
Construct:    Boomshine

Description:  Initializes values for boomshine

Parameters:   int level - level of the boomshine game

Returned:     None
******************************************************************************/
Boomshine::Boomshine (int level)
{
    mXWindowSize = X_WINDOW;
    mYWindowSize = Y_WINDOW;
    mLevel = level;
    mNumberMovingCircles = mLevel * NUMBER_CIRCLES_MULTIPLER;
    mNumberExpandingCircles = ZERO;
    mExpandingCircles.setColorR (rand () % REASONABLE_COLOR_REALM);
    mExpandingCircles.setColorG (rand () % REASONABLE_COLOR_REALM);
    mExpandingCircles.setColorB (rand () % REASONABLE_COLOR_REALM);
    mExpandingCircles.setColorA (rand () % REASONABLE_COLOR_REALM);
    mExpandingCircles.setXPosition (CIRCLE_LOCATION);
    mExpandingCircles.setYPosition (CIRCLE_LOCATION);
    mExpandingCircles.setRadius (NUMBER_EXPANSIONS);
}
/******************************************************************************
Function:       randomizeCircles ()

Description:    Creates random values for the elements of a circle

Parameters:     None

Returned:       None
******************************************************************************/
void Boomshine::randomizeCircles ()
{
    for (int i = 0; i < mNumberMovingCircles; i++)
    {
        MovingCircleArray[i].setRadius ((rand () % RANDOM_RADIUS_INTERVAL) + LOWEST_RANDOM_RADIUS);
        MovingCircleArray[i].setXPosition ((rand () % (mXWindowSize - 3 * MovingCircleArray[i].getRadius ())) + MovingCircleArray[i].getRadius () + 1);
        MovingCircleArray[i].setYPosition ((rand () % (mYWindowSize - 3 * MovingCircleArray[i].getRadius ())) + MovingCircleArray[i].getRadius () + 1);
        MovingCircleArray[i].setColorR (rand () % REASONABLE_COLOR_REALM);
        MovingCircleArray[i].setColorG (rand () % REASONABLE_COLOR_REALM);
        MovingCircleArray[i].setColorB (rand () % REASONABLE_COLOR_REALM);
        MovingCircleArray[i].setColorA (COLOR_A_NONTRANSPARENT);
        MovingCircleArray[i].setRandomDirection ();
        MovingCircleArray[i].randomSpeed ();
    }
}
/******************************************************************************
Function:       moveAllCircles

Description:    Moves the moving circles in the game

Parameters:     int top - top of the screen
                int bottom - bottom of screen
                int left - left side of screen
                int right - right side of screen

Returned:       None
******************************************************************************/
void Boomshine::moveAllCircles (int top, int bottom, int left, int right)
{
    for (int i = 0; i < mNumberMovingCircles; i++)
    {
        MovingCircleArray[i].moveCircle (mXWindowSize, mYWindowSize);
    }
}
/******************************************************************************
Function:       drawAllCircles

Description:    draws all the circles to the screen

Parameters:     SDL_Renderer * pRenderer - screen color

Returned:       None
******************************************************************************/
void Boomshine::drawAllCircles (SDL_Renderer *pRenderer) const
{
    for (int i = 0; i < mNumberMovingCircles; i++)
    {
        MovingCircleArray[i].draw (pRenderer);
    }
}
/******************************************************************************
Function:       makeUserExpandingCircles

Description:    Makes the Expanding circles the x and y positions

Parameters:     int xPosition - x position of expanding circle
                int yPositon - y position of expanding circle

Returned:       None
******************************************************************************/
void Boomshine::makeUserExpandingCircle (int xPosition, int yPosition)
{
    mExpandingCircles.setXPosition (xPosition);
    mExpandingCircles.setYPosition (yPosition);
}
/******************************************************************************
Function:       getNumberCircles

Description:    gets the number of circles

Parameters:     None

Returned:       mNumberMovingCircles
******************************************************************************/
int Boomshine::getNumberCircles () const
{
    return mNumberMovingCircles;
}
/******************************************************************************
Function:       getNumberExpandingCircles

Description:    gets the number of expanding circles

Parameters:     None

Returned:       mNumberExpandingCircles
******************************************************************************/
int Boomshine::getNumberExpandingCircles () const
{
    return mNumberExpandingCircles;
}
/******************************************************************************
Function:       setXWindowSize 

Description:    sets the x side of the window size

Parameters:     int xWindowSize - size of the x side of the window

Returned:       None
******************************************************************************/
void Boomshine::setXWindowSize (int xWindowSize)
{
    mXWindowSize = xWindowSize;
}
/******************************************************************************
Function:       setYWindowSize

Description:    sets the y side of the window size

Parameters:     int yWindowSize - size of the y side of the window

Returned:       None
******************************************************************************/
void Boomshine::setYWindowSize (int yWindowSize)
{
    mYWindowSize = yWindowSize;
}
/******************************************************************************
Function:       drawExpandingCircle

Description:    Draws a single expanding circle

Parameters:     SDL_Renderer * pRenderer - screen color

Returned:       None
******************************************************************************/
void Boomshine::drawExpandingCircle (SDL_Renderer * pRenderer) const
{

     mExpandingCircles.draw (pRenderer);
 
    
}
/******************************************************************************
Function:       expandCircles ()

Description:    Expands a single expanding circle

Parameters:     None

Returned:       None
******************************************************************************/
void Boomshine::expandCircles ()
{
    mExpandingCircles.expandCircle ();
}
/******************************************************************************
Function:       ExpansionCircleCreation 

Description:    Expands the circles depending on the radius

Parameters:     None

Returned:       None
******************************************************************************/
void Boomshine::ExpansionCircleCreation ()
{
    for (int i = 0; i < mNumberMovingCircles; i++)
    {
        
            if ((MovingCircleArray[i].getRadius () + mExpandingCircles.getRadius ()) * (MovingCircleArray[i].getRadius () + mExpandingCircles.getRadius ()) >= (MovingCircleArray[i].getXPosition () - mExpandingCircles.getXPosition ()) * (MovingCircleArray[i].getXPosition () - mExpandingCircles.getXPosition ()) + (MovingCircleArray[i].getYPosition () - mExpandingCircles.getYPosition ()) * (MovingCircleArray[i].getYPosition () - mExpandingCircles.getYPosition ()))
            {
                ExpandingCircleArray[mNumberExpandingCircles].setXPosition (MovingCircleArray[i].getXPosition ());
                ExpandingCircleArray[mNumberExpandingCircles].setYPosition (MovingCircleArray[i].getYPosition ());
                ExpandingCircleArray[mNumberExpandingCircles].setRadius (ExpandingCircle::INITIAL_RADIUS);
                ExpandingCircleArray[mNumberExpandingCircles].setColorR (MovingCircleArray[i].getColorR ());
                ExpandingCircleArray[mNumberExpandingCircles].setColorG (MovingCircleArray[i].getColorG ());
                ExpandingCircleArray[mNumberExpandingCircles].setColorB (MovingCircleArray[i].getColorB ());
                ExpandingCircleArray[mNumberExpandingCircles].setColorA (MovingCircleArray[i].getColorA ());
                ExpandingCircleArray[mNumberExpandingCircles].setIncreaseExpansion (INCREASE_EXPANSION);
                ExpandingCircleArray[mNumberExpandingCircles].setRateExpansion (RATE_EXPANSION);
                ExpandingCircleArray[mNumberExpandingCircles].setTimeExpansion (TIME_EXPANSION);
            }
            mNumberExpandingCircles++;
            for (int k = i; k < mNumberMovingCircles; k++)
            {
                MovingCircleArray[k] = MovingCircleArray[k + 1];
            }
            mNumberMovingCircles--;

    }
    for (int i = 0; i < mNumberMovingCircles; i++)
    {
        for (int j = 0; j < mNumberExpandingCircles; j++)
        {
                if ((MovingCircleArray[i].getRadius () + ExpandingCircleArray[j].getRadius ()) * MovingCircleArray[i].getRadius () + ExpandingCircleArray[j].getRadius () >= (MovingCircleArray[i].getXPosition () - ExpandingCircleArray[j].getXPosition ())*(MovingCircleArray[i].getXPosition () - ExpandingCircleArray[j].getXPosition () + (MovingCircleArray[i].getXPosition () - ExpandingCircleArray[j].getXPosition ())*(MovingCircleArray[i].getXPosition () - ExpandingCircleArray[j].getXPosition ())))
                {
                    ExpandingCircleArray[mNumberExpandingCircles].setXPosition (MovingCircleArray[i].getXPosition ());
                    ExpandingCircleArray[mNumberExpandingCircles].setYPosition (MovingCircleArray[i].getYPosition ());
                    ExpandingCircleArray[mNumberExpandingCircles].setRadius (ExpandingCircle::INITIAL_RADIUS);
                    ExpandingCircleArray[mNumberExpandingCircles].setColorR (MovingCircleArray[i].getColorR ());
                    ExpandingCircleArray[mNumberExpandingCircles].setColorG (MovingCircleArray[i].getColorG ());
                    ExpandingCircleArray[mNumberExpandingCircles].setColorB (MovingCircleArray[i].getColorB ());
                    ExpandingCircleArray[mNumberExpandingCircles].setColorA (MovingCircleArray[i].getColorA ());
                    ExpandingCircleArray[mNumberExpandingCircles].setIncreaseExpansion (INCREASE_EXPANSION);
                    ExpandingCircleArray[mNumberExpandingCircles].setRateExpansion (RATE_EXPANSION);
                    ExpandingCircleArray[mNumberExpandingCircles].setTimeExpansion (TIME_EXPANSION);

                    mNumberExpandingCircles++;

                    for (int k = i; k < mNumberMovingCircles; k++)
                    {
                        MovingCircleArray[k] = MovingCircleArray[k + 1];
                    }
                    mNumberMovingCircles--;
                }
        }
    }
}
/******************************************************************************
Function:       expandExpandingCircles 

Description:    Draws all the circles of expanding circle

Parameters:     None

Returned:       None
******************************************************************************/
void Boomshine::expandExpandingCircles ()
{
    mExpandingCircles.expandCircle ();
}
