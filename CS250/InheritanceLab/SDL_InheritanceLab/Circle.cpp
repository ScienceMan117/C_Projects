//**************************************************************************** 
// File name:	circle.cpp
// Author:		Chadd Williams
// Date:		  1/13/2016
// Class:		  CS 250
// Assignment:	SDL_SimpleAnimation
// Purpose:		  Build a class to represent a circle
//*****************************************************************************

#include "Circle.h"

//****************************************************************************
// Constructor:	Circle
//
// Description:	Default constructor, create a white circle at 0,0 of radius 1
//
// Parameters:	none
//
// Returned:		none
//***************************************************************************
Circle::Circle()
{
  mX = 0;
  mY = 0;
  mRadius = 1;
  mColor = { 255, 255, 255, 255 };
}

//****************************************************************************
// Constructor:	Circle
//
// Description:	Build a circle based on the provided parameters.
//
// Parameters:	x - int, x position
//              y - int, y position
//              radius - int, radius of the circle
//              color - SDL_Color, the color of the circle
//
// Returned:		none
//***************************************************************************
Circle::Circle(int x, int y, int radius, SDL_Color color)  
: mX(x), mY(y), mRadius(radius), mColor(color)
{
}

//****************************************************************************
// Method:	    render
//
// Description:	draw the circle on the renderer
//
// Parameters:	pRenderer - SDL_Renderer* the renderer to draw on
//
// Returned:		none
//***************************************************************************

void Circle::render(SDL_Renderer *pRenderer) const
{
  filledCircleRGBA(pRenderer, mX, mY, mRadius, mColor.r, 
    mColor.g, mColor.b, mColor.a);

}


//****************************************************************************
// Fucntion:	  operator>> (friend)
//
// Description:	Read the circle from a stream
//
// Parameters:	in - istream& , the stream to read from
//              cCircle - Circle&, the circle to read into
//
// Returned:		istream&, the input stream read from.
//***************************************************************************
istream& operator>>(istream &in, Circle& cCircle)
{
  int color;
  in >> cCircle.mX >> cCircle.mY >> cCircle.mRadius;

  in >> color;
  cCircle.mColor.r = color;

  in >> color;
  cCircle.mColor.g = color;

  in >> color;
  cCircle.mColor.b = color;

  in >> color;
  cCircle.mColor.a = color;

  return in;
}

