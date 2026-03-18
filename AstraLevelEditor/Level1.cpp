#include "Level1.h"
#include "Global.h"

Level1::Level1(sf::RenderWindow& window, Global& var_) : glob(var_) {
    loader = new LevelLoader();
    loader->load(
        "level/TestLevel/maptestv2.txt",  
        "level/TestLevel/maplvl2.png",  
        window,
        230,                         
        120                          
    );
   
    cam = new Camera(
        1920,              
        1080,               
        230*50,               
        120*50,             
        0.005             
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
	cam->Update(*player);
	parralax->update(dt, *cam);
	trig->update(dt, *player);
}

void Level1::displayScene(sf::RenderWindow& window) {
	window.setView(*cam->view);

	parralax->render(window);
	loader->render(window, cam);
	player->render(window);
	Machine->currentState->render(window);
	trig->render(window);
}

void Level1::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
	if (trig->trigger) {
		glob.pos = { 1400, 450 };
		currentScene = SceneState::Map1;
	}
}