#include "BGstatic.h"
#include "Camera.h"

BGstatic::BGstatic(sf::RenderWindow& window, std::string file, float sizeX, float sizeY) {
    size = {sizeX * 50, sizeY * 50};
    rect.setPosition({ 0, 0 });
    rect.setSize(size);

    texture.loadFromFile(file.c_str());
    rect.setTexture(&texture);
}

void BGstatic::render(sf::RenderWindow& window) {
    window.draw(rect);
}
void BGstatic::renderCam(sf::RenderWindow& window, Camera& camera) {
    sf::RectangleShape screenRect = camera.worldToScreen(rect);
    window.draw(screenRect);
}

BGstatic::~BGstatic() {

}