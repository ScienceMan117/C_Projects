//**************************************************************************** 
// File name:	Boomshine.h
// Author:		Aidan Lindsey
// Date:		4/29/2016
// Class:		CS 250
// Assignment:  07_Boomshine
// Purpose:		Create the interface for the boomshine circles   
// Hours:       17   
//*****************************************************************************
#include "MovingCircle.h"
#include "ExpandingCircle.h"

class Boomshine
{
public:
    Boomshine ();
    Boomshine (int level);
    void randomizeCircles ();
    void moveAllCircles (int top, int bottom, int left, int right);
    void drawAllCircles (SDL_Renderer *pRenderer) const;
    void makeUserExpandingCircle (int xPosition, int yPosition);
    void drawExpandingCircle (SDL_Renderer * pRenderer) const;
    void expandCircles ();
    void ExpansionCircleCreation ();
    int getNumberCircles () const;
    int getNumberExpandingCircles () const;

    void expandExpandingCircles ();
    void expandDrawExpandingCircle (SDL_Renderer *pRenderer) const;

    void setXWindowSize (int xWindowSize);
    void setYWindowSize (int yWindowSize);

    void setExpandingCircleConditions (int index);



private:
    static const int DEFAULT_LEVEL = 1;
    static const int MAX_CIRCLES = 50;
    static const int NUMBER_CIRCLES_MULTIPLER = 5;
    static const int LOWEST_RANDOM_RADIUS = 10;
    static const int RANDOM_RADIUS_INTERVAL = 10;
    static const int COLOR_A_NONTRANSPARENT = 255;
    static const int REASONABLE_COLOR_REALM = 200;
    static const int NUMBER_DIRECTIONS = 8;
    static const int HIGHEST_SPEED = 3;
    static const int USER_CIRCLE_COLOR_R = 102;
    static const int USER_CIRCLE_COLOR_G = 0;
    static const int USER_CIRCLE_COLOR_B = 204;
    static const int INCREASE_EXPANSION = 1;
    static const int RATE_EXPANSION = 2;
    static const int TIME_EXPANSION = 120;
    static const int NUMBER_EXPANSIONS = 15;
    static const int X_WINDOW = 640;
    static const int Y_WINDOW = 640;
    static const int ZERO = 0;
    static const int CIRCLE_LOCATION = -100;

    int mLevel;
    int mXWindowSize;
    int mYWindowSize;
    int mNumberMovingCircles;
    int mNumberExpandingCircles;
    
    ExpandingCircle mExpandingCircles;
    MovingCircle MovingCircleArray[MAX_CIRCLES];
    ExpandingCircle ExpandingCircleArray[MAX_CIRCLES];

};