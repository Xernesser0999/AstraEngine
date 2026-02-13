#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include <string>

class GUI_button {
public:
	bool hover;
	sf::Vector2f pos;
	sf::Vector2f size;

	sf::Texture* TX;
	sf::Texture* TX2;

	sf::RectangleShape* rectangle;

public:

	GUI_button(float posX_, float posY_, float sizeX, float sizeY, std::string file, std::string hover);
	~GUI_button();

	void render(sf::RenderWindow& window);

	bool hovered(sf::RenderWindow& window);
	bool clicked(sf::RenderWindow& window);
};
