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
#include "Pnj.h"

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

	Shooter* lvl2ShooterN1;
	Shooter* lvl2ShooterN2;
	Shooter* lvl2ShooterN3;
	Shooter* lvl2ShooterN4;
	Shooter* lvl2ShooterN5;
	Projectile* lvl2ProjectileN1;
	Projectile* lvl2ProjectileN2;
	Projectile* lvl2ProjectileN3;
	Projectile* lvl2ProjectileN4;
	Projectile* lvl2ProjectileN5;

	SavePoint* point;
	SavePoint* point1;
	SavePoint* point2;

	Pnj* pnjJump;
	Pnj* pnjFloat;

	Global& glob;
};
