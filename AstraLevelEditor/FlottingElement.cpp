#include "FlottingElement.h"
#include "Pawn.h"

FlottingElement::FlottingElement(sf::RenderWindow& window, float posX_, float posY_, float sizeX_, float sizeY_, float timeMove, float speedMove, std::string image) {
    pos = { posX_, posY_ };
    size = { sizeX_, sizeY_ };
    time = timeMove;
    speed = speedMove;

    rect.setPosition(pos);
    rect.setSize(size);

    if (!texture.loadFromFile(image)) {
        rect.setFillColor(sf::Color::Red);
    }
    else {
        rect.setTexture(&texture);
    }
}

FlottingElement::~FlottingElement()
{
}

void FlottingElement::draw(sf::RenderWindow& window) {
    window.draw(rect);
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
    rect.setPosition(pos);

    if (intersept(pawn)) {
        pawn.takedamage(2);
    }
}