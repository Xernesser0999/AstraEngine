#pragma once
#include <filesystem>
#include <Sfml/Graphics.hpp>

class Pawn;
class Spike
{
public:
    sf::Vector2f pos;
    sf::Vector2f size;

    sf::RectangleShape rect;
    sf::Texture texture;

    Spike() = default;
    Spike(sf::RenderWindow& window, float posX_, float posY_, float sizeX_, float sizeY_, std::string image);
    ~Spike();

    void draw(sf::RenderWindow& window);

    sf::RectangleShape rectangle;

    void update(Pawn& pawn);

    bool Intersect(Pawn& p);
};