#pragma once
#include <SFML/Graphics.hpp>

#include <string>

class BGstatic {
public:
	sf::RectangleShape rect;
	sf::Texture texture;

	sf::Vector2f size;

	BGstatic(sf::RenderWindow& window, std::string file, float sizeX, float sizeY);
	~BGstatic();

	void render(sf::RenderWindow& window);
};
