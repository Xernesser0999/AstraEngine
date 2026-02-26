#include "PS_burst.h"

PS_burst::PS_burst(std::string file_, float size_, float posX, float posY, int quantity_, float fireRate_, float speed_) {
	file = file_;
    size = size_;
	pos = { posX, posY };
	quantity = quantity_;
	firerate = fireRate_;
}

PS_burst::~PS_burst() {

}

void PS_burst::update(float dt) {
    currentTime = clock.getElapsedTime().asSeconds();
    if (currentTime > lastShotTime + shotCooldown) {
        for (int z = 0; z < quantity; z++) {
            Particle.emplace_back(size, rand() % 360 + 1, lifetime, speed, pos.x, pos.y, file);
        }
        lastShotTime = currentTime;
    }
    for (auto it = Particle.begin(); it != Particle.end(); ) {
        it->update(dt);

        if (it->isalive()) {
            ++it;
        }
        else {
            it = Particle.erase(it);
        }
    }
}

void PS_burst::render(sf::RenderWindow& window, Camera& camera) {

}