#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

class Camera;
class Pawn;

class Trigger
{
public:

	sf::RectangleShape rect;
	sf::Vector2f size;
	sf::Vector2f pos;
	sf::Texture TX;

	bool active = false;
	bool trigger = false;
	bool inside = false;

public :
	Trigger(float posX, float posY, float sizeX, float sizeY, bool active_);
	~Trigger();

	bool Intersect(Pawn& p);
	void update(float dt, Pawn& p);
	void render(sf::RenderWindow& window);
};

