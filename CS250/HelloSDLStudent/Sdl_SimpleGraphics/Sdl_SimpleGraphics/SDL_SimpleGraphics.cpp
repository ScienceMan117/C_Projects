//**************************************************************************** 
// File name:	SDL_SimpleGraphics.cpp
// Author:		Chadd Williams
// Date:		  1/8/2016
// Class:		  CS 250
// Assignment:SDL_SimpleGraphics
// Purpose:		Demonstrate rendering simple graphics to the screen
//*****************************************************************************

#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>

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

int main(int argc, char *argv[])
{
  int windowXPos = 100,
    windowYPos = 100,
    windowSizeX = 1024,
    windowSizeY = 1024;

  SDL_Window *pWindow;
  SDL_Renderer *pRenderer;
  const int NUMBER_OF_CIRCLES = 5;

  // http://linux.die.net/man/3/srand
  /*srand(time(NULL));*/

  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    std::cout << " Failed to initialize SDL : " << SDL_GetError() 
      << std::endl;
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

  // Set color of renderer to teal
  SDL_SetRenderDrawColor(pRenderer, 0, 128, 128, 255);

  // Clear the window and make it all teal
  SDL_RenderClear(pRenderer);

  // Change color to blue!
  SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255);
  
  for (int i = 0; i < 2; i++)
  {
      int x = rand () % windowSizeX;
      int y = rand () % windowSizeY;
      filledCircleRGBA (pRenderer, x/*100*/, y/*100*/, 25, 0, 0, 255, 255);
  }
 
  
 
  // Render the changes above
  SDL_RenderPresent(pRenderer);
  SDL_Delay(30000);

  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  SDL_Quit();

  return EXIT_SUCCESS;
}