#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "../../graphics/Window.hpp"

class Texture {

	private:
		Window window;

	public:
		// Texture Constructor and destructor :D*
		Texture();
		~Texture();

		// Forward declarations :D*
		SDL_Texture* loadTexture(std::string filepath, SDL_Renderer* renderer);
		void render(int x, int y, int w, int h, SDL_Texture* image, SDL_Renderer* renderer);
		void cleanup();

};

#endif // !1
