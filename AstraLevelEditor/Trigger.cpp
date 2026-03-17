#include "Trigger.h"
#include "Camera.h"
#include "Pawn.h"

bool Trigger::Intersect(Pawn& p) {
    return p.pos.x < pos.x + size.x &&
        p.pos.x + p.size.x > pos.x &&
        p.pos.y < pos.y + size.y &&
        p.pos.y + p.size.y > pos.y;
}

Trigger::Trigger(float posX, float posY, float sizeX, float sizeY, bool active_) {
    pos = { posX, posY };
    size = { sizeX, sizeY };

    active = active_;

    rect.setSize(size);
    rect.setPosition(pos);
    
    TX.loadFromFile("sprite/Debug/Trigger_DebugTX.png");
    rect.setTexture(&TX);
}

Trigger::~Trigger() {

}

void Trigger::update(float dt, Pawn& p) {
    if (Intersect(p) && active) {
        trigger = true;
        active = false;
        inside = true;
    }

    else {
        trigger = false;
    }

    if(!Intersect(p) && inside) {
        active = true;
        inside = false;
    }
}

void Trigger::render(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
        window.draw(rect);
    }
}