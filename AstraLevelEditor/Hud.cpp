#include "Hud.h"
#include "Pawn.h"
#include "Global.h"

Hud::Hud() {
	life = new Life();
	dash = new DashCapa();
	db = new DbCapa();
	floating = new FloatingCapa();
}

Hud::~Hud() {
	delete life;
	delete dash;
	delete db;
	delete floating;

	life = nullptr;
	dash = nullptr;
	db = nullptr;
	floating = nullptr;
}
void Hud::draw(sf::RenderWindow& window, Pawn& pawn, Global& glob) {
	life->draw(window, pawn);
	if (glob.DBUnlock) {
		db->draw(window, glob);
	}
	if (glob.FloatUnlock) {
		floating->draw(window, glob);
	}
	dash->draw(window, glob);
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

void Life::draw(sf::RenderWindow& window, Pawn& pawn){
	for(int i = 0; i < pawn.hp; i++){
		heart.setPosition({ posHeart.x + (i * 100), posHeart.y });
		window.draw(heart);
	}
}

DashCapa::DashCapa(){
	posCapacity = { 1820, 1000 };
	sizeCapacity = { 50, 50 };
	capacity.setSize(sizeCapacity);
	capacity.setPosition(posCapacity);
	dash.loadFromFile("sprite/SpriteSheet/dash.png");
	capacity.setTexture(&dash);
}

DashCapa::~DashCapa() {
}

void DashCapa::draw(sf::RenderWindow& window, Global& glob) {
	window.draw(capacity);
}

DbCapa::DbCapa(){
	posCapacity = { 1760, 1000 };
	sizeCapacity = { 50, 50 };
	capacity.setSize(sizeCapacity);
	capacity.setPosition(posCapacity);
	db.loadFromFile("sprite/SpriteSheet/doublejump.png");
	capacity.setTexture(&db);
}

DbCapa::~DbCapa() {
}

void DbCapa::draw(sf::RenderWindow& window, Global& glob) {
	window.draw(capacity);
}

FloatingCapa::FloatingCapa(){
	posCapacity = { 1700, 1000 };
	sizeCapacity = { 50, 50 };
	capacity.setSize(sizeCapacity);
	capacity.setPosition(posCapacity);
	floating.loadFromFile("sprite/SpriteSheet/float.png");
	capacity.setTexture(&floating);
}

FloatingCapa::~FloatingCapa() {
}

void FloatingCapa::draw(sf::RenderWindow& window, Global& glob) {
	window.draw(capacity);
}
