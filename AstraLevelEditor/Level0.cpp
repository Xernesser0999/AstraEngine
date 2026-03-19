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
	shooter3 = new Shooter(3780, 1200, 250.0f, 'l');

	projectile1 = new Projectile(*shooter1);
	projectile2 = new Projectile(*shooter2);
	projectile3 = new Projectile(*shooter3);

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
		player->hp = glob.hp;
	}

	parralax = new BG_parralax_Full();
	parralax->addlayer("sprite/Background/ground.png", 0.0);
	parralax->addlayer("sprite/Background/building2.png", 0.1);
	parralax->addlayer("sprite/Background/building1.png", 0.3);
	parralax->addlayer("sprite/Background/background3.png", 0.5);
	parralax->addlayer("sprite/Background/background2.png", 0.7);
	parralax->addlayer("sprite/Background/background1.png", 0.9);

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
		2628,
		60,
		78,
		"sprite/SpriteSheet/pnj.png"
	);

    hud = new Hud();

	music.openFromFile("Audio/Mai.mp3");
	music.setLooping(true);
	music.setVolume(100.f);
	music.play();
}

Level0::~Level0() {
	for (auto r : Colliderlist) {
		delete r;
		r = nullptr;
	}
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
	delete point;
	delete shooter1;
	delete shooter2;
	delete shooter3;
	delete projectile1;
	delete projectile2;
	delete projectile3;

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
	shooter3 = nullptr;
	projectile1 = nullptr;
	projectile2 = nullptr;
	projectile3 = nullptr;
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
	
	projectile1->update(dt, *player, 5.0f);
	projectile2->update(dt, *player, 5.0f);
	projectile3->update(dt, *player, 3.0f);

	point->update(dt, *player, glob);

	shooter1->update(dt, 5.0f, projectile1);
	shooter2->update(dt, 5.0f, projectile2);
	shooter3->update(dt, 5.0f, projectile3);
}

void Level0::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	point->render(window);
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
	projectile3->render(window);
	shooter1->render(window);
	shooter2->render(window);
	shooter3->render(window);

	window.setView(window.getDefaultView());
	hud->draw(window, *player, glob);
}

void Level0::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (trig1->trigger) {
		music.stop();
		glob.pos = { 415, 6400 };
		glob.RezPos = { 415, 6400 };
		glob.hp = player->hp;
		currentScene = SceneState::Map2;
	}
	if (trig2->trigger) {
		music.stop();
		glob.pos = { 2650, 6500 };
		glob.RezPos = { 2650, 6500 };
		glob.hp = player->hp;
		currentScene = SceneState::Map3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		music.stop();
		currentScene = SceneState::MenuS;
	}
}