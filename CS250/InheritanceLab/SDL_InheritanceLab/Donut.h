#pragma once

#include "Circle.h"

// subclass Circle produces a Donut class
class Donut : public Circle
{
public: 
    Donut ();
    Donut (int XLocation, int YLocation, int cRadius, SDL_Color oColor, int iRadius, SDL_Color iColor);
    void draw (SDL_Renderer *pRenderer) const;

private:
    int mRadius;
    SDL_Color mInnerColor;

};