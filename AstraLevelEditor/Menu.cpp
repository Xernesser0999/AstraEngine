#include "Menu.h"
#include "Global.h"

Menu::Menu(sf::RenderWindow& window, Global& var_) : glob(var_) {

    Background = new BGstatic(
        window,
        "sprite/Menu/MenuBackground.png",
        1920,
        1080
    );
    play = new GUI_button(1920 / 2 - 120, 1080 / 2, 240, 60, "sprite/Menu/PlayButton.png", "sprite/Menu/PlayButtonHover.png");
    quit = new GUI_button(1920 / 2 - 120, 1080 / 2 + 100, 240, 60, "sprite/Menu/QuitButton.png", "sprite/Menu/QuitButtonHover.png");
    trash = new GUI_button(1920 - 100, 1080 - 100, 50, 50, "sprite/Menu/TrashIcon.png", "sprite/Menu/TrashIconHover.png");
    
    rect.setSize({ 145*2, 48*2 });
    rect.setPosition({1920 - 145*2, 0});
    TX.loadFromFile("sprite/Menu/Control.png");
    rect.setTexture(&TX);

    glob.load();
}

Menu::~Menu() {
    delete Background;
    delete play;
    
    play = nullptr;
    Background = nullptr;
}

void Menu::update(const bool* keys, float dt) {
   
}

void Menu::displayScene(sf::RenderWindow& window) {

    Background->render(window);

    play->hovered(window);
    play->render(window);

    quit->hovered(window);
    quit->render(window);
    if (quit->clicked(window)) {
        abort();
    }

    trash->hovered(window);
    trash->render(window);
    if (trash->clicked(window)) {
        glob.reset();
    }

    window.draw(rect);
}

void Menu::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
    if (play->clicked(window)) {
        if (glob.actualLevel == 1) {
            currentScene = SceneState::Map1;
        }
        if (glob.actualLevel == 2) {
            currentScene = SceneState::Map2;
        }
        if (glob.actualLevel == 3) {
            currentScene = SceneState::Map1;
        }
    }
}