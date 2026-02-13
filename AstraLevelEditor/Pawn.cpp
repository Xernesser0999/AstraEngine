#include "Pawn.h"
#include "Camera.h"

Pawn::Pawn(sf::RenderWindow& window, int hp_, float posX_, float posY_, float sizeX_, float sizeY_, float power_jump_, float speed_, std::string image, float Iframe_) {
    hp = hp_;

    pos = {posX_, posY_};
    size = { sizeX_, sizeY_ };

    rect.setPosition({ posX_, posY_ });
    rect.setSize({sizeX_, sizeY_});

    power_jump = power_jump_;
    speed = speed_;

    Iframe = Iframe_;
    IframeTimer = Iframe;

    // |\=-_
    // TEXTURE LOADING
    texture.loadFromFile(image.c_str());
    rect.setTexture(&texture);
}

void Pawn::update(float dt, const std::vector<Collider*>& colliders) {

}

void Pawn::render(sf::RenderWindow& window, Camera* camera) {
    sf::RectangleShape screenRect = rect;

    if (camera) {                                           // If a camera is linked to the player
        screenRect = camera->worldToScreen(rect);           // Make the cam follow him
    }

    // Changing texture depending on is direction
        if (direction == 1) {
        }
        else {
        }

        //Render here
        //SDL_RenderTextureRotated(renderer, texture, nullptr, &screenRect, 0.0f, nullptr, flip);

    window.draw(screenRect);
}

bool Pawn::intersects(const sf::FloatRect& a, const sf::FloatRect& b)
{
    return a.position.x < b.position.x + b.size.x &&
        a.position.x + a.size.x > b.position.x &&
        a.position.y < b.position.y + b.size.y &&
        a.position.y + a.size.y > b.position.y;
}

void Pawn::collisionHori(const std::vector<Collider*>& colliders) {
    for (auto c : colliders) {                                                          // For every collider
        //if (!SDL_HasRectIntersectionFloat(&rect, &c->rect))                             // If there are no intersection
        //    continue;                                                                   // Then do nothing

        float playerTop = pos.y;                                                       // Get the top of the player rect
        float playerBottom = pos.y + size.y;                                           // Get the bottom of the player rect
        float blockTop = c->pos.y;                                                     // Get the top of the collider rect
        float blockBottom = c->pos.y + c->size.y;                                      // Get the bottom of the collider rect

        bool verticalOverlap = playerBottom > blockTop && playerTop < blockBottom;      // Check the type of the collision (avoid doing a vertical collision in this case)
        if (!verticalOverlap)                                                           // If it is a vertical collision
            continue;                                                                   // Then stop doing horizontal collision

        float playerLeft = pos.x;                                                      // Get the Left side of the player rect
        float playerRight = pos.x + size.x;                                            // Get the Right side of the player rect
        float blockLeft = c->pos.x;                                                    // Get the Left side of the collider rect
        float blockRight = c->pos.x + c->size.x;                                       // Get the Right side of the collider rect

        // Apply the collision
        if (velocityX > 0) {
            pos.x = blockLeft - size.x;
        }
        else if (velocityX < 0) {
            pos.x = blockRight;
        }

        velocityX = 0;
    }
}
void Pawn::collisionVert(const std::vector<Collider*>& colliders) {
    isGrounded = false;

    for (auto c : colliders) {
        //if (!SDL_HasRectIntersectionFloat(&rect, &c->rect))
        //    continue;
        sf::FloatRect playerRect({ pos.x, pos.y }, { size.x, size.y });
        sf::FloatRect blockRect({ c->pos.x, c->pos.y }, { c->size.x, c->size.y });

        if (!intersects(playerRect, blockRect))
            continue;


        float playerLeft = pos.x;
        float playerRight = pos.x + size.x;
        float blockLeft = c->pos.x;
        float blockRight = c->pos.x + c->size.x;

        bool horizontalOverlap = playerRight > blockLeft && playerLeft < blockRight;
        if (!horizontalOverlap)
            continue;

        float playerTop = pos.y;
        float playerBottom = pos.y + size.y;
        float blockTop = c->pos.y;
        float blockBottom = c->pos.y + c->size.y;

        if (velocityY > 0) {
            pos.y = blockTop - size.y;
            isGrounded = true;
        }
        else if (velocityY < 0) {
            pos.y = blockBottom;
        }

        velocityY = 0;
    }
}

void Pawn::takedamage(int dmg) {
    if (!isInvincible) {
        hp -= dmg;

        isInvincible = true;
        IframeTimer = Iframe;
    }
    if (hp <= 0) {
        isalive = false;
    }
}

void Pawn::death() {

}

Pawn::~Pawn() {
}