//**************************************************************************** 
// File name:	circle.h
// Author:		Chadd Williams
// Date:		  1/13/2016
// Class:		  CS 250
// Assignment:SDL_SimpleGraphicsClasses
// Purpose:		Build a class to represent a circle
//*****************************************************************************
#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"

using namespace std;

class Circle
{
public:

  Circle();

  Circle(int x, int y, int radius, SDL_Color color);


  void setPosition(int x, int y);

  void setRadius(int radius);

  void setColor(SDL_Color color);

  void render(SDL_Renderer *pRenderer) const;


  friend istream& operator>>(istream &in, Circle& cCircle);

protected:
  int mX;
  int mY;
  int mRadius;
  SDL_Color mColor;
};