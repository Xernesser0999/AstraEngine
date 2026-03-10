#include "Level1.h"
#include "Global.h"

Level1::Level1(sf::RenderWindow& window, Global& var_) : glob(var_) {
    // Level loader
    loader = new LevelLoader();
    loader->load(
        "level/TestLevel/debug-map-02-coll.txt",  // Collision
        "level/TestLevel/debug-map-02.png",  // Render
        window,
        30,                         // Size (in tiles) X
        20                          // Size (in tiles) Y
    );

    // Camera
    cam = new Camera(1920, 1080, 50 * 500, 50 * 500, 0.005);

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
        1
    );

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
    parralax->render(window);
    loader->render(window, cam);
    player->render(window);
    trig->render(window, *cam);
}

void Level1::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (trig->trigger) {
        glob.pos = { 1400, 450 };
        currentScene = SceneState::Map1;
    }
}