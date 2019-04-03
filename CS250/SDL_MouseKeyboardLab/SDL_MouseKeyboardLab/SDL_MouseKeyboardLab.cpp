//**************************************************************************** 
// File name:	main.cpp
// Author:		Chadd Williams
// Date:		1/11/2016
// Class:		CS 250
// Assignment:	SDL_KeyboardControl
// Purpose:		Demonstrate keyboard control to move a sprite
//*****************************************************************************

#include "SDL.h"
#include "SDL_image.h"
#include "SDL2_gfxPrimitives.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
  int windowXPos = 100,
    windowYPos = 100,
    windowSizeX = 640,
    windowSizeY = 640;

  // we will want to control how fast the screen is updated
  const int FRAMES_PER_SECOND = 60;
  int delay;
  int fps = FRAMES_PER_SECOND;
  unsigned int totalMilliSeconds = SDL_GetTicks();

  int startTime, endTime;

  SDL_Window *pWindow = nullptr;
  SDL_Renderer *pRenderer = nullptr;
  SDL_Event sdlEvent;
  int x, y;

  bool bIsRunning = true;

  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
    return false;
  }

  pWindow = SDL_CreateWindow("User Control", windowXPos, windowYPos,
    windowSizeX, windowSizeY, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);

  if (nullptr == pWindow)
  {
    std::cout << "Failed to create window : " << SDL_GetError();
    return false;
  }

  pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

  if (nullptr == pRenderer)
  {
    std::cout << "Failed to create renderer : " << SDL_GetError();
    return false;
  }

  totalMilliSeconds = SDL_GetTicks();

  // Sprite
  // add SDL2_image.lib
 
  // load file
  SDL_Rect rect;
  SDL_Texture *pTexture = IMG_LoadTexture(pRenderer, "images\\logo.png");

  // find the width and height of the image
  SDL_QueryTexture(pTexture, NULL, NULL, &rect.w, &rect.h);

  //set the location of the image
  rect.x = 100;
  rect.y = 100;
  // end Sprite



  // animation loop!
  while (bIsRunning)
  {
      if (SDL_PollEvent (&sdlEvent) != 0)
      {
          if (SDL_MOUSEBUTTONDOWN == sdlEvent.type)
          {
              SDL_GetMouseState (&x, &y);
              rect.x = x;
              rect.y = y;
          }
          if (SDL_KEYDOWN == sdlEvent.type)
          {
              switch (sdlEvent.key.keysym.scancode)
              {
              case SDL_SCANCODE_UP:
                  rect.y -= 2; 
                  break;
              case SDL_SCANCODE_DOWN:
                  rect.y += 2;
                  break;
              case SDL_SCANCODE_LEFT:
                  rect.x -= 2;
                  break;
              case SDL_SCANCODE_RIGHT:
                  rect.x += 2;
                  break;
              }
          }
          if (SDL_QUIT == sdlEvent.type)
          {
              bIsRunning = false;
          }
      }

    startTime = SDL_GetTicks();

    // Set color of renderer to gray
    SDL_SetRenderDrawColor(pRenderer, 77, 82, 84, 255);

    SDL_RenderClear(pRenderer);

    // render the image on to the screen.
    
    SDL_RenderCopy(pRenderer, pTexture, NULL, &rect);

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

  SDL_DestroyTexture(pTexture);
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  SDL_Quit();


  return EXIT_SUCCESS;
}