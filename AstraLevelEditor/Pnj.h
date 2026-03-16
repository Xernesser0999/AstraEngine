#pragma once
#include "Trigger.h"
#include "Camera.h"
#include <iostream>

class Pnj {
public: 
	sf::Vector2f pos;
	sf::Vector2f size;
	Trigger* trig;
	sf::RectangleShape rect;
	sf::Texture texture;

	Pnj(float posX, float posY, float sizeX, float sizeY, std::string image);
	~Pnj();
	void updatePnj(float dt);
	void renderPnj(sf::RenderWindow& window);
};

