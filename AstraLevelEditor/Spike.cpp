#include "Spike.h"
#include "Pawn.h" 

Spike::Spike(sf::RenderWindow& window, float posX_, float posY_, float sizeX_, float sizeY_, std::string image) {

    pos = { posX_, posY_ };
    size = { sizeX_, sizeY_ };

    rect.setPosition(pos);
    rect.setSize(size);

    if (!texture.loadFromFile(image)) {
        rect.setFillColor(sf::Color::Red);
    }
    else {
        rect.setTexture(&texture);
    }
}

Spike::~Spike()
{
}

void Spike::draw(sf::RenderWindow& window)
{
    window.draw(rect);
}

bool Spike::Intersect(Pawn& p) {
    return p.pos.x < pos.x + size.x &&
        p.pos.x + p.size.x > pos.x &&
        p.pos.y < pos.y + size.y &&
        p.pos.y + p.size.y > pos.y;
}

void Spike::update(Pawn& pawn)
{
    if (Intersect(pawn)) {
        pawn.takedamage(1);
    }

}