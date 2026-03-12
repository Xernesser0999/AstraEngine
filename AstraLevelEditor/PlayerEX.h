#pragma once
#include "Pawn.h"

class PlayerEX : public Pawn {
public:
	PlayerEX
	(
		sf::RenderWindow& window,
		int hp_,
		float posX_,
		float posY_,
		float sizeX_,
		float sizeY_,
		float power_jump_,
		float speed_,
		std::string image,
		float Iframe,
		StateMachine& state_
	);
	
	void update(float dt, const std::vector<Collider*>& colliders) override;
	void death() override;

protected:
	//void onStateChange(State from, State to) override;	
	//void updateState();									
};