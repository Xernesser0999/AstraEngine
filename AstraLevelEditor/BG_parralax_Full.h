#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Camera;

struct ParallaxLayer {
    float speed;
    float offsetX;
    float offsetY;

    sf::Vector2f size = {1920, 1080};
    sf::Vector2f pos = {0, 0};

    sf::Texture TX;
    sf::RectangleShape rect;
};

class BG_parralax_Full {
public:
    std::vector<ParallaxLayer> layers;
    BG_parralax_Full(sf::RenderWindow& window, float sw, float sh);
    void addLayer(std::string file, float scrollSpeed);
    void render(Camera& camera);
    ~BG_parralax_Full();
};