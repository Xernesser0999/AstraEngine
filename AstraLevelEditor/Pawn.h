// STRUCT - PAWN
// Permet de crée un objet capable de recevoir des input. Une camera peut etre lié a cette objet.

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Collider.h"

class Camera;

struct Pawn {
	//  |\=-_
	//  VARIABLE
	int hp;							// Player health
	int maxhp;						// Player MaxHP

	sf::Vector2f pos;
	sf::Vector2f size;

	float power_jump;				// Jump Height
	float speed;					// Speed of the player

	float Iframe;					// Iframe (in second)
	float IframeTimer;				// Actual Iframe acting as a timer

	float velocityY = 0;			// Vertical Velocity
	float velocityX = 0;			// Horizontal Velocity

	float PawnCenterX;				// Center of the player rectangle used for fliping the sprite
	float ColliderCenterX;

	int direction;					// Direction of the player

	//  |\=-_
	//  STATE MACHINE
	// a optimiser
	bool isGrounded = true;
	bool isInvincible = false;
	bool isalive = true;

	//  |\=-_
	//  SDL VARIABLE
	// SDL_FlipMode flip = SDL_FLIP_NONE;
	sf::RectangleShape rect;
	sf::Texture texture;

	//  |\=-_
	//  FUNCTION
	Pawn(sf::RenderWindow& window, int hp_, float posX_, float posY_, float sizeX_, float sizeY_, float power_jump_, float speed_, std::string image, float Iframe_);
	virtual ~Pawn();

	virtual void update(float dt, const std::vector<Collider*>& colliders);		// Update		// Can be Override
	void render(sf::RenderWindow& window, Camera* camera = nullptr);			// Render

	void collisionVert(const std::vector<Collider*>& colliders);				// Vertical Collision
	void collisionHori(const std::vector<Collider*>& colliders);				// Horizontal Collision
	bool intersects(const sf::FloatRect& a, const sf::FloatRect& b);

	virtual void takedamage(int dmg);											// Takedamage	// Can be Override
	virtual void death();														// Death		// Can be Override
};
