#include "GUI_button.h"

GUI_button::GUI_button(float posX_, float posY_, float sizeX, float sizeY, std::string file, std::string hover) {
	pos = { posX_, posY_ };
	size = { sizeX, sizeY };

	TX = new sf::Texture();
	TX->loadFromFile(file);
	TX2 = new sf::Texture();
	TX2->loadFromFile(hover);

	rectangle = new sf::RectangleShape(size);
	rectangle->setPosition(pos);
	rectangle->setTexture(TX);
}

bool GUI_button::hovered(sf::RenderWindow& window) {
	sf::Vector2i pos2 = sf::Mouse::getPosition(window);
	int x = pos2.x;
	int y = pos2.y;

	if (x >= pos.x && x < pos.x + size.x && y >= pos.y && y < pos.y + size.y) {
		rectangle->setTexture(TX2);
		return true;
	}
	else {
		rectangle->setTexture(TX);
		return false;
	}
}

bool GUI_button::clicked(sf::RenderWindow& window) {
	sf::Vector2i pos2 = sf::Mouse::getPosition(window);
	int x = pos2.x;
	int y = pos2.y;

	if (x >= pos.x && x < pos.x + size.x && y >= pos.y && y < pos.y + size.y) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			return true;
		}
	}
	else {
		return false;
	}
}

void GUI_button::render(sf::RenderWindow& window) {
	window.draw(*rectangle);
}

GUI_button::~GUI_button() {
	TX = nullptr;
	TX2 = nullptr;
	rectangle = nullptr;
	delete TX;
	delete TX2;
	delete rectangle;
}