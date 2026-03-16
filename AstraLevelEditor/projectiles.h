#pragma once
#include <Sfml/Graphics.hpp>
//#include <vector>

// Forward declaration
class Shooter;

class Projectile
{
public:
	Projectile(const Shooter& _shooter);
	~Projectile();
	void update(float dt, const Shooter& _shooter);
	void render(sf::RenderWindow& window);
	sf::Vector2f pos;
	sf::Vector2f size;

	//std::vector<Projectile> projectiles;

	sf::RectangleShape rect;
	sf::Texture texture;
	sf::Clock clock;
	char direction = 'l';				//left,right
	bool isAlive = true;
	float lifeTime = 5.0f;
	float speed;
};