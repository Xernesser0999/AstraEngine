#include "PS_particle.h"
#include "Camera.h"

PS_particle::PS_particle(float size_, float angle_, float lifetime_, float speed_, float posX_, float posY_, std::string file) {
	size = {size_, size_};
	pos = { posX_, posY_ };
	angle = angle_;
	lifetime = lifetime_;
	speed = speed_;

	TX.loadFromFile(file.c_str());

	rect.setSize(size);
	rect.setPosition(pos);
	rect.setTexture(&TX);
}

PS_particle::~PS_particle() {

}

void PS_particle::update(float dt) {
	float rad = angle * 3.1415 / 180;

	pos.x += cos(rad) * speed * dt;
	pos.y += sin(rad) * speed * dt;
	rect.setPosition(pos);

	lifetime -= dt;
}

void PS_particle::render(sf::RenderWindow& window, Camera& camera) {
	sf::RectangleShape screenRect = camera.worldToScreen(rect);
	window.draw(screenRect);
}

bool PS_particle::isalive() const {
	return lifetime > 0;
}