#pragma once
#include <SFML/Graphics.hpp>
class Life {
public:
	sf::RectangleShape heart;
	sf::Vector2f posHeart;
	sf::Vector2f sizeHeart;
	sf::Texture luneBlanche;
	sf::Texture luneGrise;

	Life();
	~Life();
	void update();
	void draw(sf::RenderWindow& window, int nbHeart);
};

class Capacities {
public:
	sf::RectangleShape capacity;
	sf::Vector2f posCapacity;
	sf::Vector2f sizeCapacity;

	Capacities();
	~Capacities();
	void update();
	void draw(sf::RenderWindow& window);
};

class Hud{
public:
	Life* life;
	Capacities* capacities;

	Hud();
	~Hud();
	void draw(sf::RenderWindow& window, int nbHeart);
};



