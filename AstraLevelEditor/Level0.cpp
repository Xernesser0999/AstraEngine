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
		7
	);
    Machine = new StateMachine(new DummyState());

    player = new PlayerEX(
        window,
        3,
        0,
        0,
        70,
        97,
        1400,
        700,
        "",
        1,
        *Machine
    );

    Machine->currentState = new IdleStateRight(*player);

	point = new SavePoint(
		2200,
		1450,
		1
	);

	blob = new BlobEnemy(1250, 1750, 50, 50, 5.5, 100);
	blob1 = new BlobEnemy(1600, 550, 50, 50, 5.0, 100);
	blob2 = new BlobEnemy(3125, 950, 50, 50, 1.50, 100);

	flot = new FlottingElement(window, 830, 1850, 50, 50, 3.0, 150, "sprite/Debug/PlaceHolder.png");
	flot2 = new FlottingElement(window, 625, 1720, 50, 50, 3.0, 150, "sprite/Debug/PlaceHolder.png");
	flot3 = new FlottingElement(window, 2125, 1150, 50, 50, 1.25, 150, "sprite/Debug/PlaceHolder.png");
	flot4 = new FlottingElement(window, 2323, 1150, 50, 50, 1.25, 150, "sprite/Debug/PlaceHolder.png");
	flot5 = new FlottingElement(window, 3426, 2100, 50, 50, 1.5, 150, "sprite/Debug/PlaceHolder.png");
	flot6 = new FlottingElement(window, 3228, 2100, 50, 50, 1.5, 150, "sprite/Debug/PlaceHolder.png");
	flot7 = new FlottingElement(window, 2374, 150, 50, 50, 2, 150, "sprite/Debug/PlaceHolder.png");
	flot8 = new FlottingElement(window, 1268, 450, 50, 50, 4, 150, "sprite/Debug/PlaceHolder.png");
	flot9 = new FlottingElement(window, 771, 450, 50, 50, 3, 300, "sprite/Debug/PlaceHolder.png");

	shooter1 = new Shooter(2300, 2050, 350.0f, 'l');
	shooter2 = new Shooter(800, 1550, 250.0f, 'r');

	projectile1 = new Projectile(*shooter1);
	projectile2 = new Projectile(*shooter2);

	if (glob.Boot) {
		glob.Boot = false;
		player->pos = { 100, 2000 };
		player->Rez = { 100, 2600 };
	}
	else {
		player->pos = glob.pos;
		player->Rez = glob.RezPos;
		player->canDB = glob.DBUnlock;
		player->canFloat = glob.FloatUnlock;
	}

	parralax = new BG_parralax_Full();
	parralax->addlayer("sprite/Background/Debugmap.png", 0.5);

	trig1 = new Trigger(
		3800,
		650,
		50,
		150,
		true
	);
	trig2 = new Trigger(
		1050,
		0,
		225,
		55,
		true
	);
	pnjDoubleJump = new Pnj(
		150,
		2630,
		70,
		70,
		"sprite/Debug/Baker.png"
	);

    hud = new Hud();
}

Level0::~Level0() {
    Colliderlist.clear();
    delete loader;
    delete cam;
    delete player;
    delete parralax;
    delete trig1;
	delete trig2;
    delete spike;
    delete blob;
    delete blob1;
    delete blob2;
    delete flot;
    delete pnjDoubleJump;
    delete flot2;
    delete flot3;
    delete flot4;
    delete flot5;
    delete flot6;
    delete flot7;
    delete flot8;
    delete flot9;
    delete hud;
	delete shooter1;
	delete shooter2;
	delete projectile1;
	delete point;
	delete projectile2;

	loader = nullptr;
	cam = nullptr;
	player = nullptr;
	parralax = nullptr;
	trig1 = nullptr;
	trig2 = nullptr;
	blob = nullptr;
	blob1 = nullptr;
	blob2 = nullptr;
	flot = nullptr;
	pnjDoubleJump = nullptr;
    flot2 = nullptr;
    flot3 = nullptr;
    flot4 = nullptr;
    flot5 = nullptr;
    flot6 = nullptr;
    flot7 = nullptr;
    flot8 = nullptr;
    flot9 = nullptr;
    hud = nullptr;
	point = nullptr;
	shooter1 = nullptr;
	shooter2 = nullptr;
	projectile1 = nullptr;
	projectile2 = nullptr;
}

void Level0::update(const bool* keys, float dt) {
	loader->update(dt, *player);
	player->update(dt, loader->colliders);
	cam->Update(dt,  *player);
	parralax->update(dt, *cam);
	trig1->update(dt, *player);
	trig2->update(dt, *player);
	blob->update(dt, *player);
	blob1->update(dt, *player);
	blob2->update(dt, *player);
	flot->update(*player, dt);
	flot2->update(*player, dt);
	flot3->update(*player, dt);
	flot4->update(*player, dt);
	flot5->update(*player, dt);
	flot6->update(*player, dt);
	flot7->update(*player, dt);
	flot8->update(*player, dt);
	flot9->update(*player, dt);
	pnjDoubleJump->updatePnj(dt, *player, 1, 1, glob);
	
	projectile1->update(dt, *player, 2.0f);
	projectile2->update(dt, *player, 2.0f);


	point->update(dt, *player, glob);

	//if (player->pos.y > 10000) {
	//	player->pos.y = glob.pos.y;
	//}
	shooter1->update(dt, 5.0f, projectile1);
	shooter2->update(dt, 5.0f, projectile2);
}

void Level0::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	Machine->currentState->render(window);
	trig1->render(window);
	trig2->render(window);
	blob->render(window);
	blob1->render(window);
	blob2->render(window);

	flot->draw(window);
	flot2->draw(window);
	flot3->draw(window);
	flot4->draw(window);
	flot5->draw(window);
	flot6->draw(window);
	flot7->draw(window);
	flot8->draw(window);
	flot9->draw(window);
	pnjDoubleJump->renderPnj(window);
	
	projectile1->render(window);
	projectile2->render(window);

	shooter1->render(window);
	projectile1->render(window);
	point->render(window);
	shooter2->render(window);

	window.setView(window.getDefaultView());
	hud->draw(window, *player);
}

void Level0::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (trig1->trigger) {
		glob.pos = { 415, 6400 };
		glob.RezPos = { 415, 6400 };
		currentScene = SceneState::Map2;
	}
	if (trig2->trigger) {
		glob.pos = { 2650, 6500 };
		glob.RezPos = { 2650, 6500 };
		currentScene = SceneState::Map3;
	}
}