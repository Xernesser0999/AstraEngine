#include "Camera.h"

//#include <cmath>

Camera::Camera(float ScreenX, float ScreenY, float LevelX, float LevelY, float lagfactor) {

    ScreenSize = {ScreenX, ScreenY};
    LevelSize = {LevelX, LevelY};

    sizeC.setPosition({ 0, 0 });
    sizeC.setSize({ ScreenSize.x, ScreenSize.y });

    lag = lagfactor;
}

void Camera::setCameraOnPlayer(Pawn& pawn) {
    ObjectivePos.x = (pawn.pos.x + pawn.size.x / 2) - ScreenSize.x / 2;
    ObjectivePos.y = (pawn.pos.y + pawn.size.y / 2) - ScreenSize.y / 2;

    if (ObjectivePos.x < 0) {
        ObjectivePos.x = 0;
    }
    if (ObjectivePos.x > LevelSize.x - ScreenSize.x) {
        ObjectivePos.x = LevelSize.x - ScreenSize.x;
    }

    pos.x += (ObjectivePos.x - pos.x) * lag;
    pos.y += (ObjectivePos.y - pos.y) * lag;

    sizeC.setPosition(pos);
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

    screenRect.setTexture(worldRect.getTexture());
    return screenRect;
}
