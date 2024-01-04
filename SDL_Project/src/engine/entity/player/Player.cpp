#include "Player.hpp"

Player::Player()
{
	// Initialize image :D*
	image = nullptr;
}

Player::~Player()
{
	// Freeup stuff if out of scope :D*
	cleanup();
}

void Player::render(SDL_Renderer* renderer)
{

	if (image == nullptr) image = texture.loadTexture("res/images/sample.png", renderer);
	
	// Render pingu :D*
	texture.render(x, y, 100, 100, image, renderer);
}

void Player::cleanup()
{
	// Freeup stuff :D*
	SDL_DestroyTexture(image);
	image = nullptr;

	SDL_Quit();
	IMG_Quit();
}