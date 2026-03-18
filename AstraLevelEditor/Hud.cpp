#include "Hud.h"

Hud::Hud() {
	life = new Life();
	capacities = new Capacities();
}

Hud::~Hud() {
	delete life;
	delete capacities;
	life = nullptr;
	capacities = nullptr;
}
void Hud::draw(sf::RenderWindow& window, int nbHeart) {
	life->draw(window, nbHeart);
	capacities->draw(window);
}

Life::Life(){
	posHeart = { 50, 50 };
	sizeHeart = { 80, 80 };
	heart.setSize(sizeHeart);
	luneBlanche.loadFromFile("sprite/SpriteSheet/lune_blanche.png");
	heart.setTexture(&luneBlanche);
}

Life::~Life() {
}

void Life::draw(sf::RenderWindow& window, int nbHeart){
	for(int i = 0; i < nbHeart; i++){
		heart.setPosition({ posHeart.x + (i * 100), posHeart.y });
		window.draw(heart);
	}
}

Capacities::Capacities(){
	posCapacity = { 1820, 1000 };
	sizeCapacity = { 50, 50 };
	capacity.setPosition(posCapacity);
	capacity.setSize(sizeCapacity);
	capacity.setFillColor(sf::Color::Blue);
}

Capacities::~Capacities() {
}

void Capacities::draw(sf::RenderWindow& window) {
	window.draw(capacity);
}
