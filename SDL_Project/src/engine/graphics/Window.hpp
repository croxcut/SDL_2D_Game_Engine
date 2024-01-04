#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Window {

	public:
		// Window Constructor and destructor :D*
		Window();
		~Window();

		// Forward declarations :D*
		bool init();
		void cleanup();
		SDL_Renderer* getRenderer();
		SDL_Window* getWindow();

	private:	
		SDL_Window* window;				// Window We're gonna render into :D*
		SDL_Renderer* renderer;			// This handles the overall rendering :D*
	
		const int SCREEN_HEIGHT{ 600 };							// Screen Height :D*
		const int SCREEN_WIDTH{ SCREEN_HEIGHT * 16 / 10 };		// Screen Width ( sets up the size to 16/10 ratio :D* )
		std::string TITLE = "Just A windpw";


		/*
	The if statement is important here :D*
	if this is absent there's gonna be a
	memory leak :D* it leaks around(350+mb per second :D*)
*/
//if (image == nullptr) 

};

#endif // !WINDOW_HPP
