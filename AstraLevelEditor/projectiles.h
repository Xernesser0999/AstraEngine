#pragma once
#include <Sfml/Graphics.hpp>

class Shooter;
class Pawn;

class Projectile
{
public:
	Projectile() = default;
	Projectile(const Shooter& _shooter);
	~Projectile();

	void update(float dt, const Shooter& _shooter);
	void render(sf::RenderWindow& window);

	// initialize or (re)spawn the projectile
	void spawn(const Shooter& _shooter);

	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Texture texture;
	sf::Clock clock;
	bool Intersect(Pawn& p);
	char direction = 'l';	// left,right
	bool isAlive = false;
	float lifeTime = 0.0f;
	float maxLife = 5.0f;
	float speed = 0.0f;
};