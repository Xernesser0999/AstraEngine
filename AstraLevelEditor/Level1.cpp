#include "Level1.h"
#include "Global.h"

Level1::Level1(sf::RenderWindow& window, Global& var_) : glob(var_) {
    loader = new LevelLoader();
    loader->load(
        "level/TestLevel/lvl2.txt",  
        "level/TestLevel/lvl2.png",  
        window,
        230,                         
        150                          
    );
   
	cam = new Camera(
		1920,               // Taille X camera (a pas modif)
		1080,               // Taille Y camera (a pas modif)
		230 * 50,               // Taille X du niveau
		150 * 50,               // Taille Y du niveau
		7               // Lag factor
	);
    Machine = new StateMachine(new DummyState());

	// Player
	player = new PlayerEX(
		window,
		3,
		glob.pos.x,
		glob.pos.y,
		70,
		97,
		1400,
		700,
		"",
		1,
		*Machine
	);
	Machine->currentState = new IdleStateRight(*player);

	player->canDB = glob.DBUnlock;
	player->canFloat = glob.FloatUnlock;

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

	point = new SavePoint(
		3600,
		6500,
		2
	);
	point1 = new SavePoint(
		8500,
		4450,
		2
	);
	point2 = new SavePoint(
		7900,
		3850,
		2
	);

	pnjJump = new Pnj(
		8600,
		4430,
		70,
		70,
		"sprite/Debug/Baker.png"
	);
	pnjFloat = new Pnj(
		8000,
		3830,
		70,
		70,
		"sprite/Debug/Baker.png"
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
	cam->Update(dt, *player);
	parralax->update(dt, *cam);
	trig->update(dt, *player);

	point->update(dt, *player, glob);
	point1->update(dt, *player, glob);
	point2->update(dt, *player, glob);

	pnjJump->updatePnj(dt, *player, 1, 2, glob);
	pnjFloat->updatePnj(dt, *player, 2, 2, glob);

	if (player->pos.y > 10000) {
		player->pos.y = glob.pos.y;
	}
	/*lvl2ProjectileN1->update(dt, *player);
	lvl2ProjectileN2->update(dt, *player, 2.0f);
	lvl2ShooterN1->update(dt, 5.0f, lvl2ProjectileN1);
	lvl2ShooterN2->update(dt, 5.0f, lvl2ProjectileN2);*/

}

void Level1::displayScene(sf::RenderWindow& window)
{
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	Machine->currentState->render(window);
	trig->render(window);

	point->render(window);
	point1->render(window);
	point2->render(window);

	pnjFloat->renderPnj(window);
	pnjJump->renderPnj(window);

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
		glob.RezPos = { 1400, 450 };
		currentScene = SceneState::Map1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		currentScene = SceneState::MenuS;
	}
}