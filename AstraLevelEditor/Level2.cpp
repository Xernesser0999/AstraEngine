#include "Level2.h"
#include "Global.h"

Level2::Level2(sf::RenderWindow& window, Global& var_) : glob(var_) {
	// Level loader
	loader = new LevelLoader();
	loader->load(
		"level/TestLevel/lvl3.txt",  // Collision
		"level/TestLevel/lvl3.png",  // Render
		window,
		120,                         // Size (in tiles) X
		150                          // Size (in tiles) Y
	);

	// Camera
	cam = new Camera(
		1920,               // Taille X camera (a pas modif)
		1080,               // Taille Y camera (a pas modif)
		120 * 50,               // Taille X du niveau
		150 * 50,               // Tailel Y du niveau
		10               // Lag factor
	);
	
	Machine = new StateMachine(new DummyState());

	// Player
	player = new PlayerEX(
		window,
		1,
		glob.pos.x,
		glob.pos.y,
		50,
		50,
		1250,
		500,
		"sprite/Debug/PlaceHolder.png",
		1,
		*Machine
	);
	Machine->currentState = new IdleStateRight(*player);

	player->canDB = glob.DBUnlock;
	player->canFloat = glob.FloatUnlock;

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
}

Level2::~Level2() {
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

void Level2::update(const bool* keys, float dt) {
	loader->update(dt, *player);
	player->update(dt, loader->colliders);
	cam->Update(dt, *player);
	parralax->update(dt, *cam);
	trig->update(dt, *player);

	if (player->pos.y > 10000) {
		player->pos.y = glob.pos.y;
	}
}

void Level2::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	Machine->currentState->render(window);
	trig->render(window);
}

void Level2::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (trig->trigger) {
		glob.pos = { 1500, 1450 };
		currentScene = SceneState::Map3;
	}
}