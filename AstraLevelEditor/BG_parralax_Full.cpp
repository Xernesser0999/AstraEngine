#include "BG_parralax_Full.h"
#include "Camera.h"

BG_parralax_Full::BG_parralax_Full() {

}

BG_parralax_Full::~BG_parralax_Full() {
    for (auto r : layer_) {
        delete r;
        r = nullptr;
    }
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
    sf::Vector2f center = cam.view->getCenter();

    for (auto& r : layer_) {
        float ox = center.x * r.speed;
        float oy = center.y * r.speed;

        // Position de snap : la tuile "centrale" la plus proche
        float snapX = std::round(ox / 1920.f) * 1920.f;
        float snapY = std::round(oy / 1080.f) * 1080.f;

        int index = 0;
        for (int y = -1; y <= 1; y++)
        {
            for (int x = -1; x <= 1; x++)
            {
                // Position monde = snap + offset de grille - déplacement parallax
                float px = (snapX + x * 1920.f) - ox + center.x;
                float py = (snapY + y * 1080.f) - oy + center.y;

                r.rect[index].setPosition({ px - 1920.f / 2.f, py - 1080.f / 2.f });
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