#include "shooter.h"

Shooter::Shooter(float posX, float posY, float speedMove, char _direction)
{
	pos = { posX, posY };
	size = { 50, 50 };
	direction = _direction;
	speed = speedMove;

	rect.setPosition(pos);
	rect.setSize(size);
	if (!texture.loadFromFile("sprite/Debug/Trigger_DebugTX.png"))
	{
		rect.setFillColor(sf::Color::Red);
	}
	else
	{
		rect.setTexture(&texture);
	}
}
Shooter::~Shooter() {}

void Shooter::update(float dt, float _timeShoot)
{

}
void Shooter::render(sf::RenderWindow& window)
{
	window.draw(rect);
}