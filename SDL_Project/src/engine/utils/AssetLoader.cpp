#include "AssetLoader.hpp"

void AssetLoader::init(SDL_Window* window, SDL_Renderer* renderer)
{
	// We call this after the window is created
	// might change a couple things as i go
	// along 
	this-> m_Renderer = renderer;
	this-> m_Window = window;

	if (m_Renderer == NULL || m_Window == NULL)
	{
		std::cout << "Failed to initialize Assetloader! | Error: " << SDL_GetError() << std::endl;
	}
}

bool AssetLoader::loadMedia()
{
	// Load Texture from file :D*
	texture = loadTexture("res/images/sample.png");
	if (texture == NULL)
	{
		std::cout << "Failed to Load Image at specified path!" << std::endl;
		return false;
	}

	return true;
}

SDL_Texture* AssetLoader::loadTexture(std::string filepath)
{
	// The Final texture loaded from a surface :D*
	SDL_Texture* finalSurface = nullptr;

	// Load image at specified path :D*
	SDL_Surface* loadedImage = IMG_Load(filepath.c_str());
	if (loadedImage == NULL)
	{
		std::cout << "Unable to Load Image: " << filepath.c_str() << " | Error: " << SDL_GetError() << std::endl;
	}
	else
	{	
		// Convert the surface to a texture image :D*
		finalSurface = SDL_CreateTextureFromSurface(m_Renderer, loadedImage);
		if (finalSurface == NULL)
		{
			std::cout << "Unable to Optimize Image: " << filepath.c_str() << " | Error: " << SDL_GetError() << std::endl;
		}

		// Freeup the loaded image since there's no use for it now :D*
		SDL_FreeSurface(loadedImage);
	}

	return finalSurface;
}

void AssetLoader::cleanup()
{
	// Free Up resources back to the System
	SDL_DestroyRenderer(m_Renderer);
	m_Window = nullptr;

	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;

	// Quit SDL Libraries :D*
	SDL_Quit();
}

void AssetLoader::render(int x, int y, int w, int h)
{	
	// Render the texture to the Window
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderCopy(m_Renderer, texture, NULL, &rect);
}