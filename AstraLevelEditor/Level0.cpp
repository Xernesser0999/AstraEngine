#include "Level0.h"
#include "Global.h"

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
		1000,
		700,
		"sprite/Debug/PlaceHolder.png",
		1,
		*Machine
	);

	if (glob.Boot) {
		glob.Boot = false;
		player->pos = { 250, 700 };
	}
	else {
		player->pos = glob.pos;
	}

	parralax = new BG_parralax_Full();
	parralax->addlayer("sprite/Background/Debugmap.png", 0.5);

	trig1 = new Trigger(
		1475,
		350,
		50,
		150,
		true
	);
	trig2 = new Trigger(
		475,
		650,
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
	delete trig1;
	delete trig2;

	loader = nullptr;
	cam = nullptr;
	player = nullptr;
	parralax = nullptr;
	trig1 = nullptr;
	trig2 = nullptr;
}

void Level0::update(const bool* keys, float dt) {
	loader->update(dt, *player);
	player->update(dt, loader->colliders);
	cam->Update(*player);
	parralax->update(dt, *cam);
	trig1->update(dt, *player);
	trig2->update(dt, *player);
}

void Level0::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	trig1->render(window, *cam);
	trig2->render(window, *cam);
}

void Level0::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (trig1->trigger) {
		glob.pos = { 150,2700 };
		currentScene = SceneState::Map2;
	}
	if (trig2->trigger) {
		glob.pos = { 500,700 };
		currentScene = SceneState::Map3;
	}
}