#include "Level1.h"
#include "Global.h"

Level1::Level1(sf::RenderWindow& window, Global& var_) : glob(var_) {
	// Level loader
	loader = new LevelLoader();
	loader->load(
		"level/TestLevel/lvl2.txt",  // Collision
		"level/TestLevel/lvl2.png",  // Render
		window,
		230,                         // Size (in tiles) X
		150                          // Size (in tiles) Y
	);

	// Camera
	cam = new Camera(
		1920,               // Taille X camera (a pas modif)
		1080,               // Taille Y camera (a pas modif)
		230 * 50,               // Taille X du niveau
		150 * 50,               // Taille Y du niveau
		10               // Lag factor
	);
	Machine = new StateMachine(new IdleState());

	// Player
	player = new PlayerEX(
		window,
		1,
		glob.pos.x,
		glob.pos.y,
		50,
		50,
		1400,
		500,
		"sprite/Debug/PlaceHolder.png",
		1,
		*Machine
	);
	player->canDB = glob.DBUnlock;
	player->canFloat = glob.FloatUnlock;

	cam->view->setCenter(player->pos);

	parralax = new BG_parralax_Full();
	parralax->addlayer("sprite/Background/Debugmap.png", 0.5);

	//Trigger
	trig = new Trigger(
		-25,
		350,
		50,
		150,
		true
	);

	point = new SavePoint(
		3600,
		6500,
		2
	);
}

Level1::~Level1() {
	Colliderlist.clear();
	delete loader;
	delete cam;
	delete player;
	delete parralax;
	delete trig;

	loader = nullptr;
	cam = nullptr;
	player = nullptr;
	parralax = nullptr;
	trig = nullptr;
}

void Level1::update(const bool* keys, float dt) {
	loader->update(dt, *player);
	player->update(dt, loader->colliders);
	cam->Update(dt, *player);
	parralax->update(dt, *cam);
	trig->update(dt, *player);
	point->update(dt, *player, glob);

	if (player->pos.y > 10000) {
		player->pos.y = glob.pos.y;
	}
}

void Level1::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	trig->render(window);
	point->render(window);
}

void Level1::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (trig->trigger) {
		glob.pos = { 1400, 450 };
		glob.RezPos = { 1400, 450 };
		currentScene = SceneState::Map1;
	}
}