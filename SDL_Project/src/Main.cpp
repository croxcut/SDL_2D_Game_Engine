#include <iostream>
#include "engine/Engine.hpp"
/*
	Welcome :D*

	( I Would recommend you to use
	VISUAL STUDIO :D* )
	If you're gonna run this thing
	Just Link the Include folder and
	libraries on the propperties tab

	If you want to load different image
	to your liking just go to the
	AssetLoader.cpp and find the loadImage
	Method and place the correct filepath
	to it :D*

	If you want to change the Window Size
	just head to the Utils.hpp and change
	the constant values of SCREEN_WIDTH
	and SCREEN_HEIGHT to your liking :D*

	I wanna say that this engine is not
	complete yet and the code need some
	refactoring( because some implementations
	i did is pretty sketch at best :D* )
	so if you want to add refactor the
	code you're free to do so :D*

	- John Paul Valenzuela -
	-    January 3 2024    -
*/

int main(int argc, char** argv)
{

	Engine engine;

	// Run Engine! :D*
	if (!engine.start())
	{
		std::cout << "Failed to run the engine! " << std::endl;
	}
	
	// Freeup Stuff :D*
	engine.stop();

	return 0;
}