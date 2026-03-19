#include "PlayerEX.h"

PlayerEX::PlayerEX( sf::RenderWindow& window, int hp_, float posX_, float posY_, float sizeX_, float sizeY_, float power_jump_, float speed_, std::string image, float Iframe_, StateMachine& state_
) : Pawn(window, hp_, posX_, posY_, sizeX_, sizeY_, power_jump_, speed_, image, Iframe_, state_){
}

void PlayerEX::update(float dt, const std::vector<Collider*>& colliders) {

    state.update(dt, *this);

    pos.x += velocityX * dt;
    Pawn::collisionHori(colliders);

    velocityY += Gravity * dt;     
    pos.y += velocityY * dt;
    Pawn::collisionVert(colliders);

    rect.setPosition({ pos.x, pos.y });
    std::cout << pos.x << ", " << pos.y << std::endl;
    system("CLS");
    if (isInvincible) {
        IframeTimer -= dt;
        if (IframeTimer <= 0.0f) {
            isInvincible = false;
            IframeTimer = 0.0f;
        }
    }

    if (isalive == false) {
        death();
    }
}

void PlayerEX::death() {
    pos = { Rez };
    //pos = { 100, 2650 };
    hp = 3;
    isalive = true;
}