#pragma once
#include <Sfml/Graphics.hpp>
#include "TXanimated.h"

class Pawn;
class BlobEnemy{
public:
	BlobEnemy(float posX, float posY, float SizeX, float SizeY, float timeMove, float speedMove);
	~BlobEnemy();

	void update(float dt, Pawn& p);
	void render(sf::RenderWindow& window);
	bool Intersect(Pawn& p);

	sf::Vector2f pos;
	sf::Vector2f size;

	TXanimated* rect;

	sf::Texture texture;

	float time;
	bool moveRight = true;
	float actualTimeMove = 0;
	float speed;
};

