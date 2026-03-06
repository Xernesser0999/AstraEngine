#pragma once
#include "Scene.h"

#include "LevelLoader.h"
#include "Collider.h"
#include "Camera.h"
#include "PlayerEX.h"
#include "Trigger.h"
#include "BG_parralax_Full.h"

class EngineLevel : public Scene {
public:

	EngineLevel(sf::RenderWindow& window);
	~EngineLevel();

	void displayScene(sf::RenderWindow& window) override;
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:

	Trigger* trig;
	LevelLoader* loader;
	PlayerEX* player;
	Camera* cam;
	std::vector<Collider*> Colliderlist;
	// BGparralaxAuto* parralax;
	BG_parralax_Full* parralax;
};
