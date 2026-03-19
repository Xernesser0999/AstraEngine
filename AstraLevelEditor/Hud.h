#pragma once
#include <SFML/Graphics.hpp>

class Pawn;
class Global;

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
	void draw(sf::RenderWindow& window, Pawn& pawn);
};

class DashCapa {
public:
	sf::RectangleShape capacity;
	sf::Vector2f posCapacity;
	sf::Vector2f sizeCapacity;

	DashCapa();
	~DashCapa();
	void update();
	void draw(sf::RenderWindow& window, Global& glob);
};

class DbCapa {
public:
	sf::RectangleShape capacity;
	sf::Vector2f posCapacity;
	sf::Vector2f sizeCapacity;

	DbCapa();
	~DbCapa();
	void update();
	void draw(sf::RenderWindow& window, Global& glob);
};

class FloatingCapa {
public:
	sf::RectangleShape capacity;
	sf::Vector2f posCapacity;
	sf::Vector2f sizeCapacity;

	FloatingCapa();
	~FloatingCapa();
	void update();
	void draw(sf::RenderWindow& window, Global& glob);
};

class Hud{
public:
	Life* life;
	DashCapa* dash;
	DbCapa* db;
	FloatingCapa* floating;

	Hud();
	~Hud();
	void draw(sf::RenderWindow& window, Pawn& pawn, Global& glob);
};



