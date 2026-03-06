#include "BG_parralax_Full.h"
#include "Camera.h"

BG_parralax_Full::BG_parralax_Full() {

}

BG_parralax_Full::~BG_parralax_Full() {
	layer_.clear();
}

void BG_parralax_Full::addlayer(std::string file, float speed_) {
	layer_.emplace_back();
	Layer& l = layer_.back();

	l.speed = speed_;
	l.TX.loadFromFile(file);

	for (int i = 0; i < 9; i++)
	{
		sf::RectangleShape r;
		r.setSize({ 1920, 1080 });
		r.setTexture(&l.TX);
		l.rect.push_back(r);
	}

}

void BG_parralax_Full::update(float dt, Camera& cam) {
	for (auto& r : layer_) {
		float ox = cam.pos.x * r.speed;
		float oy = cam.pos.y * r.speed;

		// X
		while (ox < 0) {
			ox += 1920.f;
		}
		while (ox >= 1920.f) {
			ox -= 1920.f;
		}
		// Y
		while (oy < 0) {
			oy += 1080.f;
		}
		while (oy >= 1080.f) {
			oy -= 1080.f;
		}

		int index = 0;
		for (int y = -1; y <= 1; y++)
		{
			for (int x = -1; x <= 1; x++)
			{
				r.rect[index].setPosition({ x * 1920 - ox, y * 1080 - oy });
				index++;
			}
		}
	}
}

void BG_parralax_Full::render(sf::RenderWindow& window) {
	for (auto& z : layer_) {
		for (auto& x : z.rect) {
			window.draw(x);
		}
	}
}