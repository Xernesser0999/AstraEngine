#pragma once
#include <SFML/Graphics.hpp>

class Camera;

struct StateStruct
{
public:
public:
	StateStruct();
	virtual ~StateStruct();

	virtual void Update(float dt);
	virtual void Render(sf::RenderWindow& window, Camera* camera = nullptr);
};

