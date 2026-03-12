#pragma once
#include <Sfml/Graphics.hpp>
class Shooter
{
	public:
	Shooter(float posX, float posY, float timeShoot);
	~Shooter();
	void update(float dt);
	void render(sf::RenderWindow& window);
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Texture texture;
	sf::Clock clock;
	float time;
};

