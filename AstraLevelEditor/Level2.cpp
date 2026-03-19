#include "Level2.h"
#include "Global.h"

Level2::Level2(sf::RenderWindow& window, Global& var_) : glob(var_) {
	loader = new LevelLoader();
	loader->load(
		"level/TestLevel/lvl3.txt",  
		"level/TestLevel/lvl3.png",  
		window,
		120,                         
		150                          
	);

	cam = new Camera(
		1920,              
		1080,              
		120 * 50,               
		150 * 50,              
		7               
	);
	
	Machine = new StateMachine(new DummyState());

	player = new PlayerEX(
		window,
		1,
		glob.pos.x,
		glob.pos.y,
		70,
		97,
		1250,
		500,
		"sprite/Debug/PlaceHolder.png",
		3,
		*Machine
	);

	blob1 = new BlobEnemy(4350, 950, 50, 50, 2.5f, 100);
	blob3 = new BlobEnemy(2565, 1950, 50, 50, 5.0f, 100);
	blob4 = new BlobEnemy(1760, 2450, 50, 50, 5.0f, 100);
	blob5 = new BlobEnemy(1900, 4150, 50, 50, 5.0f, 100);
	blob6 = new BlobEnemy(2420, 5650, 50, 50, 6.5f, 100);

	flot1 = new FlottingElement(window, 300, 3150, 50, 50, 5, 50, "sprite/Debug/PlaceHolder.png");
	flot2 = new FlottingElement(window, 1200, 3500, 50, 50, 4.5, 75, "sprite/Debug/PlaceHolder.png");
	flot3 = new FlottingElement(window, 2680, 5800, 50, 50, 5, 50, "sprite/Debug/PlaceHolder.png");

	Machine->currentState = new IdleStateRight(*player);

	player->canDB = glob.DBUnlock;
	player->canFloat = glob.FloatUnlock;

	parralax = new BG_parralax_Full();
	parralax->addlayer("sprite/Background/fond.png", 0);
	parralax->addlayer("sprite/Background/building2.png", 0.1);
	parralax->addlayer("sprite/Background/building1.png", 0.3);
	parralax->addlayer("sprite/Background/background3.png", 0.5);
	parralax->addlayer("sprite/Background/background2.png", 0.7);
	parralax->addlayer("sprite/Background/background1.png", 0.9);

	trig = new Trigger(
		2750,
		7200,
		200,
		50,
		true
	);
	wintrig = new Trigger(
		2500,
		800,
		100,
		100,
		true
	);

	hud = new Hud();
	win = new Win();

	music.openFromFile("Audio/Mai.mp3");
	music.setLooping(true);
	music.setVolume(100.f);
	music.play();
}

Level2::~Level2() {
	Colliderlist.clear();
	delete loader;
	delete cam;
	delete player;
	delete parralax;
	delete trig;
	delete blob1;
	delete blob3;
	delete blob4;
	delete blob5;
	delete blob6;
	delete flot1;
	delete flot2;
	delete flot3;
	delete hud;
	delete win;

	loader = nullptr;
	cam = nullptr;
	player = nullptr;
	parralax = nullptr;
	trig = nullptr;
	blob1 = nullptr;
	blob3 = nullptr;
	blob4 = nullptr;
	blob5 = nullptr;
	blob6 = nullptr;
	flot1 = nullptr;
	flot2 = nullptr;
	flot3 = nullptr;
	hud = nullptr;
	win = nullptr;
}

void Level2::update(const bool* keys, float dt) {
	loader->update(dt, *player);
	player->update(dt, loader->colliders);
	cam->Update(dt, *player);
	parralax->update(dt, *cam);
	trig->update(dt, *player);

	if (player->pos.y > 10000) {
		player->pos = {2650, 6800};
	}

	blob1->update(dt, *player);
	blob3->update(dt, *player);
	blob4->update(dt, *player);
	blob5->update(dt, *player);
	blob6->update(dt, *player);

	flot1->update(*player, dt);
	flot2->update(*player, dt);
	flot3->update(*player, dt);

	wintrig->update(dt, *player);
	if (wintrig->trigger) {
		aswon = true;
	}
}

void Level2::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	Machine->currentState->render(window);
	trig->render(window);

	blob1->render(window);
	blob3->render(window);
	blob4->render(window);
	blob5->render(window);
	blob6->render(window);

	flot1->draw(window);
	flot2->draw(window);
	flot3->draw(window);

	window.setView(window.getDefaultView());

	hud->draw(window, *player, glob);

	if (aswon) {
		win->render(window);
	}
}

void Level2::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (trig->trigger) {
		music.stop();

		glob.pos = { 1500, 1450 };

		currentScene = SceneState::Map1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		music.stop();
		currentScene = SceneState::MenuS;
	}
}