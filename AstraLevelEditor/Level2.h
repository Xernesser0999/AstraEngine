#pragma once
#include "Scene.h"

#include <SFML/Audio.hpp>

#include "LevelLoader.h"
#include "Collider.h"
#include "Camera.h"
#include "PlayerEX.h"
#include "Trigger.h"
#include "BG_parralax_Full.h"
#include "BlobEnemy.h"
#include "FlottingElement.h"
#include "Hud.h"

#include "StateMachine.h"

class Global;

class Level2 : public Scene {
public:

	Level2(sf::RenderWindow& window, Global& var_);
	~Level2();

	void displayScene(sf::RenderWindow& window) override;
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:

	sf::Music music;

	StateMachine* Machine;
	Trigger* trig;
	LevelLoader* loader;
	PlayerEX* player;
	Camera* cam;
	std::vector<Collider*> Colliderlist;
	BG_parralax_Full* parralax;
	BlobEnemy* blob1;
	BlobEnemy* blob3;
	BlobEnemy* blob4;
	BlobEnemy* blob5;
	BlobEnemy* blob6;

	FlottingElement* flot1;
	FlottingElement* flot2;
	FlottingElement* flot3;

	Hud* hud;

	Global& glob;
};
