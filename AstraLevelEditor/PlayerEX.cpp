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
    if (isInvincible) {
        IframeTimer -= dt;
        if (IframeTimer <= 0.0f) {
            isInvincible = false;
            IframeTimer = 0.0f;
        }
    }

    if (!isalive) {
        death();
    }
}

void PlayerEX::death() {
    rect.setPosition({ 200, 800 });
    hp = 1;                                
    isalive = true;
}