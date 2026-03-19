#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include <string>
#include <vector>

class Camera;

struct Layer {
    sf::Texture TX;
    std::vector<sf::RectangleShape*> rect;

    float speed;
};

class BG_parralax_Full
{
public:
    std::vector<Layer*> layer_;

    BG_parralax_Full();
    ~BG_parralax_Full();

    void addlayer(std::string file, float speed_);
    void update(float dt, Camera& cam);
    void render(sf::RenderWindow& window);
};

