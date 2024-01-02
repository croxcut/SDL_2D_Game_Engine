#include "Engine.hpp"

bool Engine::run()
{
	if (!window.init())
	{
		// Initializes Window :D*
		std::cout << "Failed to Initialize! " << std::endl;
		return false;
	}
	else
	{	
		// Initialize AssetLoader :D*
		asset.init(window.window, window.renderer);
		if (!asset.loadMedia())
		{
			// Checks if we successfully loaded a Texture :D*
			return false;
		}
		else
		{	
			int x = 0;
			int y = 0;
			int speed = 4;

			// This handles the input events :D*
			SDL_Event e;

			bool running = true; // Running flag :D*

			// Game Loop :D*
			while (running)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT) running = false;				

					// Poormans Movement code :D* (i will implement a much better one)
					int key = e.key.keysym.sym;

					if (key == SDLK_UP) y -= speed;		// Move Up
					if (key == SDLK_DOWN) y += speed;	// Move Down
					if (key == SDLK_LEFT) x -= speed;   // Move Left
					if (key == SDLK_RIGHT) x += speed;	// Move Right

				}

				// Clear Window :D*
				SDL_RenderClear(window.renderer);

				// Render Stuff to the Windwo :D*
				asset.render(x, y, 100, 100);

				// Update Window :D*
				SDL_RenderPresent(window.renderer);

			}
		}
	}

	return true;

}

void Engine::stop()
{	
	// Cleanup stuff :D*
	window.cleanup();
	asset.cleanup();
}