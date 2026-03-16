#include "projectiles.h"
#include "shooter.h"

Projectile::Projectile(const Shooter& _shooter)
{

	direction = _shooter.direction;
	speed = _shooter.speed;
	pos = _shooter.pos;
	size = { 40, 40 };
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

void Projectile::update(float dt, const Shooter& _shooter)
{
	lifeTime -= dt;
	if (lifeTime <= 0)
	{
		lifeTime = 5.0f;
		pos = _shooter.pos;
	}
	else
	{

		{
			if (direction == 'l')
			{
				pos.x -= speed * dt;
				rect.setPosition(pos);
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