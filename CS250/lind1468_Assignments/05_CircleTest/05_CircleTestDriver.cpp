//**************************************************************************** 
// File name:	05_CircleTestDriver.cpp
// Author:		Aidan Lindsey
// Date:		4/6/2016
// Class:		CS 250
// Assignment:  SDL Introduction
// Purpose:		To print colors of a particular size and color to a particular
//              position from a file
// Hours:       8
//*****************************************************************************

#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Circle.h"
#include "MovingCircle.h"
#include "Direction2D.h"
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"

using namespace std;

//****************************************************************************
// Function:	  main
//
// Description:	Display a circle to the window 
//
// Parameters:  none
//
// Returned:	  int - EXIT_SUCCESS
//***************************************************************************

int main (int argc, char *argv[])
{
    int windowXPos = 100,
        windowYPos = 100,
        windowSizeX = 640,
        windowSizeY = 640;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    ifstream inFile;
    const int MAX_CIRCLES = 5;
    Circle cCircles[MAX_CIRCLES];
    int numCircles = 0;
 
    inFile.open ("Circle.txt");

    if (inFile.fail ())
    {
        cout << "File failed to open" << endl;
        return EXIT_FAILURE;
    }
    if (SDL_Init (SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << " Failed to initialize SDL : " << SDL_GetError ()
            << std::endl;
        return false;
    }

    pWindow = SDL_CreateWindow ("Simple Graphics", windowXPos, windowYPos,
        windowSizeX, windowSizeY, 0);

    if (nullptr == pWindow)
    {
        std::cout << "Failed to create window : " << SDL_GetError ();
        return false;
    }

    pRenderer = SDL_CreateRenderer (pWindow, -1, 0);

    if (nullptr == pRenderer)
    {
        std::cout << "Failed to create renderer : " << SDL_GetError ();
        return false;
    }

    SDL_RenderSetLogicalSize (pRenderer, windowSizeX, windowSizeY);

    SDL_SetRenderDrawColor (pRenderer, 0, 128, 128, 255);

    SDL_RenderClear (pRenderer);

    SDL_SetRenderDrawColor (pRenderer, 0, 0, 255, 255);
  
    // Reads the circle information from the file to the Circle object array
    while (!inFile.eof () && numCircles < MAX_CIRCLES)
    {
        inFile >> cCircles[numCircles];
        numCircles++;
    }
    // Draws the circles in the Circle object array to the screen
    for (int i = 0; i < numCircles; i++)
    {
        cCircles[i].draw (pRenderer);
    }
    SDL_RenderPresent (pRenderer);
    SDL_Delay (10000);

    SDL_DestroyRenderer (pRenderer);
    SDL_DestroyWindow (pWindow);
    SDL_Quit ();

    return EXIT_SUCCESS;
}