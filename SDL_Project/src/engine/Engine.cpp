#include "Engine.hpp"

bool Engine::start()
{	
	// Initialize Window :D*
	if (!window.init())
	{
		std::cout << "Failed to Initialize Window" << std::endl;
		return false;
	}
	else
	{
		// Event listener ( this handles any kind of input events :D* )
		SDL_Event e;

		// Player speed :D*
		int speed = 4;

		// Running flag :D*
		bool running = true;

		// Game loop (kinda ass right now but will refactor later :D*)
		while (running)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT) running = false;

				// Initialize Input
				input.pressed(e);

				if (input.moveUp) player.y -= speed;
				if (input.moveDown) player.y += speed;
				if (input.moveLeft) player.x -= speed;
				if (input.moveRight) player.x += speed;

				// Release key input
				input.unpressed();
			}

			// Clear Window :D*
			SDL_RenderClear(window.getRenderer());
			
			// Render PLayer Sprite :D*
			player.render(window.getRenderer());

			// Update the Window after the Sprite is rendered :D*
			SDL_RenderPresent(window.getRenderer());

		}
	}

	return true;
}

void Engine::stop()
{
	// Freeup Stuff when the 
	// The Engine is no longer
	// Running :D*
	window.cleanup();
	texture.cleanup();
	player.cleanup();
}