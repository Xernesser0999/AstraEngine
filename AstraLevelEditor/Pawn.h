#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Collider.h"
#include "StateMachine.h"

class Camera;

struct Pawn {
	//  |\=-_
	//  VARIABLE
	int hp;							// Player health
	int maxhp;						// Player MaxHP

	sf::Vector2f pos;
	sf::Vector2f size;

	sf::Vector2f Rez;

	float power_jump;				 // Jump Height
	float speed;					// Speed of the player

	//dash
	float dashDuration = 0.2f; 		      // Duration of the dash
	float cooldownDuration = 0.5f;		 // Time before the dash can be used again
	float cooldownTimer = 0.0f;		    // Timer for the cooldown
	float dashTimer = 0.2f;			   // Timer for the dash duration


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

	StateMachine& state;

	//  |\=-_
	//  DOUBLE SAUT
	bool isJumping;
	bool isDoubleJumping = false;
	bool isInpuConsume = false;

	float Gravity = 4000.0f;

	bool canDB;
	bool canFloat;
	//  |\=-_
	//  SDL VARIABLE
	// SDL_FlipMode flip = SDL_FLIP_NONE;
	sf::RectangleShape rect;
	sf::Texture texture;

	//  |\=-_
	//  FUNCTION
	Pawn(sf::RenderWindow& window, int hp_, float posX_, float posY_, float sizeX_, float sizeY_, float power_jump_, float speed_, std::string image, float Iframe_, StateMachine& state_);
	virtual ~Pawn();

	virtual void update(float dt, const std::vector<Collider*>& colliders);
	void render(sf::RenderWindow& window);

	void collisionVert(const std::vector<Collider*>& colliders);
	void collisionHori(const std::vector<Collider*>& colliders);
	bool intersects(const sf::FloatRect& a, const sf::FloatRect& b);

	virtual void takedamage(int dmg);
	virtual void death();
};