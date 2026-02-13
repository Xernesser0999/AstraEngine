#include <SFML/Graphics.hpp>

#include "Pawn.h"
#include "Collider.h"
#include "Camera.h"
#include "PlayerEX.h"
#include <iostream>

int main()
{
    // |\-_________________-/|
    // ####### WINDOW ########
    // |/-------------------\|
    sf::RenderWindow window(
        sf::VideoMode({ 1920, 1080 }),
        "SFML window"
    );
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // |\-_________________-/|
    // ##### CONSTRUCTOR #####
    // |/-------------------\|
    Collider test(window, 0, 900, 2000, 100, "sprite/PlaceHolder.png");
    std::vector<Collider*> Colliderlist;
    Colliderlist.push_back(&test);


    Camera cam(1920, 1080, 10000, 10000);
    PlayerEX player
    (
        window,
        1,
        100,
        100,
        100,
        100,
        1250,
        500,
        "sprite/PlaceHolder.png",
        1
    );


    sf::Clock clock;
    float dt;
    // |\-_________________-/|
    // ###### GAME LOOP ######
    // |/-------------------\|
    while (window.isOpen())
    {
        // EVENT
        dt = clock.restart().asSeconds();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // CLEAR
        window.clear();

        // UPDATE
        player.update(dt, Colliderlist);
        cam.setCameraOnPlayer(player);

        // RENDER
        test.render(window, cam);
        player.render(window, &cam);

        // WINDOW DISPLAY
        window.display();
    }
}