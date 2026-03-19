#include "projectiles.h"
#include "shooter.h"
#include "Pawn.h"

Projectile::Projectile(const Shooter& _shooter)
{
	spawn(_shooter);
}

Projectile::~Projectile() {}

void Projectile::spawn(const Shooter& _shooter)
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

	isAlive = true;
	lifeTime = 0.0f;
}

bool Projectile::Intersect(Pawn& p)
{
	return p.pos.x < pos.x + size.x &&
		p.pos.x + p.size.x > pos.x &&
		p.pos.y < pos.y + size.y &&
		p.pos.y + p.size.y > pos.y;
}


void Projectile::update(float dt, Pawn& pawn, float _lifetime)
{

	if (isAlive)
	{
		if (_lifetime > 0.0f && lifeTime <= 0.0f)
		{
			lifeTime = _lifetime;
		}
		if (lifeTime > 0.0f)
		{
			lifeTime -= dt;
			if (lifeTime <= 0.0f)
			{
				isAlive = false;
			}
		}
	}

	// movement
	if (direction == 'l')
	{
		pos.x -= speed * dt;
	}
	else if (direction == 'r')
	{
		pos.x += speed * dt;
	}
	rect.setPosition(pos);

	if (Intersect(pawn))
	{
		pawn.takedamage(1);
		isAlive = false;
	}
}

void Projectile::render(sf::RenderWindow& window)
{

	if (isAlive)
	{
		window.draw(rect);
	}
}