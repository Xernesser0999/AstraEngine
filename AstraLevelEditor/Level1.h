#pragma once
#include "Scene.h"
#include "projectiles.h"
#include "shooter.h"
#include "LevelLoader.h"
#include "Collider.h"
#include "Camera.h"
#include "PlayerEX.h"
#include "Trigger.h"
#include "BG_parralax_Full.h"
#include "SavePoint.h"
#include "BlobEnemy.h"
#include "FlottingElement.h"

class Global;

class Level1 : public Scene {
public:

	Level1(sf::RenderWindow& window, Global& var_);
	~Level1();

	void displayScene(sf::RenderWindow& window) override;
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:

	StateMachine* Machine;
	Trigger* trig;
	LevelLoader* loader;
	PlayerEX* player;
	Camera* cam;
	std::vector<Collider*> Colliderlist;
	BG_parralax_Full* parralax;
	SavePoint* point;

	BlobEnemy* lvl2Blob1;
	BlobEnemy* lvl2Blob2;

	FlottingElement* flot;

	Shooter* lvl2Shooter1;
	Shooter* lvl2Shooter2;
	Shooter* lvl2ShooterN3;
	Shooter* lvl2ShooterN4;
	Shooter* lvl2ShooterN5;
	Projectile* lvl2Projectile1;
	Projectile* lvl2Projectile2;
	Projectile* lvl2ProjectileN3;
	Projectile* lvl2ProjectileN4;
	Projectile* lvl2ProjectileN5;
	Global& glob;
};
