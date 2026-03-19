#pragma once
#include <SFML/Graphics.hpp>

#include "Trigger.h"

class Pawn;
class Global;

class SavePoint
{
public:
	sf::RectangleShape rect;
	sf::Texture TX;
	sf::Vector2f RezPos;

	Trigger* trig;

	int actual;

public:
	SavePoint(float posX, float posY, int actualLevel);
	~SavePoint();

	void update(float dt, Pawn& pawn, Global& glob);
	void render(sf::RenderWindow& window);
};

