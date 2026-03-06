#include "BG_parralax_Full.h"
#include "Camera.h"

BG_parralax_Full::BG_parralax_Full(float speed_, float speedfactor_) {
	speed = speed_;
	speedfactor = speedfactor_;
}

BG_parralax_Full::~BG_parralax_Full() {
	rect.clear();
	rectbis.clear();
}

void BG_parralax_Full::addlayer(std::string file) {
	sf::RectangleShape rectangle;
	sf::Texture tx;
	
	tx.loadFromFile(file.c_str());

	rectangle.setPosition({ 0 - 1920, 0 - 1080 });
	rectangle.setSize({ 1920 * 3, 1080 * 3 });
	rectangle.setTexture(&tx);
	
	rect.push_back(rectangle);
}

void BG_parralax_Full::update(float dt, Camera& cam) {
	for (sf::RectangleShape c : rect) {
		pos = c.getPosition();
		pos = {(cam.pos.x - pos.x) /2, (cam.pos.y - pos.y) / 2 };
	}
}

void BG_parralax_Full::render(sf::RenderWindow& window) {
	for (sf::RectangleShape z : rect) {
		window.draw(z);
	}
}