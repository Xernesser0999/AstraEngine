#include "Pnj.h"
#include "Pawn.h"

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

void Pnj::updatePnj(float dt, Pawn& pawn){ //rajouter un parametre d'une capacite
	trig->update(dt, pawn);
	if (trig->inside && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
		if (!capacityGiven) {
			//lance fonction pour dialogue a
			//unloco la capacite en parametre
			std::cout << "Trigger" << std::endl;
			capacityGiven = true;
		}
		else if (capacityGiven) {
			std::cout << "Done" << std::endl;
			//lance fonction pour dialogue b
		}
	}
}

void Pnj::renderPnj(sf::RenderWindow& window){
	window.draw(rect);
	trig->render(window);
}
