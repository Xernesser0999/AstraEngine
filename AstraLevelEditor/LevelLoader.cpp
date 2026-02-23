#include "LevelLoader.h"

#include "Camera.h"


void LevelLoader::load(const std::string& collider_path, const std::string& render_path, sf::RenderWindow& window, float tileX, float tileY)
{
    std::ifstream file(collider_path);
    if (!file.is_open()) return;

    actualX = 0;
    actualY = 0;

    std::string line;
    int size = 50;

    int id;
    while (std::getline(file, line))
    {
        actualX = 0;

        for (char c : line)
        {
            if (c == '1')
            {
                colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Debug/Collider_DebugTX.png"));
            }

            actualX += size;
        }

        actualY += size;
    }


    back = new BGstatic(window, render_path, tileX, tileY);
}

void LevelLoader::oldload(const std::string& path, sf::RenderWindow& window)
{
    std::ifstream file(path);
    if (!file.is_open()) return;

    actualX = 0;
    actualY = 0;

    int size = 50;

    int id;
    while (file >> id)   // lit un nombre (ex : 012 → 12)
    {
        // Conversion ID → sprite
        switch (id)
        {
        case 1: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest001.png")); break;
        case 2: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest002.png")); break;
        case 3: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest003.png")); break;
        case 4: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest004.png")); break;
        case 5: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest005.png")); break;
        case 6: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest006.png")); break;
        case 7: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest007.png")); break;
        case 8: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest008.png")); break;
        case 9: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest009.png")); break;
        case 10: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest010.png")); break;
        case 11: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest011.png")); break;
        case 12: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest012.png")); break;
        case 13: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest013.png")); break;
        case 14: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest014.png")); break;
        case 15: colliders.push_back(new Collider(window, actualX, actualY, size, size, "sprite/Testing/forest015.png")); break;

        default:
            break; // 000 → rien
        }

        // Gestion du placement
        actualX += size;

        // Si on atteint la fin de ligne → retour à la ligne
        if (file.peek() == '\n')
        {
            file.get(); // consomme le '\n'
            actualY += size;
            actualX = 0;
        }
    }
}

void LevelLoader::render(sf::RenderWindow& window, Camera* cam) {
    back->renderCam(window, *cam);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {                  // Arrow Left
        for (Collider* c : colliders) {
            c->render(window, *cam);
        }
    }
}

void LevelLoader::update(float dt, PlayerEX& player) {

}

LevelLoader::~LevelLoader() {
    colliders.clear();
    delete back;
    back = nullptr;
}