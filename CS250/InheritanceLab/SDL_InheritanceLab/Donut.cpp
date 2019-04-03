#include "Donut.h"
#include <iostream>

using namespace std;

Donut::Donut () : Circle (), mInnerColor({ 0, 0, 0, 0 })
{

}
Donut::Donut (int XLocation, int YLocation, int cRadius, SDL_Color oColor, int iRadius, SDL_Color iColor) : 
Circle (XLocation, YLocation, cRadius, oColor), mRadius (iRadius), mInnerColor (iColor)
{
}
void Donut::draw (SDL_Renderer *pRenderer) const
{
    Circle::render (pRenderer);
    filledCircleRGBA (pRenderer, mX, mY, mRadius, mInnerColor.r,
        mInnerColor.g, mInnerColor.b, mInnerColor.a);
}