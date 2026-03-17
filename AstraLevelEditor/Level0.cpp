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
        76*50,               
        60*50,               
        0.005              
    );
    Machine = new StateMachine(new IdleState());

    player = new PlayerEX(
        window,
        1,
        0,
        0,
        50,
        50,
        1400,
        700,
        "sprite/Debug/PlaceHolder.png",
        1,
        *Machine

        
    );
    blob = new BlobEnemy(1250, 1750, 5.5, 100);
	blob1 = new BlobEnemy(1600, 550, 5.0, 100);
	blob2 = new BlobEnemy(3125, 950, 1.50, 100);
   
    spike = new Spike(
        window,
        200,
        2500,
        200,
        200,
        "sprite/Environment/Spike.png"
    );
    flot = new FlottingElement(window, 830, 1850, 50, 50, 3.0, 150, "sprite/Debug/PlaceHolder.png");
    flot2 = new FlottingElement(window, 625, 1720, 50, 50, 3.0, 150, "sprite/Debug/PlaceHolder.png");
    flot3 = new FlottingElement(window, 2125, 1150, 50, 50, 1.25, 150, "sprite/Debug/PlaceHolder.png");
    flot4 = new FlottingElement(window, 2323, 1150, 50, 50, 1.25, 150, "sprite/Debug/PlaceHolder.png");
    flot5 = new FlottingElement(window, 3426, 2100, 50, 50, 1.5, 150, "sprite/Debug/PlaceHolder.png");
    flot6 = new FlottingElement(window, 3228, 2100, 50, 50, 1.5, 150, "sprite/Debug/PlaceHolder.png");
    flot7 = new FlottingElement(window, 2374, 150, 50, 50, 2, 150, "sprite/Debug/PlaceHolder.png");
    flot8 = new FlottingElement(window, 1268, 450, 50, 50, 4, 150, "sprite/Debug/PlaceHolder.png");
    flot9 = new FlottingElement(window, 771, 450, 50, 50, 3, 300, "sprite/Debug/PlaceHolder.png");

    if (glob.Boot) {
        glob.Boot = false;
        player->pos = {100, 2000};
    }
    else {
        player->pos = glob.pos;
    }

    parralax = new BG_parralax_Full();
    parralax->addlayer("sprite/Background/Debugmap.png", 0.5);

    trig = new Trigger(
        3800,
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
    delete trig;
    delete spike;
    delete blob;
    delete blob1;
    delete blob2;
    delete flot;
    delete flot2;
    delete flot3;
    delete flot4;
    delete flot5;
    delete flot6;
    delete flot7;
    delete flot8;
    delete flot9;

    loader = nullptr;
    cam = nullptr;
    player = nullptr;
    parralax = nullptr;
    trig = nullptr;
    spike = nullptr;
    blob = nullptr;
	blob1 = nullptr;
	blob2 = nullptr;
    flot = nullptr;
    flot2 = nullptr;
    flot3 = nullptr;
    flot4 = nullptr;
    flot5 = nullptr;
    flot6 = nullptr;
    flot7 = nullptr;
    flot8 = nullptr;
    flot9 = nullptr;
}

void Level0::update(const bool* keys, float dt) {
    loader->update(dt, *player);
    player->update(dt, loader->colliders);
    cam->Update(*player);
    parralax->update(dt, *cam);
    trig->update(dt, *player);
	blob->update(dt);
	blob1->update(dt);
	blob2->update(dt);
    spike->update(*player);
    flot->update(*player, dt);
    flot2->update(*player, dt);
    flot3->update(*player, dt);
    flot4->update(*player, dt);
    flot5->update(*player, dt);
    flot6->update(*player, dt);
    flot7->update(*player, dt);
    flot8->update(*player, dt);
    flot9->update(*player, dt);
}

void Level0::displayScene(sf::RenderWindow& window) {
    window.setView(*cam->view);

    parralax->render(window);
    loader->render(window, cam);
    player->render(window);
    trig->render(window, *cam);
	blob->render(window);
	blob1->render(window);
	blob2->render(window);
    spike->draw(window);
    flot->draw(window);
    flot2->draw(window);
    flot3->draw(window);
    flot4->draw(window);
    flot5->draw(window);
    flot6->draw(window);
    flot7->draw(window);
    flot8->draw(window);
    flot9->draw(window);
}

void Level0::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (trig->trigger) {
        glob.pos = { 50, 450 };
        currentScene = SceneState::Map2;
    }
}