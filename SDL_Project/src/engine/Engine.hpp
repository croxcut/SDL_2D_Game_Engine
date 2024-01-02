#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "graphics/Window.hpp"
#include "utils/AssetLoader.hpp"

class Engine
{
private:
	// Private Object Instances :D*
	Window window;
	AssetLoader asset;
public:
	// Forward Declarations :D*
	bool run();
	void stop();

};

#endif 
