#pragma once
#include "Trigger.h"
#include "Camera.h"
#include <iostream>
class Pawn;

class Pnj {
public: 
	sf::Vector2f pos;
	sf::Vector2f size;
	Trigger* trig;
	sf::RectangleShape rect;
	sf::Texture texture;
	Pawn* pawn;

	Pnj(float posX, float posY, float sizeX, float sizeY, std::string image);
	~Pnj();
	void updatePnj(float dt, Pawn& pawn);
	void renderPnj(sf::RenderWindow& window);
};

