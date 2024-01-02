#ifndef ASSETLOADER_HPP
#define ASSETLOADER_HPP

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


class AssetLoader
{
public:
	SDL_Texture* texture = nullptr;

private:
	// Private Member variables for initialization :D*
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;

public:
	// Forward Declarations :D*
	void init(SDL_Window* window, SDL_Renderer* renderer);
	bool loadMedia();
	SDL_Texture* loadTexture(std::string filepath);
	void cleanup();
	void render(int x, int y, int w, int h);

private:

};

#endif 

