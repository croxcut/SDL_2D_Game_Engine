#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <SDL.h>

class InputHandler {

	public:
		SDL_Event e;
		bool moveUp, moveDown, moveLeft, moveRight;
	
	public:
		// Forward declarations :D*
		void pressed(SDL_Event e);
		void unpressed();
};

#endif // !INPUTHANDLER_HPP
