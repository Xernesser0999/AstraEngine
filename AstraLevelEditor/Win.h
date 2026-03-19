#pragma once
#include <SFML/Graphics.hpp>

class Win
{
public:
	sf::RectangleShape rect;
	sf::Texture TX;
	
	Win();
	~Win();

	void render(sf::RenderWindow& window);
};

