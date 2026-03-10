#include "TXanimated.h"

TXanimated::TXanimated() {
	Frameloc = {0, 0};
	ActualFrame = 0;
}

TXanimated::~TXanimated() {

}

void TXanimated::load(std::string file, std::string image, float sizeX, float sizeY, float posX, float posY) {
	std::ifstream f(file);

	std::getline(f, filename);
	f >> FrameSize.x, FrameSize.y;
	f >> TotalFrame;
	f >> FrameRate;
	TotalFrame - 1;

	offset = sf::IntRect({ 0, 0 }, {FrameSize});

	TX.loadFromFile(file);

	rect.setSize({ sizeX, sizeY });
	rect.setPosition({ posX, posY });
	rect.setTexture(&TX);
	rect.setTextureRect(offset);
}

void TXanimated::update(float dt) {

	Frameloc.x += 32;
	offset = sf::IntRect({ Frameloc.x, 0 }, { 32, 32 });

	ActualFrame += 1;
	rect.setTextureRect(offset);

	if (ActualFrame == TotalFrame) {
		ActualFrame = 0;
		Frameloc.x = 0;
	}

}

void TXanimated::render(sf::RenderWindow& window) {
	window.draw(rect);
}