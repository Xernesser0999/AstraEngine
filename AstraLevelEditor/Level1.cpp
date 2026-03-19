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
		1920,					 
		1080,					
		230 * 50,              
		150 * 50,             
		7					 
	);
	Machine = new StateMachine(new DummyState());

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
	player->hp = glob.hp;

	lvl2Blob1 = new BlobEnemy(2700, 7003, 50, 50, 5.5, 100);
	lvl2Blob2 = new BlobEnemy(6700, 4653, 50, 50, 2.5, 100);
	lvl2Shooter1 = new Shooter(10810.0f, 4030.0f, 400.0f, 'r');
	lvl2Shooter2 = new Shooter(11400.0f, 3750, 300.0f, 'l');

	lvl2Projectile1 = new Projectile(*lvl2Shooter1);
	lvl2Projectile2 = new Projectile(*lvl2Shooter2);
	flot = new FlottingElement(window, 9700, 3103, 50, 50, 3.0, 150, "sprite/Debug/PlaceHolder.png");


	cam->view->setCenter(player->pos);

	parralax = new BG_parralax_Full();
	parralax->addlayer("sprite/Background/fond.png", 0);
	parralax->addlayer("sprite/Background/building2.png", 0.1);
	parralax->addlayer("sprite/Background/building1.png", 0.3);
	parralax->addlayer("sprite/Background/background3.png", 0.5);
	parralax->addlayer("sprite/Background/background2.png", 0.7);
	parralax->addlayer("sprite/Background/background1.png", 0.9);

	trig = new Trigger(
		0,
		7053,
		50,
		200,
		true
	);

	point = new SavePoint(
		3600,
		6500,
		2
	);

	hud = new Hud();
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
		60,
		78,
		"sprite/SpriteSheet/pnj.png"
	);
	pnjFloat = new Pnj(
		8000,
		3830,
		60,
		78,
		"sprite/SpriteSheet/pnj.png"
	);

	music.openFromFile("Audio/Mai.mp3");
	music.setLooping(true);
	music.setVolume(100.f);
	music.play();
}

Level1::~Level1() {
	Colliderlist.clear();
	delete loader;
	delete cam;
	delete player;
	delete parralax;
	delete trig;
	delete lvl2Shooter1;
	delete lvl2Shooter2;
	delete lvl2Projectile1;
	delete lvl2Projectile2;
	delete lvl2Blob1;
	delete lvl2Blob2;
	delete flot;
	delete hud;

	loader = nullptr;
	cam = nullptr;
	player = nullptr;
	parralax = nullptr;
	trig = nullptr;
	lvl2Shooter1 = nullptr;
	lvl2Shooter2 = nullptr;
	lvl2Projectile1 = nullptr;
	lvl2Projectile1 = nullptr;
	lvl2Blob1 = nullptr;
	lvl2Blob2 = nullptr;
	flot = nullptr;
	hud = nullptr;
}

void Level1::update(const bool* keys, float dt) {
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
	flot->update(*player, dt);

	if (player->pos.y > 10000) {
		player->pos.y = glob.pos.y;
	}
	lvl2Projectile1->update(dt, *player, 1.5f);
	lvl2Projectile2->update(dt, *player, 1.5f);

	lvl2Shooter1->update(dt, 1.5f, lvl2Projectile1);
	lvl2Shooter2->update(dt, 1.5f, lvl2Projectile2);
	lvl2Blob1->update(dt, *player);
	lvl2Blob2->update(dt, *player);

}

void Level1::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	point->render(window);
	point1->render(window);
	point2->render(window);
	player->render(window);
	Machine->currentState->render(window);
	trig->render(window);


	pnjFloat->renderPnj(window);
	pnjJump->renderPnj(window);

	lvl2Shooter1->render(window);
	lvl2Shooter2->render(window);
	lvl2Projectile1->render(window);
	lvl2Projectile2->render(window);
	lvl2Blob1->render(window);	
	lvl2Blob2->render(window);
	flot->draw(window);

	window.setView(window.getDefaultView());
	hud->draw(window, *player, glob);
}

void Level1::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window)
{
	if (trig->trigger)
	{
		music.stop();
		glob.pos = { 3650, 670 };
		glob.RezPos = { 1400, 450 };
		glob.hp = player->hp;
		currentScene = SceneState::Map1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		music.stop();
		currentScene = SceneState::MenuS;
	}
}