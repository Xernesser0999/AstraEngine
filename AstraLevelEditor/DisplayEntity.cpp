#include "DisplayEntity.h"
#include "Camera.h"

DisplayEntity::DisplayEntity(sf::RenderWindow& window, float posX_, float posY_, float sizeX_, float sizeY_, std::string image) {

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

void DisplayEntity::update(float dt) {

}

void DisplayEntity::render(sf::RenderWindow& window, Camera& camera) {
	window.draw(rect);
}

DisplayEntity::~DisplayEntity() {
}