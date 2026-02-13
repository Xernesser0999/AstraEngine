#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include "Pawn.h"

class Camera
{
public:
    sf::RectangleShape sizeC;
    sf::Vector2f ScreenSize;
    sf::Vector2f LevelSize;
    sf::Vector2f pos;

    sf::Vector2f worldPos;
    sf::Vector2f worldSize;

public:

    Camera(float ScreenX, float ScreenY, float LevelX, float LevelY);

    void setCameraOnPlayer(Pawn& pawn);
    sf::RectangleShape worldToScreen(sf::RectangleShape& worldRect);
};