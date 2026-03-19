#include "BlobEnemy.h"
#include "Pawn.h"

BlobEnemy::BlobEnemy(float posX, float posY, float SizeX, float SizeY, float timeMove, float speedMove){
	pos = { posX, posY };
	size = { SizeX, SizeY };
	speed = speedMove;
	time = timeMove;

	rect = new TXanimated();
	rect->load("sprite/SpriteSheet/BobGoingRight.txt", 50, 50, pos.x, pos.y);
}

BlobEnemy::~BlobEnemy(){
	delete rect;
	rect = nullptr;
}

bool BlobEnemy::Intersect(Pawn& p) {
	return p.pos.x < pos.x + size.x &&
		p.pos.x + p.size.x > pos.x &&
		p.pos.y < pos.y + size.y &&
		p.pos.y + p.size.y > pos.y;
}


void BlobEnemy::update(float dt, Pawn& p){
	actualTimeMove += dt;

	if (Intersect(p)) {
		p.takedamage(1);
	}

	if (moveRight) {
		pos.x += speed * dt;
	}
	else {
		pos.x -= speed * dt;
	}

	if(actualTimeMove >= time) {
		if (moveRight) {
			rect->load("sprite/SpriteSheet/BobGoingLeft.txt", 50, 50, pos.x, pos.y);
		}
		else {
			rect->load("sprite/SpriteSheet/BobGoingRight.txt", 50, 50, pos.x, pos.y);
		}
		moveRight = !moveRight;
		actualTimeMove = 0;
	}
	rect->update(dt);
	rect->rect.setPosition(pos);
}

void BlobEnemy::render(sf::RenderWindow& window){
	rect->render(window);
}	
