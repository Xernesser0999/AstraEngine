#pragma once
#include "Trigger.h"
#include "Camera.h"
#include "Pawn.h"
#include <iostream>
class Pawn;
class Global;

class Pnj {
public: 
	sf::Vector2f pos;
	sf::Vector2f size;
	Trigger* trig;
	sf::RectangleShape rect;
	sf::Texture texture;
	bool capacityGiven = false ;

	Pnj(float posX, float posY, float sizeX, float sizeY, std::string image);
	~Pnj();
	void updatePnj(float dt, Pawn& pawn, int z, int a, Global& glob);
	void renderPnj(sf::RenderWindow& window);
};

