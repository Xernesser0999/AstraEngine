#include "BlobEnemy.h"

BlobEnemy::BlobEnemy(float posX, float posY, float timeMove, float speedMove){
	pos = { posX, posY };
	size = { 50, 50 };
	speed = speedMove;
	time = timeMove;	
	rect = new TXanimated();
	rect->load("sprite/SpriteSheet/BobGoingRight.txt", 50, 50, pos.x, pos.y);
}

BlobEnemy::~BlobEnemy(){
}

void BlobEnemy::update(float dt){
	actualTimeMove += dt;

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
