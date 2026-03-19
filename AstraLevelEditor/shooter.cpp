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

void Shooter::update(float dt, float _timeShoot, Projectile* _projectile)
{
	projectile = _projectile;
	shootTimer += dt;
	float interval = (_timeShoot > 0.0f) ? _timeShoot : shootInterval;//kind of useless imo but pretty so I keep it

	if (shootTimer >= interval)
	{
		if (projectile)
		{
			projectile->spawn(*this);// (re)spawn the projectile
		}
		shootTimer = 0.0f;
	}
}
void Shooter::render(sf::RenderWindow& window)
{
	window.draw(rect);
}