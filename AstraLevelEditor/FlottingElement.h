#pragma once
#include <Sfml/Graphics.hpp>

class Pawn;
class FlottingElement
{
public:
	sf::Vector2f pos;
	sf::Vector2f size;

	sf::RectangleShape rect;
	sf::Texture texture;

	sf::RectangleShape rectangle;

	float time;
	bool moveHeight = true;
	float actualTimeMove = 0;
	float speed;

	FlottingElement() = default;
	FlottingElement(sf::RenderWindow& window, float posX_, float posY_, float sizeX_, float sizeY_, float timeMove, float speedMove, std::string image);
	~FlottingElement();

	void draw(sf::RenderWindow& window);
	bool intersept(Pawn& p);
	void update(Pawn& pawn, float dt);
};

