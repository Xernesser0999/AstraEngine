#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Camera;

class PS_particle
{
public:
	sf::Vector2f size;
	sf::Vector2f pos;

	sf::RectangleShape rect;
	sf::Texture TX;

	float angle;
	float lifetime;
	float speed;

public:

	PS_particle(float size_, float angle_, float lifetime_, float speed_, float posX_, float posY, std::string file);
	~PS_particle();

	void update(float dt);
	void render(sf::RenderWindow& window, Camera& camera);
	bool isalive() const;
};

