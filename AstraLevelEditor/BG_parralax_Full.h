#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include <string>
#include <vector>

class Camera;

class BG_parralax_Full
{
public:
    float scroll = 0;
    float speed;
    float speedfactor;

    sf::Vector2f size;
    sf::Vector2f pos;

    std::vector<sf::RectangleShape> rect;
    std::vector<sf::RectangleShape> rectbis;

    BG_parralax_Full(float speed_, float speedfactor_);
    ~BG_parralax_Full();

    void addlayer(std::string file);
    void update(float dt, Camera& cam);
    void render(sf::RenderWindow& window);
};

