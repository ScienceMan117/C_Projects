//**************************************************************************** 
// File name:	HelloSDL.cpp
// Author:		Chadd Williams
// Date:		  1/7/2016
// Class:		  CS 250
// Assignment:HelloSDL
// Purpose:		Demonstrate hello world using SDL
//*****************************************************************************

#include "SDL.h"				// main SDL header
#include "SDL_ttf.h"			// true type font
#include <iostream>
#include "SDL2_gfxPrimitives.h"
#include <ctime>
#include <cstdlib>

using namespace std;


//****************************************************************************
// Function:	  main
//
// Description:	Display the words Hello World on the screen
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


	SDL_Window *pWindow;
	SDL_Renderer *pRenderer;
	TTF_Font *pFont;


	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	pWindow = SDL_CreateWindow("Hello SDL!", windowXPos, windowYPos,
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

	TTF_Init();
	pFont = TTF_OpenFont("C:/Windows/Fonts/verdana.ttf", 50);

	if (nullptr == pFont)
	{
		cout << "Error: No Font" << endl;
		exit(EXIT_FAILURE);
	}

	// Write "Hello World" on to a Surface
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *pSurface = TTF_RenderText_Blended(pFont, "Hello World", color);
	if (nullptr == pSurface)
	{
		std::cout << "Failed to create surface : " << SDL_GetError();
		return false;
	}

	// Map the Surface onto a Texture
	SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
	if (nullptr == pTexture)
	{
		std::cout << "Failed to create texture : " << SDL_GetError();
		return false;
	}
	
	// Render the Texture with our message.
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = 0;
	dst.y = 0;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(pTexture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(pRenderer, pTexture, NULL, &dst);

	// write hello on the window using SDL2	_gfxPrimitives.h
	stringRGBA(pRenderer, 400, 400, "Hello", 255, 255, 255, 255);

	// Actually Render the changes above
	SDL_RenderPresent(pRenderer);
	SDL_Delay(3000);

	SDL_FreeSurface(pSurface);
	TTF_CloseFont(pFont);
	SDL_DestroyTexture(pTexture);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	return EXIT_SUCCESS;
}