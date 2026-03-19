#include "FlottingElement.h"
#include "Pawn.h"

FlottingElement::FlottingElement(sf::RenderWindow& window, float posX_, float posY_, float sizeX_, float sizeY_, float timeMove, float speedMove, std::string image) {
    pos = { posX_, posY_ };
    size = { sizeX_, sizeY_ };
    time = timeMove;
    speed = speedMove;

    rect = new TXanimated();
    rect->load("sprite/SpriteSheet/bombnut.txt", 50, 50, pos.x, pos.y);

}

FlottingElement::~FlottingElement() {
    delete rect;
    rect = nullptr;
}

void FlottingElement::draw(sf::RenderWindow& window) {
    rect->render(window);
}

bool FlottingElement::intersept(Pawn& p)
{
    return p.pos.x < pos.x + size.x &&
        p.pos.x + p.size.x > pos.x &&
        p.pos.y < pos.y + size.y &&
        p.pos.y + p.size.y > pos.y;;
}

void FlottingElement::update(Pawn& pawn, float dt) {

    actualTimeMove += dt;

    if (moveHeight) {
        pos.y += speed * dt;
    }
    else {
        pos.y -= speed * dt;
    }

    if (actualTimeMove >= time) {
        moveHeight = !moveHeight;
        actualTimeMove = 0;
    }
    rect->update(dt);
    rect->rect.setPosition(pos);

    if (intersept(pawn)) {
        pawn.takedamage(2);
    }
}