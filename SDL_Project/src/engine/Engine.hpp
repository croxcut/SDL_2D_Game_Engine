#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include "graphics/Window.hpp"
#include "graphics/Scene/Texture.hpp"
#include "entity/player/Player.hpp"
#include "utils/InputHandler.hpp"

class Engine {

	private:
		InputHandler input;
		Texture texture;
		Window window;
		Player player;
		

	public:
		bool start();
		void stop();

};

#endif // !ENGINE_HPP
