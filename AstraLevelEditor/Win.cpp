#include "Win.h"

Win::Win() {
	rect.setPosition({ 0, 0 });
	rect.setSize({ 1920, 1080 });

	TX.loadFromFile("sprite/Menu/win.png");
}

Win::~Win() {

}

void Win::render(sf::RenderWindow& window) {
	window.draw(rect);
}