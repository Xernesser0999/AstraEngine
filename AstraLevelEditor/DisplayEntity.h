#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Camera;

class DisplayEntity {
public:
	sf::Vector2f pos;
	sf::Vector2f size;

	sf::RectangleShape rect;
	sf::Texture texture;

	DisplayEntity(sf::RenderWindow& window, float posX_, float posY_, float sizeX_, float sizeY_, std::string image);
	~DisplayEntity();

	void update(float dt);
	void render(sf::RenderWindow& window, Camera& camera);
};
