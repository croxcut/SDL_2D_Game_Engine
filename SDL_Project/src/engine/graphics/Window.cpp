#include "Window.hpp"

bool Window::init()
{
	// Create an Asset Loader instance :D*
	AssetLoader asset; 

	// Initialize SDL :D*
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to initialize SDL! | Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else
	{
		// Create Window :D*
		window = SDL_CreateWindow(
			TITLE.c_str(),					// Window Title :D*
			SDL_WINDOWPOS_CENTERED,			// Render The Window to the Center of the Screen :D*
			SDL_WINDOWPOS_CENTERED,			//	||	   ||   ||   ||  ||   ||   ||  ||   ||
			SCREEN_WIDTH,					// Window Width :D*
			SCREEN_HEIGHT,					// Window Height :D*
			SDL_WINDOW_SHOWN				// Display the Window tot the Screen :D*
		);
		
		// Returns a false flag if we failed to create Window :D*
		if (window == NULL)
		{
			std::cout << "Failed to create Window! | Error: " << SDL_GetError() << std::endl;
			return false;
		}
		else
		{
			// Create Renderer :D*
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				std::cout << "Renderer could not be created! | Error: " << SDL_GetError() << std::endl;
				return false;
			}
			else
			{
				// Set Background color :D*
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

				// Initialize SLD_Image so we can load PNG files :D*
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL_Image Couldnot be initialize! | Error: " << IMG_GetError() << std::endl;
					return false;
				}
			}
		}
	}

	return true;
}

void Window::cleanup() 
{
	// Free Up resources back to the System :D*
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	// Quit SDL Libraries :D*
	SDL_Quit();
}