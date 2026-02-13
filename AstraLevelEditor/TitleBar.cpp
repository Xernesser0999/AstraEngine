#include "TitleBar.h"

TitleBar::TitleBar() {
	Bar.setPosition({ 0, 0 });
	Bar.setSize({ 1920, 30 });
	Bar.setFillColor(sf::Color(46, 46, 46));
	Quit_button(0, 0, 0, 0, "", "");
}

TitleBar::~TitleBar() {

}

void TitleBar::update(float dt) {

}

void TitleBar::render(sf::RenderWindow& window) {
	window.draw(Bar);
}