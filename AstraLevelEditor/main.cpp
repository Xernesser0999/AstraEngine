#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

#include "SceneManager.h"
#include "KeyStruct.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Astra Engine");
    SceneManager sM = SceneManager(window);
    SceneManager::Instance = &sM;//Ne pas supprimer, mis par Benoit
    keys myKeys;
    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        myKeys.initKeys(myKeys.myKeys);
        sM.manageState(&myKeys, window);
        sM.updateState(myKeys.myKeys, dt, window);

        window.clear();

        sM.displayState(window);

        window.display();
    }
}