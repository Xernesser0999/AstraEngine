#include "BlobEnemy.h"

BlobEnemy::BlobEnemy(float posX, float posY, float timeMove, float speedMove)
{
	pos = { posX, posY };
	size = { 50, 50 };
	speed = speedMove;
	time = timeMove;
	rect.setPosition(pos);
	rect.setSize(size);
	if (!texture.loadFromFile("sprite/Debug/PlaceHolder.png"))
	{
		rect.setFillColor(sf::Color::Red);
	}
	else {
		rect.setTexture(&texture);
	}

}

BlobEnemy::~BlobEnemy() {}

void BlobEnemy::update(float dt)
{
	actualTimeMove += dt;

	if (moveRight) {
		pos.x += speed * dt;
	}
	else {
		pos.x -= speed * dt;
	}

	if (actualTimeMove >= time) {
		moveRight = !moveRight;
		actualTimeMove = 0;
	}
	rect.setPosition(pos);
}

void BlobEnemy::render(sf::RenderWindow& window) {
	window.draw(rect);
}
