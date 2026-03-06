#include "BG_parralax_Full.h"

#include "Camera.h"


BG_parralax_Full::BG_parralax_Full(SDL_Renderer* _renderer, float screenW, float screenH) {
    renderer = _renderer;
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

void BG_parralax_Full::render(Camera& camera)
{
    for (auto& layer : layers)
    {
        sf::RectangleShape screenRect = camera.worldToScreen(layer.rect);

        layer.offsetX = -camera.ScreenSize.x;

        float normalizedOffset = layer.offsetX - (camera.ScreenSize.x * layer.speed);
        if (layer.rect.w > 0) {
            normalizedOffset = fmod(layer.offsetX, layer.size.x);
            if (normalizedOffset > 0) {
                normalizedOffset -= layer.rect.w;
            }
        }

        float startX = normalizedOffset;

        for (float x = startX; x < levelWidth; x += layer.rect.w)
        {
            SDL_FRect dst{
                x,
                levelHeight - layer.rect.h / 1.5 - camera.sizeC.y * layer.speed,
                layer.rect.w,
                layer.rect.h
            };

            SDL_RenderTexture(renderer, layer.texture, nullptr, &dst);
        }
    }
};

BG_parralax_Full::~BG_parralax_Full() {

}