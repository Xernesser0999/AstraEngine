#include "Level0.h"
#include "Global.h"
#include "shooter.h"
#include "projectiles.h"

Level0::Level0(sf::RenderWindow& window, Global& var_) : glob(var_) {
	loader = new LevelLoader();
	loader->load(
		"level/LVL1.txt",
		"level/LVL1.png",
		window,
		76,
		60
	);

	cam = new Camera(
		1920,
		1080,
		76 * 50,
		60 * 50,
		0.005
	);
	Machine = new StateMachine(new IdleState());

	// Player
	player = new PlayerEX(
		window,
		1,
		0,
		0,
		50,
		50,
		1400,
		700,
		"sprite/Debug/PlaceHolder.png",
		1,
		*Machine
	);

	blob = new BlobEnemy(1250, 1750, 1.85, 300);
	blob1 = new BlobEnemy(1600, 550, 1.50, 250);
	blob2 = new BlobEnemy(3125, 950, 1.50, 150);
	shooter1 = new Shooter(750, 2600, 1.5f, 'l');
	projectile1 = new Projectile(*shooter1);

	spike = new Spike(
		window,
		200,
		2500,
		200,
		200,
		"sprite/Environment/Spike.png"
	);

	if (glob.Boot)
	{
		glob.Boot = false;
		player->pos = { 100, 2000 };
	}
	else
	{
		player->pos = glob.pos;
	}

	parralax = new BG_parralax_Full();
	parralax->addlayer("sprite/Background/Debugmap.png", 0.5);

	trig = new Trigger(
		1475,
		350,
		50,
		150,
		true
	);
}

Level0::~Level0() {
	Colliderlist.clear();
	delete loader;
	delete cam;
	delete player;
	delete parralax;
	delete trig;
	delete blob;
	delete blob1;
	delete blob2;
	delete shooter1;
	delete projectile1;

	loader = nullptr;
	cam = nullptr;
	player = nullptr;
	parralax = nullptr;
	trig = nullptr;
	blob = nullptr;
	blob1 = nullptr;
	blob2 = nullptr;
	shooter1 = nullptr;
	projectile1 = nullptr;
}

void Level0::update(const bool* keys, float dt) {

	loader->update(dt, *player);
	player->update(dt, loader->colliders);
	cam->Update(*player);
	parralax->update(dt, *cam);
	trig->update(dt, *player);
	blob->update(dt);
	blob1->update(dt);
	blob2->update(dt);
	spike->update(*player);
	projectile1->update(dt, *shooter1);

}

void Level0::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	trig->render(window, *cam);
	blob->render(window);
	blob1->render(window);
	blob2->render(window);
	spike->draw(window);
	shooter1->render(window);
	projectile1->render(window);
}

void Level0::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (trig->trigger) {
		glob.pos = { 50, 450 };
		currentScene = SceneState::Map2;
	}
}