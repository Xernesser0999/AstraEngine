#include "PlayerEX.h"

PlayerEX::PlayerEX( sf::RenderWindow& window, int hp_, float posX_, float posY_, float sizeX_, float sizeY_, float power_jump_, float speed_, std::string image, float Iframe_, StateMachine& state_
) : Pawn(window, hp_, posX_, posY_, sizeX_, sizeY_, power_jump_, speed_, image, Iframe_, state_){
}

void PlayerEX::update(float dt, const std::vector<Collider*>& colliders) {

    // |\=-_
    // STATE MACHINE drives input + velocityX + jump initiation
    state.update(dt, *this);

    // |\=-_
    // HORIZONTAL PHYSICS + COLLISION
    pos.x += velocityX * dt;
    Pawn::collisionHori(colliders);

    // |\=-_
    // VERTICAL PHYSICS + COLLISION
    velocityY += 2000.0f * dt;     // gravity
    pos.y += velocityY * dt;
    Pawn::collisionVert(colliders);

    // Sync rect
    rect.setPosition({ pos.x, pos.y });

    // |\=-_
    // IFRAME TIMER
    if (isInvincible) {
        IframeTimer -= dt;
        if (IframeTimer <= 0.0f) {
            isInvincible = false;
            IframeTimer = 0.0f;
        }
    }

    // |\=-_
    // DEATH
    if (!isalive) death();
}

void PlayerEX::death() {
    rect.setPosition({ 200, 800 });
    hp = 1;
    isalive = true;
}