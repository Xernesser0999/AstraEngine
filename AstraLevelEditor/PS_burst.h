#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <ctime>

#include "PS_particle.h"
class Camera;

class PS_burst
{
public:
	sf::Vector2f pos;
	std::string file;

	float size;
	float lifetime;
	float speed;
	float firerate;
	int quantity;

	std::vector<PS_particle> Particle;

	float currentTime = 0;
	float lastShotTime = 0;
	float shotCooldown;

	sf::Clock clock;

public:
	PS_burst(std::string file_, float size_, float posX, float posY, int quantity_, float fireRate_, float speed_);
	~PS_burst();

	void update(float dt);
	void render(sf::RenderWindow& window, Camera& camera);
};

