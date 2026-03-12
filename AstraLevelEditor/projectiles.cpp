#include "projectiles.h"

Projectile::Projectile(float posX, float posY, float speedMove, char _direction)
{
	pos = { posX, posY };
	size = { 50, 50 };
	speed = speedMove;
	rect.setPosition(pos);
	rect.setSize(size);
	if (!texture.loadFromFile("sprite/Debug/PlaceHolder.png"))
	{
		rect.setFillColor(sf::Color::Red);
	}
	else
	{
		rect.setTexture(&texture);
	}

}

Projectile::~Projectile() {}

void Projectile::update(float dt)
{
	lifeTime -= dt;
	if (lifeTime <= 0)
	{
		isAlive = false;
	}
	else
	{
		while (isAlive)
		{
			rect.setPosition(pos);
			if (direction == 'b')
			{
				pos.y += speed * dt;
			}
			else if (direction == 'l')
			{
				pos.x -= speed * dt;
			}
			else if (direction == 'r')
			{
				pos.x += speed * dt;
			}
		}
	}

}
void Projectile::render(sf::RenderWindow& window)
{
	window.draw(rect);
}