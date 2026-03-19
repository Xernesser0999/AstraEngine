#include "Hud.h"
#include "Pawn.h"

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
void Hud::draw(sf::RenderWindow& window, Pawn& pawn) {
	life->draw(window, pawn);
	capacities->draw(window);
}

Life::Life(){
	posHeart = { 50, 50 };
	sizeHeart = { 80, 80 };
	heart.setSize(sizeHeart);
	luneBlanche.loadFromFile("sprite/SpriteSheet/lune_blanche.png");
	luneGrise.loadFromFile("sprite/SpriteSheet/lune_grise.png");
	heart.setTexture(&luneBlanche);
}

Life::~Life() {
}

void Life::draw(sf::RenderWindow& window, Pawn& pawn){
	for(int i = 0; i < pawn.hp; i++){
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
