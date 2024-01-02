#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <iostream>
#include <SDL.h>
#include "../utils/Utils.hpp"
#include "../utils/AssetLoader.hpp"

class Window
{
public:
	SDL_Window* window = nullptr;		// Window that we're gonna render into :D*
	SDL_Renderer* renderer = nullptr;	// Handles the rendering of our streamed texture :D*

public:
	// Forward Declarations 
	bool init();
	void cleanup();
};

#endif

