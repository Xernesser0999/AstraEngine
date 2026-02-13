#include "PlayerEX.h"

PlayerEX::PlayerEX(
	sf::RenderWindow& window,
	int hp_,
	float posX_,
	float posY_,
	float sizeX_,
	float sizeY_,
	float power_jump_,
	float speed_,
	std::string image,
	float Iframe_
)
	: Pawn(
		window,
		hp_,
		posX_,
		posY_,
		sizeX_,
		sizeY_,
		power_jump_,
		speed_,
		image,
		Iframe_
	) 
{}

//void PlayerEX::onStateChange(State from, State to) {
//	if (to == IDLE) {
//		SDL_Log("Player IDLE");
//	}
//	else if (to == RUNNING) {
//		SDL_Log("Player RUNNING");
//	}
//	else if (to == INAIR) {
//		SDL_Log("Player IN AIR");
//	}
//}

//void PlayerEX::updateState() {
//	if (!isGrounded) {
//		if (!isState(INAIR)) {			// If not on ground
//			setState(INAIR);
//		}
//	}
//	else {
//		if (velocityX != 0) {			// If we move
//			if (!isState(RUNNING)) {
//				setState(RUNNING);
//			}
//		}
//		else {
//			if (!isState(IDLE)) {		// If we dont move
//				setState(IDLE);
//			}
//		}
//	}
//}

void PlayerEX::update(float dt, const std::vector<Collider*>& colliders) {
	velocityX = 0;                                  // Don't move if no action

	//  |\=-_
	//  HORIZONTAL MOVEMENT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {                  // Arrow Left
		velocityX = -speed;                         // Set the velocity
		direction = 1;                              // Set the direction to left
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {                 // Arrow Right
		velocityX = speed;                          // Set the velocity
		direction = 0;                              // Set the direction to right
	}

	pos.x += velocityX * dt;                       // Apply the movement
	Pawn::collisionHori(colliders);                 // Check for collision

	//  |\=-_
	//  VERTICAL MOVEMENT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && isGrounded) {   // Spacebar (only work if the player on ground)
		velocityY = -power_jump;                    // Set the velocity
		isGrounded = false;                         // Player not on ground anymore
	}

	velocityY += 2000.0f * dt;                      // Gravity
	pos.y += velocityY * dt;                       // Apply the vertical movement
	Pawn::collisionVert(colliders);                 // Check for collision

	rect.setPosition({ pos.x, pos.y });

	//  |\=-_
	//  STATE MACHINE
	//updateState();                                  // State update

	//  |\=-_
	//  IFRAME
	if (isInvincible) {
		IframeTimer -= dt;                          // Timer
		if (IframeTimer <= 0.0f) {                  // When timer hit 0
			isInvincible = false;                   // Disable invincibility
			IframeTimer = 0.0f;                     // Reset Iframe
		}
	}

	//  |\=-_
	//  DEATH
	if (!isalive) {
		death();
	}
}

void PlayerEX::death() {
	rect.setPosition({ 200, 800 });
	hp = 1;                                 // Set hp
	isalive = true;                         // Make the player alive again
	//setState(IDLE);                         // Remettre l'�tat � IDLE
}