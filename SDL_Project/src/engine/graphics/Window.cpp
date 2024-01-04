#include "Window.hpp"


Window::Window()
{
	// Window Constructor :D*
	// sets initializers value to nullptr[nothing] :D*
	window = nullptr;
	renderer = nullptr;
}

Window::~Window()
{
	// Freeup stuff if the class
	// is out of scope :D*
	cleanup();
}

bool Window::init()
{
	// Initalize SDL! :D*
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Couldn't Initialize SDL! | Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else
	{
		// Setup Window Paramter :D&
		window = SDL_CreateWindow(
			TITLE.c_str(),				// Window Title
			SDL_WINDOWPOS_CENTERED,		//
			SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
		);

		// Check if failed to create Window :D*, returns a false flag :D*
		if (window == NULL)
		{
			std::cout << "Window Creation Failed! | Error: " << SDL_GetError() << std::endl;
			return false;
		}
		else
		{
			// Create Renderer :D*
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			// Check if faield to create Renderer, returns a false flag :D*
			if (renderer == NULL)
			{
				std::cout << "Failed to Create Renderer! | Error: " << SDL_GetError() << std::endl;
				return false;
			}
			else
			{
				// Set Background Color :D*
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

				// Initialize SDL_Image :D*
				int image = IMG_INIT_PNG;

				// Check if failed to initialize :D*
				if (!(IMG_Init(image) & image))
				{
					std::cout << "SDL_Image Could not be Initialize! | Error: " << IMG_GetError() << std::endl;
					return false;
				}
			}
		}
	}

	return true;
}

SDL_Renderer* Window::getRenderer()
{
	return renderer;
}

SDL_Window* Window::getWindow()
{
	return window;
}

void Window::cleanup()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	window = nullptr;
	renderer = nullptr;

	SDL_Quit();
}