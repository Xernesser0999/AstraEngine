#include "EngineLevel.h"

EngineLevel::EngineLevel(sf::RenderWindow& window) {
    // Level loader
    loader = new LevelLoader();
    loader->load (
        "level/TestLevel/map.txt",  // Collision
        "level/TestLevel/map.png",  // Render
        window,
        60,                         // Size (in tiles) X
        40                          // Size (in tiles) Y
    );

    // Camera
    cam = new Camera(1920, 1080, 50*60, 50*40, 0.01);

    // Player
    player = new PlayerEX (
        window,
        1,
        200,
        1300,
        50,
        50,
        1250,
        500,
        "sprite/Debug/PlaceHolder.png",
        1
    );

    // Parralax background
    parralax = new BGparralaxAuto (
        window,
        "sprite/Background/BG_layer3.png",
        "sprite/Background/BG_layer2.png",
        "sprite/Background/BG_layer1.png",
        "sprite/Background/BG_layer0.png",
        "",
        1920,
        1080,
        25,
        1.2
    );

    test = new Collider(
        window,
        500,
        1000,
        50,
        50,
        "sprite/Debug/PlaceHolder.png"
    );
}

EngineLevel::~EngineLevel() {
    Colliderlist.clear();
    delete loader;
    delete cam;
    delete player;
    delete parralax;

    loader = nullptr;
    cam = nullptr;
    player = nullptr;
    parralax = nullptr;
}

void EngineLevel::update(const bool* keys, float dt) {
    loader->update(dt, *player);
    player->update(dt, loader->colliders);
    cam->setCameraOnPlayer(*player);
    parralax->update(dt);
}

void EngineLevel::displayScene(sf::RenderWindow& window) {
    parralax->render(window);
    loader->render(window, cam);
    player->render(window, cam);
    test->render(window, *cam);
}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
    //    currentScene = SceneState::menu;
    //    EngineLevel::~EngineLevel();
    //}
}