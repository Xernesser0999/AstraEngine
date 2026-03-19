#pragma once
#include "Scene.h"

#include "LevelLoader.h"
#include "Collider.h"
#include "Camera.h"
#include "PlayerEX.h"
#include "Trigger.h"
#include "BG_parralax_Full.h"
#include "BlobEnemy.h"
#include "Spike.h"
#include "FlottingElement.h"
#include "Pnj.h"
#include "projectiles.h"
#include "SavePoint.h"

#include "StateMachine.h"

class Global;

class Level0 : public Scene {
public:

	Level0(sf::RenderWindow& window, Global& var_);
	~Level0();

	void displayScene(sf::RenderWindow& window) override;
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:

	StateMachine* Machine;
	Trigger* trig1;
	Trigger* trig2;
	LevelLoader* loader;
	PlayerEX* player;
	Camera* cam;
	std::vector<Collider*> Colliderlist;
	BG_parralax_Full* parralax;
	Projectile* proj1;
	BlobEnemy* blob;
	BlobEnemy* blob1;
	BlobEnemy* blob2;
	Spike* spike;
	FlottingElement* flot;
	FlottingElement* flot2;
	FlottingElement* flot3;
	FlottingElement* flot4;
	FlottingElement* flot5;
	FlottingElement* flot6;
	FlottingElement* flot7;
	FlottingElement* flot8;
	FlottingElement* flot9;
	Pnj* pnjDoubleJump;

	Shooter* shooter1;
	Projectile* projectile1;

	SavePoint* point;

	Global& glob;
};
