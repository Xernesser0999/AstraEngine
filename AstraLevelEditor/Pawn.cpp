#include "Pawn.h"
#include "Camera.h"

Pawn::Pawn(sf::RenderWindow& window, int hp_, float posX_, float posY_, float sizeX_, float sizeY_, float power_jump_, float speed_, std::string image, float Iframe_, StateMachine& state_ ) : state(state_)
{
    hp = hp_;
    pos = {posX_, posY_};
    size = { sizeX_, sizeY_ };

    rect.setPosition({ posX_, posY_ });
    rect.setSize({sizeX_, sizeY_});

    power_jump = power_jump_;
    speed = speed_;

    Iframe = Iframe_;
    IframeTimer = Iframe;

    texture.loadFromFile(image.c_str());
    rect.setTexture(&texture);
}

void Pawn::update(float dt, const std::vector<Collider*>& colliders) {

}

void Pawn::render(sf::RenderWindow& window) {
    window.draw(rect);
}

bool Pawn::intersects(const sf::FloatRect& a, const sf::FloatRect& b) {
    return a.position.x < b.position.x + b.size.x &&
        a.position.x + a.size.x > b.position.x &&
        a.position.y < b.position.y + b.size.y &&
        a.position.y + a.size.y > b.position.y;
}

void Pawn::collisionHori(const std::vector<Collider*>& colliders) {
    for (auto c : colliders) {                                                          
        sf::FloatRect playerRect({ pos.x, pos.y }, { size.x, size.y });
        sf::FloatRect blockRect({ c->pos.x, c->pos.y }, { c->size.x, c->size.y });
        if (!intersects(playerRect, blockRect))
            continue;

        float playerTop = pos.y;                                                      
        float playerBottom = pos.y + size.y;                                          
        float blockTop = c->pos.y;                                                    
        float blockBottom = c->pos.y + c->size.y;                                     

        bool verticalOverlap = playerBottom > blockTop && playerTop < blockBottom;    
        if (!verticalOverlap)                                                         
            continue;

        float playerLeft = pos.x;
        float playerRight = pos.x + size.x;
        float blockLeft = c->pos.x;
        float blockRight = c->pos.x + c->size.x;

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
            isDoubleJumping = false;
        }
        else if (velocityY < 0) {
            pos.y = blockBottom;
        }

        velocityY = 0;
    }
}

void Pawn::takedamage(int dmg) {
    hp -= dmg;
    if (hp <= 0) {
        isalive = false;
    }
}

void Pawn::death() {}

Pawn::~Pawn() {}