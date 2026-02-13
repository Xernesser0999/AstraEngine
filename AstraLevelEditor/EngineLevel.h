#pragma once
#include "Scene.h"

#include "Collider.h"
#include "Camera.h"
#include "PlayerEX.h"

class EngineLevel : public Scene {
public:

	EngineLevel(sf::RenderWindow& window);
	~EngineLevel();

	void displayScene(sf::RenderWindow& window) override;
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:

	PlayerEX* player;
	Camera* cam;
	std::vector<Collider*> Colliderlist;
};
