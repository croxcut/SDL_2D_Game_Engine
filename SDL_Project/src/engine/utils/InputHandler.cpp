#include "InputHandler.hpp"

void InputHandler::pressed(SDL_Event e)
{	
	// This checks for keypresses (arrow keys)
	if (e.key.keysym.sym == SDLK_UP) moveUp = true;
	if (e.key.keysym.sym == SDLK_DOWN) moveDown = true;
	if (e.key.keysym.sym == SDLK_LEFT) moveLeft = true;
	if (e.key.keysym.sym == SDLK_RIGHT) moveRight = true;
}

void InputHandler::unpressed()
{
	// release Key 
	moveUp = moveDown = moveLeft = moveRight = false;
}