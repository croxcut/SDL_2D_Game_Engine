#include "Texture.hpp"

Texture::Texture()
{
	// TODO: Nothing for now :D*
}

Texture::~Texture()
{
	// Freeup stuff :D*
	cleanup();
}

SDL_Texture* Texture::loadTexture(std::string filepath, SDL_Renderer* renderer)
{
	// Final texture
	SDL_Texture* finalTexture = nullptr;

	// load image :D*
	SDL_Surface* loadedImage = IMG_Load(filepath.c_str());
	if (loadedImage == NULL)
	{
		std::cout << "Failed to load Image: " << filepath.c_str() << " | Error: " << IMG_GetError() << std::endl;
	}
	else
	{	
		// Convert Image to a propper texture :D*
		finalTexture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		if (finalTexture == NULL)
		{
			std::cout << "Failed to Create Texture! | Error: " << IMG_GetError() << std::endl;
		}

		// Destroy the previous image( since we just created a texture from it ) :D*
		SDL_FreeSurface(loadedImage);
		loadedImage = nullptr;
	}
	
	return finalTexture; // returns the propper texture :D*

}

void Texture::cleanup()
{
	// Freeup Stuff :D*
	SDL_Quit();
	IMG_Quit();
}

void Texture::render(int x, int y, int w, int h, SDL_Texture* image, SDL_Renderer* renderer)
{
	// Previous Implementation :D*
	/*
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
	*/
	
	// A much better implementation :D*
	SDL_Rect rect = {x, y, w, h};
	
	// Render the given texture :D*
	SDL_RenderCopy(renderer, image, NULL, &rect);
}