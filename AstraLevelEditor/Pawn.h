#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Collider.h"
#include "StateMachine.h"

class Camera;

struct Pawn {
	int hp;							
	int maxhp;						

	sf::Vector2f pos;
	sf::Vector2f size;

	sf::Vector2f Rez;

	float power_jump;				 
	float speed;					

	float dashDuration = 0.2f; 		     
	float cooldownDuration = 0.5f;		
	float cooldownTimer = 0.0f;		    
	float dashTimer = 0.2f;			 


	float Iframe;					
	float IframeTimer;				

	float velocityY = 0;			
	float velocityX = 0;			

	float PawnCenterX;				
	float ColliderCenterX;

	int direction;				

	bool isGrounded = true;
	bool isInvincible = false;
	bool isalive = true;

	StateMachine& state;

	bool isJumping;
	bool isDoubleJumping = false;
	bool isInpuConsume = false;

	float Gravity = 4000.0f;

	bool canDB;
	bool canFloat;
	sf::RectangleShape rect;
	sf::Texture texture;

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