#include "Pnj.h"

Pnj::Pnj(float posX, float posY, float sizeX, float sizeY, std::string image){
	trig = new Trigger(posX, posY, sizeX, sizeY, true);
	rect.setPosition({ posX, posY });
	rect.setSize({ sizeX, sizeY });
	texture.loadFromFile(image.c_str());
	rect.setTexture(&texture);

}

Pnj::~Pnj(){
	delete trig;
	trig = nullptr;	
}

void Pnj::updatePnj(float dt){
	if (trig->trigger && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
		std::cout << "Trigger" << std::endl;
		trig->active = false;
	}
}

void Pnj::renderPnj(sf::RenderWindow& window){
	window.draw(rect);
	trig->render(window, *new Camera());
}
