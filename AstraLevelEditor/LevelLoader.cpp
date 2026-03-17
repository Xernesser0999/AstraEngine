#include "LevelLoader.h"
#include "Camera.h"

void LevelLoader::load(const std::string& collider_path, const std::string& render_path, sf::RenderWindow& window, float tileX, float tileY)
{
    std::ifstream file(collider_path);

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
            if (c == '2')
            {
                spike.push_back(new Spike(window, actualX, actualY+25, size, 25, "sprite/Environment/Piques.png"));
            }

            actualX += size;
        }

        actualY += size;
    }

    back = new BGstatic(window, render_path, tileX * 50, tileY * 50);
}

void LevelLoader::TileLoad(const std::string& path, const std::string& collpath, sf::RenderWindow& window)
{
    // Load render
    std::ifstream file(path);

    actualX = 0;
    actualY = 0;

    int size = 50;

    char c;
    while (file.get(c))
    {
        switch (c)
        {
        case 'A': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest001.png")); break;
        case 'Z': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest002.png")); break;
        case 'E': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest003.png")); break;
        case 'R': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest004.png")); break;
        case 'T': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest005.png")); break;
        case 'Y': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest006.png")); break;
        case 'U': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest007.png")); break;
        case 'I': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest008.png")); break;
        case 'O': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest009.png")); break;
        case 'P': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest010.png")); break;
        case 'Q': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest011.png")); break;
        case 'S': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest012.png")); break;
        case 'D': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest013.png")); break;
        case 'F': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest014.png")); break;
        case 'G': Display.push_back(new DisplayEntity(window, actualX, actualY, size, size, "sprite/Testing/forest015.png")); break;

        default:
            break;
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

    std::string line;
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
}

void LevelLoader::render(sf::RenderWindow& window, Camera* cam) {
    back->renderCam(window, *cam);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
        for (Collider* c : colliders) {
            c->render(window, *cam);
        }
    }
    for (Spike* z : spike) {
        z->draw(window);
    }
}

void LevelLoader::TileRender(sf::RenderWindow& window, Camera* cam) {
    for (auto& c : Display) {
        c->render(window, *cam);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
        for (Collider* c : colliders) {
            c->render(window, *cam);
        }
    }
}

void LevelLoader::update(float dt, PlayerEX& player) {
    for (Spike* z : spike) {
        z->update(player);
    }
}

LevelLoader::~LevelLoader()  {
    for (auto& c : colliders) {
        delete c;
        c = nullptr;
    }
    for (auto& z : spike) {
        delete z;
        z = nullptr;
    }
    colliders.clear();
    spike.clear();

    delete back;
    back = nullptr;
}