#include "Camera.h"

Camera::Camera(float ScreenX, float ScreenY, float LevelX, float LevelY, float lagfactor) {
    view = new sf::View({ ScreenX / 2, ScreenY / 2 }, { ScreenX, ScreenY });
    lag = lagfactor;
    ScreenSize = { ScreenX, ScreenY };
    LevelSize = { LevelX, LevelY };

    lag = lagfactor;
}

Camera::~Camera() {
    delete view;
    view = nullptr;
}

void Camera::Update(float dt, Pawn& pawn) {
    ObjectivePos = { pawn.pos.x + pawn.size.x / 2, pawn.pos.y + pawn.size.y / 2 };

    ObjectivePos.x = std::max(ScreenSize.x / 2, std::min(ObjectivePos.x, LevelSize.x - ScreenSize.x / 2));
    ObjectivePos.y = std::max(ScreenSize.y / 2, std::min(ObjectivePos.y, LevelSize.y - ScreenSize.y / 2));

    sf::Vector2f current = view->getCenter();
    current.x += (ObjectivePos.x - current.x) * lag * dt;
    current.y += (ObjectivePos.y - current.y) * lag * dt;

    view->setCenter(current);
    pos = current;
}