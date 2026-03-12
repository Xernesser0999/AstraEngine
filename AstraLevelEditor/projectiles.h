#pragma once
#include <Sfml/Graphics.hpp>
#include <vector>

class Projectile
{
public:
	Projectile(float posX, float posY, float speedMove, char _direction);
	~Projectile();
	void update(float dt);
	void render(sf::RenderWindow& window);

	sf::Vector2f pos;
	sf::Vector2f size;
	std::vector<Projectile*> projectiles;
	sf::RectangleShape rect;
	sf::Texture texture;
	sf::Clock clock;
	char direction;			//bottom, left, right
	bool isAlive = true;
	float lifeTime = 15.0f;
	float speed;

};