#pragma once
#include <Sfml/Graphics.hpp>
#include "projectiles.h"

class Shooter {
public:
	Shooter(float posX, float posY, float speedMove, char _direction);
	~Shooter();
	void update(float dt, float _timeShoot, Projectile* _projectile);
	void render(sf::RenderWindow& window);

	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape rect;
	sf::Texture texture;

	char direction;		//left,right
	float speed = 200.0f;
	Projectile* projectile = nullptr;
	float shootTimer = 0.0f;          // time since last shot
	float shootInterval = 2.0f;
};