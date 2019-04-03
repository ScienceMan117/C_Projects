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
    friend istream& operator >> (istream& in, Circle &cCircle);
    void setPosition (int x, int y);
    void draw (/*SDL_Renderor *pr*/);


private: int pRender;
         int x;
         int y;
         int radius;
         int red;
         int green;
         int blue;
         int alpha;
};