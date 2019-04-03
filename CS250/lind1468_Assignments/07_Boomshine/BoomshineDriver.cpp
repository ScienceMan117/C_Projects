//**************************************************************************** 
// File name:	BoomshineDriver.cpp
// Author:		Aidan Lindsey
// Date:		4/29/2016
// Class:		CS 250
// Assignment:  07_Boomshine
// Purpose:		Calls the functions of boomshine.h and creates the boomshine    
//              game
// Hours:       17   
//*****************************************************************************
#include <ctime>
#include "Boomshine.h"

using namespace std;



int main (int argc, char *argv[])
{
    const int FRAMES_PER_SECOND = 60;
    const int TOP_WINDOW_POSITION = 0;
    const int BOTTOM_WINDOW_POSITION = 640;
    const int LEFT_WINDOW_POSITION = 0;
    const int RIGHT_WINDOW_POSITION = 0;
    const int MAX_MOUSE_COUNT = 1;
    int windowXPos = 100,
        windowYPos = 100,
        windowSizeX = 640,
        windowSizeY = 640;

    int delay;
    int fps = FRAMES_PER_SECOND;
    int startTime, endTime;
    int xMouse;
    int yMouse;
    unsigned int totalMilliSeconds = SDL_GetTicks ();

    SDL_Window *pWindow = nullptr;
    SDL_Renderer *pRenderer = nullptr;
    SDL_Event sdlEvent;
    const int MAX_CIRCLES = 5;

    int numCircles = 0;
    int mouseCount = 0;
    bool bIsRunning = true;
    bool bClick = false;
    Boomshine cBoomshineObject (5);

    srand ((unsigned int)time (NULL));

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
    cBoomshineObject.randomizeCircles ();

    while (bIsRunning)
    {
        if (SDL_PollEvent (&sdlEvent) != 0)
        {
            if (SDL_QUIT == sdlEvent.type)
            {
                bIsRunning = false;
            }
            
            if (SDL_MOUSEBUTTONDOWN == sdlEvent.type && bClick == false)
            {
                SDL_GetMouseState (&xMouse, &yMouse);
                cBoomshineObject.makeUserExpandingCircle (xMouse, yMouse);
                bClick = true;               
            }
        }
        startTime = SDL_GetTicks ();

        SDL_SetRenderDrawColor (pRenderer, 255, 255, 255, 255);

        SDL_RenderClear (pRenderer);

      
        cBoomshineObject.drawAllCircles (pRenderer);
        cBoomshineObject.moveAllCircles (TOP_WINDOW_POSITION, BOTTOM_WINDOW_POSITION, LEFT_WINDOW_POSITION, RIGHT_WINDOW_POSITION);

        if (true == bClick)
        {
                cBoomshineObject.drawExpandingCircle (pRenderer);          
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

    return EXIT_SUCCESS;
}