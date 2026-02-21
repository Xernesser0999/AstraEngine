#include "EngineLevel.h"

EngineLevel::EngineLevel(sf::RenderWindow& window) {
    loader = new LevelLoader();
    loader->load("level/TestLevel/Level.txt","level/TestLevel/Level.png", window);

    cam = new Camera(1920, 1080, 10000, 10000);
    player = new PlayerEX
    (
        window,
        1,
        100,
        100,
        50,
        50,
        1250,
        500,
        "sprite/Debug/PlaceHolder.png",
        1
    );
}

EngineLevel::~EngineLevel() {
    Colliderlist.clear();
}

void EngineLevel::displayScene(sf::RenderWindow& window) {
    loader->render(window, cam);
    player->render(window, cam);
}

void EngineLevel::update(const bool* keys, float dt) {
    loader->update(dt, *player);
    player->update(dt, loader->colliders);
    cam->setCameraOnPlayer(*player);
}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
    //    currentScene = SceneState::menu;
    //    EngineLevel::~EngineLevel();
    //}
}