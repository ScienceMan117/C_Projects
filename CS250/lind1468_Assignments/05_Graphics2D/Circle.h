//**************************************************************************** 
// File name:	Circle.h
// Author:		Aidan Lindsey
// Date:		4/6/2016
// Class:		CS 250
// Assignment:  SDL Introduction
// Purpose:		To create the interface for drawing circles to the screen      
// Hours:       8
//*****************************************************************************
#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include <time.h>
#include <ctime>
#include <cstdlib>
using namespace std;

class Circle
{
public:
    Circle ();
    Circle (int cXPosition, int cYPosition, int cRadius, int cColorR, int cColorG, int cColorB, int cColorA);
    friend istream& operator >> (istream& in, Circle &cCircle);
    void draw (SDL_Renderer *pRenderer) const;
    // getcolor functions
    int getColorR () const;
    int getColorG () const;
    int getColorB () const;
    int getColorA () const;
    int getRadius () const;
    int getXPosition () const;
    int getYPosition () const;
    void setXPosition (int cXPosition);
    void setYPosition (int cYPosition);
    void setRadius (int cRadius);
    void setColorR (int cColorR);
    void setColorG (int cColorG);
    void setColorB (int cColorB);
    void setColorA (int cColorA);
    
protected:
         int mXPosition;
         int mYPosition;
         int mRadius;
         int mRed;
         int mGreen;
         int mBlue;
         int mAlpha;
};