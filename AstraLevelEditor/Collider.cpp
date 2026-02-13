#include "Collider.h"
#include "Camera.h"

Collider::Collider(sf::RenderWindow& window, float posX_, float posY_, float sizeX_, float sizeY_, std::string image) {

	pos = {posX_, posY_};
	size = { sizeX_, sizeY_ };

	rect.setPosition(pos);
	rect.setSize(size);

	if (!texture.loadFromFile(image)) {
		rect.setFillColor(sf::Color::Magenta);
	}
	else {
		rect.setTexture(&texture);
	}
}

void Collider::update(float dt) {

}

void Collider::render(sf::RenderWindow& window, Camera& camera) {
	sf::RectangleShape screenRect = camera.worldToScreen(rect);
	window.draw(screenRect);
}

Collider::~Collider() {
}