#include "SavePoint.h"

#include "PlayerEX.h"
#include "Global.h"

SavePoint::SavePoint(float posX, float posY, int actualLevel) {
	rect.setPosition({ posX, posY });
	rect.setSize({ 100, 50 });

	TX.loadFromFile("sprite/Debug/Savepoint.png");
	rect.setTexture(&TX);

	trig = new Trigger(
		posX,
		posY,
		100,
		50,
		true
	);

	RezPos = {posX + 25, posY};

	actual = actualLevel;
}

SavePoint::~SavePoint() {
	delete trig;
	trig = nullptr;
}

void SavePoint::update(float dt, Pawn& pawn, Global& glob) {
	trig->update(dt, pawn);
	if (trig->inside && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
		pawn.Rez = RezPos;
		glob.save(pawn, actual);
	}
	trig->active = true;
}

void SavePoint::render(sf::RenderWindow& window) {
	trig->render(window);
	window.draw(rect);
}