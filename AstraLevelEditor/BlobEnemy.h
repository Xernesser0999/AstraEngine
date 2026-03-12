#pragma once
#include <Sfml/Graphics.hpp>

class BlobEnemy{
public:
	BlobEnemy(float posX, float posY, float timeMove, float speedMove);
	~BlobEnemy();
	void update(float dt);
	void render(sf::RenderWindow& window);

	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Texture texture;
	sf::Clock clock;
	float time;
	bool moveRight = true;
	float actualTimeMove = 0;
	float speed;
};

