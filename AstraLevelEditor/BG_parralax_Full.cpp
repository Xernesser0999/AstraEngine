#include "BG_parralax_Full.h"

#include "Camera.h"


BG_parralax_Full::BG_parralax_Full() {

}


void BG_parralax_Full::addLayer(std::string file, float speed)
{
    ParallaxLayer layer;
    layer.TX.loadFromFile(file.c_str());
    layer.speed = speed;
    layer.offsetX = 0.0f;
    layer.offsetY = 0.0f;
    layer.rect.setPosition({0, 0});
    layer.rect.setSize({1920, 1080});
    layers.push_back(layer);
}

void BG_parralax_Full::render(sf::RenderWindow& window, Camera& camera, float LevelSizeX, float LevelSizeY)
{
    for (auto& layer : layers)
    {
        sf::RectangleShape screenRect = camera.worldToScreen(layer.rect);

        layer.offsetX = -camera.pos.x;

        float normalizedOffset = layer.offsetX - (camera.ScreenSize.x * layer.speed);
        if (layer.size.x > 0) {
            normalizedOffset = fmod(layer.offsetX, layer.size.x);
            if (normalizedOffset > 0) {
                normalizedOffset -= layer.size.x;
            }
        }

        float startX = normalizedOffset;

        for (float x = startX; x < LevelSizeX; x += layer.size.x)
        {
<<<<<<< Updated upstream
            /*
            sf::RectangleShape dst{
                x,
                LevelSizeY - layer.size.y / 1.5 - camera.pos.y * layer.speed,
                layer.size.x,
                layer.size.y
            };
            */
=======
            sf::RectangleShape dst(sf::Vector2f(layer.size.x, layer.size.y));

            dst.setPosition({
                x, LevelSizeY - layer.size.y / 1.5f - camera.pos.y * layer.speed
            });

>>>>>>> Stashed changes
            window.draw(screenRect);
        }
    }
};

BG_parralax_Full::~BG_parralax_Full() {

}