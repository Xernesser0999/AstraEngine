#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Camera;

class PS_burst
{
	std::vector<sf::RectangleShape> Particle;

	sf::Vector2f size;

	PS_burst(sf::RenderWindow& window, std::string file, float size);
	~PS_burst();

	void update(float dt);
	void render(sf::RenderWindow& window, Camera& camera);
};

