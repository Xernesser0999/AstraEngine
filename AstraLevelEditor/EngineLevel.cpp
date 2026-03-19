#include "EngineLevel.h"
#include "Global.h"

EngineLevel::EngineLevel(sf::RenderWindow& window, Global& var_) : glob(var_) {
   
    loader = new LevelLoader();
    loader->load (
        "level/TestLevel/map.txt",  
        "level/TestLevel/map.png",  
        window,
        60,                         
        40                        
    );

   
    cam = new Camera(1920, 1080, 50*60, 50*40, 0.005);
    Machine = new StateMachine(new IdleStateRight(*player));

   
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
        1,
        *Machine
    );

    parralax = new BG_parralax_Full();
    parralax->addlayer("sprite/Background/Debugmap.png", 0.5);

   
    trig = new Trigger(
        500,
        800,
        150,
        50,
        true
    );
}

EngineLevel::~EngineLevel() {
    for (auto& r : Colliderlist) {
        delete r;
        r = nullptr;
    }
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

    delete Machine;
    Machine = nullptr;
}

void EngineLevel::update(const bool* keys, float dt) {
    loader->update(dt, *player);
    player->update(dt, loader->colliders);
    cam->Update(dt, *player);
    parralax->update(dt, *cam);
    trig->update(dt, *player);
    if (trig->trigger) {
        std::cout << "tick";
    }
}

void EngineLevel::displayScene(sf::RenderWindow& window) {
    parralax->render(window);
    loader->render(window, cam);
    player->render(window);
    trig->render(window);
}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
}