#include "BGstatic.h"

BGstatic::BGstatic(sf::RenderWindow& window, std::string file, float sizeX, float sizeY) {
    size = {sizeX, sizeY};
    rect.setPosition({ 0, 0 });
    rect.setSize(size);

    texture.loadFromFile(file.c_str());
    rect.setTexture(&texture);
}

void BGstatic::render(sf::RenderWindow& window) {
    window.draw(rect);
}

BGstatic::~BGstatic() {

}