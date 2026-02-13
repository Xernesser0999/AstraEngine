#include "Camera.h"

Camera::Camera(float ScreenX, float ScreenY, float LevelX, float LevelY) {

    ScreenSize = {ScreenX, ScreenY};
    LevelSize = {LevelX, LevelY};

    sizeC.setPosition({ 0, 0 });
    sizeC.setSize({ ScreenSize.x, ScreenSize.y });
}

void Camera::setCameraOnPlayer(Pawn& pawn) {
    pos = sizeC.getPosition();

    // Center on player
    sizeC.setPosition({
        (pawn.pos.x + pawn.size.x / 2) - ScreenSize.x / 2,
        (pawn.pos.y + pawn.size.y / 2) - ScreenSize.y / 2
        });
    
    // Lock screen in world
    if (pos.x < 0) {
        pos.x = 0;
    }
    if (pos.y < 0) {
        pos.y = 0;
    }
    if (pos.x + ScreenSize.x > LevelSize.x) {       // The camera can't leave the level
        pos.x = LevelSize.x - ScreenSize.x;         // X axis
    }
    if (pos.y + ScreenSize.y > LevelSize.y) {
        pos.y = LevelSize.y - ScreenSize.y;        // Y axis
    }
}

sf::RectangleShape Camera::worldToScreen(sf::RectangleShape& worldRect)
{
    sf::Vector2f worldPos = worldRect.getPosition();
    sf::Vector2f worldSize = worldRect.getSize();

    sf::RectangleShape screenRect;
    screenRect.setSize(worldSize);
    screenRect.setPosition({
        worldPos.x - pos.x,
        worldPos.y - pos.y
        });

    // Si tu veux garder la texture :
    screenRect.setTexture(worldRect.getTexture());

    return screenRect;
}
