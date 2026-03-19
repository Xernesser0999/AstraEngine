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
		0.005               // Lag factor
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

	lvl2ShooterN1 = new Shooter(10810.0f, 4030.0f, 1.5f, 'r');
	lvl2ProjectileN1 = new Projectile(*lvl2ShooterN1);

	lvl2ShooterN2 = new Shooter(11400.0f, 3750, 1.5f, 'l');
	lvl2ProjectileN2 = new Projectile(*lvl2ShooterN2);


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
}

Level1::~Level1()
{
	Colliderlist.clear();
	delete loader;
	delete cam;
	delete player;
	delete parralax;
	delete trig;
	delete lvl2ShooterN1;
	delete lvl2ProjectileN1;

	loader = nullptr;
	cam = nullptr;
	player = nullptr;
	parralax = nullptr;
	trig = nullptr;
	lvl2ShooterN1 = nullptr;
	lvl2ProjectileN1 = nullptr;
}

void Level1::update(const bool* keys, float dt)
{
	loader->update(dt, *player);
	player->update(dt, loader->colliders);
	cam->Update(*player);
	parralax->update(dt, *cam);
	trig->update(dt, *player);
	lvl2ProjectileN1->update(dt, *player, 3.0f);
	lvl2ProjectileN2->update(dt, *player, 2.0f);
	lvl2ShooterN1->update(dt, 5.0f, lvl2ProjectileN1);
	lvl2ShooterN2->update(dt, 5.0f, lvl2ProjectileN2);

}

void Level1::displayScene(sf::RenderWindow& window)
{
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	trig->render(window);

	lvl2ShooterN1->render(window);
	lvl2ShooterN2->render(window);
	lvl2ProjectileN1->render(window);
	lvl2ProjectileN2->render(window);
}

void Level1::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window)
{
	if (trig->trigger)
	{
		glob.pos = { 1400, 450 };
		currentScene = SceneState::Map1;
	}
}