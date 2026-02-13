#include "EngineLevel.h"

EngineLevel::EngineLevel(sf::RenderWindow& window) {
    Colliderlist.push_back(new Collider(window, 0, 900, 2000, 100, "sprite/PlaceHolder.png"));
    Colliderlist.push_back(new Collider(window, 2000, 900, 2000, 100, "sprite/PlaceHolder.png"));
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
        "sprite/PlaceHolder.png",
        1
    );
}

EngineLevel::~EngineLevel() {
    Colliderlist.clear();
}

void EngineLevel::displayScene(sf::RenderWindow& window) {
    for (Collider* c : Colliderlist) {
        c->render(window, *cam);
    }
    player->render(window, cam);
}

void EngineLevel::update(const bool* keys, float dt) {
    player->update(dt, Colliderlist);
    cam->setCameraOnPlayer(*player);
}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape)) {
    //    currentScene = SceneState::menu;
    //    EngineLevel::~EngineLevel();
    //}
}