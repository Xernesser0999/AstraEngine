#pragma once
#include <SFML/Graphics.hpp>

#include <string>

class Camera;

class BGstatic {
public:
	sf::RectangleShape rect;
	sf::Texture texture;

	sf::Vector2f size;

	BGstatic(sf::RenderWindow& window, std::string file, float sizeX, float sizeY);
	~BGstatic();

	void render(sf::RenderWindow& window);
	void renderCam(sf::RenderWindow& window, Camera& camera);
};
