#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Entity.hpp"
#include "../../../engine/graphics/Scene/Texture.hpp"

class Player : public Entity {

	private:
		Texture texture;
		SDL_Texture* image;

	public:
		// Constructor/destructor for player class :D*
		Player();
		~Player();

		// Forward declarations :D*
		void render(SDL_Renderer* renderer);
		void cleanup();

};

#endif // !PLAYER_HPP
