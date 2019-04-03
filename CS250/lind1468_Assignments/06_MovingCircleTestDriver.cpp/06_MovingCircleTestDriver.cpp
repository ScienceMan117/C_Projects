//**************************************************************************** 
// File name:	06_MovingCircleTestDriver.cpp
// Author:		Aidan Lindsey
// Date:		4/15/2016
// Class:		CS 250
// Assignment:  06_MovingCircle
// Purpose:		To print colors of a particular size and color to a particular
//              position from a file using object-oriented program using
//              multiple classes, inheritance, friends and operator 
//              overloading
// Hours:       12
//*****************************************************************************

#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include "MovingCircle.h"
#include "Circle.h"
#include "Direction2D.h"
#include <fstream>

using namespace std;

//****************************************************************************
// Function:	main
//
// Description:	Display bouncing circle to the window 
//
// Parameters:  None
//
// Returned:	int - EXIT_SUCCESS
//***************************************************************************

int main (int argc, char *argv[])
{
    int windowXPos = 100,
        windowYPos = 100,
        windowSizeX = 640,
        windowSizeY = 640;

    SDL_Window *pWindow = nullptr;
    SDL_Renderer *pRenderer = nullptr;
    SDL_Event sdlEvent;
    ifstream inFile;
    const int MAX_CIRCLES = 5;
    const int FRAMES_PER_SECOND = 60;
    int numCircles = 0;
    int delay;
    int fps = FRAMES_PER_SECOND;
    int startTime, endTime;
    unsigned int totalMilliSeconds = SDL_GetTicks ();
    bool bIsRunning = true;
    MovingCircle cMovingCircles[MAX_CIRCLES];

    inFile.open ("MovingCircles.txt");

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

    pWindow = SDL_CreateWindow ("User Control", windowXPos, windowYPos,
        windowSizeX, windowSizeY, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);


    if (nullptr == pWindow)
    {
        std::cout << "Failed to create window : " << SDL_GetError ();
        return false;
    }

    pRenderer = SDL_CreateRenderer (pWindow, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderSetLogicalSize (pRenderer, windowSizeX, windowSizeY);

    if (nullptr == pRenderer)
    {
        std::cout << "Failed to create renderer : " << SDL_GetError ();
        return false;
    }

    totalMilliSeconds = SDL_GetTicks ();


    // Reads the circle information from the file to the Circle object array

    while (!inFile.eof () && numCircles < MAX_CIRCLES)
    {
        inFile >> cMovingCircles[numCircles];
        numCircles++;
    }

    // Program keeps running until the user exits out of the program
    while (bIsRunning)
    {
        if (SDL_PollEvent (&sdlEvent) != 0)
        {
            if (SDL_QUIT == sdlEvent.type)
            {
                bIsRunning = false;
            }
        }

        startTime = SDL_GetTicks ();

        // Set color of renderer to gray
        SDL_SetRenderDrawColor (pRenderer, 0, 128, 128, 255);

        SDL_RenderClear (pRenderer);

        for (int i = 0; i < numCircles; i++)
        {
            cMovingCircles[i].draw (pRenderer);
            cMovingCircles[i].moveCircle (windowSizeX, windowSizeY);
        }
        
        SDL_RenderPresent (pRenderer);

        // decide how fast to update the screen.
        if (-1 != FRAMES_PER_SECOND)
        {
            // force a particular number of frames per second
            endTime = SDL_GetTicks ();
            if (1000 / FRAMES_PER_SECOND > endTime - startTime)
            {
                delay = 1000 / FRAMES_PER_SECOND - (endTime - startTime);
                SDL_Delay (delay);
                // uncomment to see how much of a delay is needed.
                //cout << delay << " ";
            }


            ++fps;

            if (totalMilliSeconds + 1000 < SDL_GetTicks ())
            {
                totalMilliSeconds = SDL_GetTicks ();
                fps = 0;
            }
        }
        else
        {
            // just delay for 1 millisecond
            SDL_Delay (1);
        }
    }
    SDL_DestroyRenderer (pRenderer);
    SDL_DestroyWindow (pWindow);
    SDL_Quit ();
    inFile.close ();

    return EXIT_SUCCESS;
}