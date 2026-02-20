#include "LevelLoader.h"

#include "Camera.h"

void LevelLoader::load(const std::string& path, sf::RenderWindow& window)
{
    std::ifstream file(path);
    if (!file.is_open()) return;

    actualX = 0;
    actualY = 0;

    int size = 50;

    char c;
    while (file.get(c))
    {
        if (c == 'X')
        {
            colliders.push_back(
                new Collider(window, actualX, actualY, size, size, "sprite/Environment/ForestUp.png")
            );
        }
        if (c == 'O')
        {
            colliders.push_back(
                new Collider(window, actualX, actualY, size, size, "sprite/Environment/ForestDown.png")
            );
        }
        if (c == 'I')
        {
            colliders.push_back(
                new Collider(window, actualX, actualY, size, size, "sprite/Environment/ForestLeft.png")
            );
        }
        if (c == 'L')
        {
            colliders.push_back(
                new Collider(window, actualX, actualY, size, size, "sprite/Environment/ForestRight.png")
            );
        }
        if (c == 'Z')
        {
            colliders.push_back(
                new Collider(window, actualX, actualY, size, size, "sprite/Environment/ForestFill.png")
            );
        }

        if (c == '\n')
        {
            actualY += size;
            actualX = 0;
        }
        else
        {
            actualX += size;
        }
    }
}

void LevelLoader::render(sf::RenderWindow& window, Camera* cam) {
    for (Collider* c : colliders) {
        c->render(window, *cam);
    }
}

void LevelLoader::update(float dt, PlayerEX& player) {

}