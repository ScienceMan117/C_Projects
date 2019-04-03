//**************************************************************************** 
// File name:	SDL_SimpleAnimation.cpp
// Author:		Chadd Williams
// Date:		  1/8/2016
// Class:		  CS 250
// Assignment:	SDL_SimpleAnimation
// Purpose:		Demonstrate simple animation with SDL
//*****************************************************************************

#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include <iostream>
using namespace std;

//****************************************************************************
// Function:	  main
//
// Description:	Display a simple circle moving across the window
//
// Parameters:  none
//
// Returned:	  int - EXIT_SUCCESS
//***************************************************************************

int main(int argc, char *argv[])
{
	int windowXPos = 100,
		windowYPos = 100,
		windowSizeX = 640,
		windowSizeY = 640;
	
	// we will want to control how fast the screen is updated
	const int FRAMES_PER_SECOND = 100;
	int delay;
	int fps = FRAMES_PER_SECOND;
	int totalMilliSeconds = SDL_GetTicks();

	int startTime, endTime;
	int x = 0;
	SDL_Window *pWindow;
	SDL_Renderer *pRenderer;


	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	pWindow = SDL_CreateWindow("Simple Graphics", windowXPos, windowYPos,
		windowSizeX, windowSizeY, 0);

	if (nullptr == pWindow)
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return false;
	}

	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

	if (nullptr == pRenderer)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize(pRenderer, windowSizeX, windowSizeY);

	totalMilliSeconds = SDL_GetTicks();

	x = 0;
	while ( x < windowSizeX)
	{
		startTime = SDL_GetTicks();

		
		// Set color of renderer to teal
		SDL_SetRenderDrawColor(pRenderer, 0, 128, 128, 255);

		// Clear the window and make it all teal
		SDL_RenderClear(pRenderer);

		// Render a circle
		// move the circle in the x direction

		filledCircleRGBA(pRenderer, x++, 375, 20, 0, 0, 255, 255);

		// Render the changes above
		SDL_RenderPresent(pRenderer);


		// decide how fast to update the screen.
		if (-1 != FRAMES_PER_SECOND)
		{
			// force a particular number of frames per second
			endTime = SDL_GetTicks();
			if (1000 / FRAMES_PER_SECOND > endTime - startTime)
			{
				delay = 1000 / FRAMES_PER_SECOND - (endTime - startTime);
				SDL_Delay(delay);
				// uncomment to see how much of a delay is needed.
				//cout << delay << " ";
			}
			++fps;

			if (totalMilliSeconds + 1000 < SDL_GetTicks())
			{

				totalMilliSeconds = SDL_GetTicks();
				fps = 0;
			}
		}
		else
		{
			// just delay for 1 millisecond
			SDL_Delay(1);
		}
		
	}

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	return EXIT_SUCCESS;
}