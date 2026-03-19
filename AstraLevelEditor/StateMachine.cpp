#include "StateMachine.h"
#include "Pawn.h"  

StateMachine::StateMachine(IState* startState) : currentState(startState) {}

void StateMachine::update(float dt, Pawn& pawn)
{
	currentState->update(dt, pawn);
	IState* next = currentState->nextState;
	if (next != nullptr && next != currentState)
	{
		delete currentState;
		currentState = next;
		currentState->nextState = nullptr;
	}
}

StateMachine::~StateMachine()
{
	delete currentState;
	currentState = nullptr;
}

static bool pressLeft()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
}
static bool pressRight()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
}

static bool pressJump()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}

static bool pressShift()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift);
}

IdleStateRight::IdleStateRight(Pawn& pawn) {
    rect = new TXanimated();
    rect->load("sprite/SpriteSheet/idleRight.txt", 70, 97, pawn.pos.x, pawn.pos.y);
}

void IdleStateRight::update(float dt, Pawn& pawn) {
    pawn.velocityX = 0;
    pawn.Gravity = 4000;
	pawn.cooldownTimer -= dt;
    rect->update(dt);
    rect->rect.setPosition(pawn.pos);

    if (!pawn.isGrounded) {
        if (pawn.direction == 0) {
            nextState = new FallingRight(pawn);
        }
        else {
            nextState = new FallingLeft(pawn);
        }
        return;
    }
    if (pressLeft()) {
        nextState = new MovingLeftState(pawn);
        return;
    }
    if (pressRight()) {
        nextState = new MovingRightState(pawn);
        return;
    }
    if (pressJump() && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.isGrounded = false;
        pawn.isJumping = true;
        pawn.isInpuConsume = true;
        nextState = new JumpingRightState(pawn);
        return;
    }
    if (!pressJump()) {
        pawn.isInpuConsume = false;
    }
    
}

void IdleStateRight::render(sf::RenderWindow& window){
    rect->render(window);
}

IdleStateLeft::IdleStateLeft(Pawn& pawn) {
    rect = new TXanimated();
    rect->load("sprite/SpriteSheet/idleLeft.txt", 70, 97, pawn.pos.x, pawn.pos.y);
}

void IdleStateLeft::update(float dt, Pawn& pawn) {
    pawn.velocityX = 0;
    pawn.Gravity = 4000;
	pawn.cooldownTimer -= dt;
    rect->update(dt);
    rect->rect.setPosition(pawn.pos);

    if (!pawn.isGrounded) {
        if (pawn.direction == 0) {
            nextState = new FallingRight(pawn);
        }
        else {
            nextState = new FallingLeft(pawn);
        }
        return;
    }
    if (pressLeft()) {
        nextState = new MovingLeftState(pawn);
        return;
    }
    if (pressRight()) {
        nextState = new MovingRightState(pawn);
        return;
    }
    if (pressJump() && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.isGrounded = false;
        pawn.isJumping = true;
        pawn.isInpuConsume = true;
        nextState = new JumpingRightState(pawn);
        return;
    }
    if (!pressJump()) {
        pawn.isInpuConsume = false;
    }
}

void IdleStateLeft::render(sf::RenderWindow& window){
	rect->render(window);
}

MovingLeftState::MovingLeftState(Pawn& pawn) {
    rect = new TXanimated();
    rect->load("sprite/SpriteSheet/runLeft.txt", 70, 97, pawn.pos.x, pawn.pos.y);
}

void MovingLeftState::update(float dt, Pawn& pawn)
{
	pawn.velocityX = -pawn.speed;
	pawn.direction = 1;
	pawn.cooldownTimer -= dt;
    rect->update(dt);
    rect->rect.setPosition(pawn.pos);

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}

	if (!pawn.isGrounded) {
		nextState = new FallingLeft(pawn);
		return;
	}
	if (pressJump() && !pawn.isInpuConsume)
	{
		pawn.velocityY = -pawn.power_jump;
		pawn.isGrounded = false;
		pawn.isJumping = true;
		pawn.isInpuConsume = true;
		nextState = new JumpingLeftState(pawn);
		return;
	}
	if (!pressLeft() && !pressRight()) {
		nextState = new IdleStateLeft(pawn);
		return;
	}
	if (pressRight()) {
		nextState = new MovingRightState(pawn);
		return;
	}
	if (pressShift()) {
		nextState = new DashingLeft(pawn);
		return;
	}
}

void MovingLeftState::render(sf::RenderWindow& window) {
	rect->render(window);
}

MovingRightState::MovingRightState(Pawn& pawn) {
	rect = new TXanimated();
	rect->load("sprite/SpriteSheet/runRight.txt", 70, 97, pawn.pos.x, pawn.pos.y);
}

void MovingRightState::update(float dt, Pawn& pawn) {
	pawn.velocityX = pawn.speed;
	pawn.direction = 0;
	pawn.cooldownTimer -= dt;
    rect->update(dt);
	rect->rect.setPosition(pawn.pos);   

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}

	if (!pawn.isGrounded) {
		nextState = new FallingRight(pawn);
		return;
	}
	if (pressJump() && !pawn.isInpuConsume) {
		pawn.velocityY = -pawn.power_jump;
		pawn.isGrounded = false;
		pawn.isJumping = true;
		pawn.isInpuConsume = true;
		nextState = new JumpingRightState(pawn);
		return;
	}
	if (!pressLeft() && !pressRight()) {
		nextState = new IdleStateRight(pawn);
		return;
	}
	if (pressLeft()) {
		nextState = new MovingLeftState(pawn);
		return;
	}
	if (pressShift()) {
		nextState = new DashingRight(pawn);
		return;
	}
}

void MovingRightState::render(sf::RenderWindow& window) {
	rect->render(window);   
}

JumpingLeftState::JumpingLeftState(Pawn& pawn) {
    rect = new TXanimated();
    rect->load("sprite/SpriteSheet/jumpLeft.txt", 70, 97, pawn.pos.x, pawn.pos.y);
}

void JumpingLeftState::update(float dt, Pawn& pawn) {
    rect->update(dt);
    rect->rect.setPosition(pawn.pos);
    if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
        pawn.direction = 1;
    }
    else if (pressRight()) {
        nextState = new JumpingRightState(pawn);
    }
    else {
        pawn.velocityX = 0;
    }

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume && pawn.canDB) {
        pawn.Gravity = 4000;
        pawn.velocityY = -pawn.power_jump;
        pawn.isDoubleJumping = true;
        if (pawn.isGrounded) {
            pawn.isJumping = false;
            pawn.isDoubleJumping = false;
        }
        pawn.isInpuConsume = true;
    }

	if (pressShift()) {
		nextState = new DashingLeft(pawn);
		return;
	}

	if (pawn.velocityY >= 0) {
		nextState = new FallingLeft(pawn);
		return;
	}

	if (pawn.isGrounded) {
		pawn.isJumping = false;
		pawn.isDoubleJumping = false;
		nextState = new IdleStateLeft(pawn);
		return;
	}
}

void JumpingLeftState::render(sf::RenderWindow& window) {
    rect->render(window);
}

JumpingRightState::JumpingRightState(Pawn& pawn) {
    rect = new TXanimated();
    rect->load("sprite/SpriteSheet/jumpRight.txt", 70, 97, pawn.pos.x, pawn.pos.y);
}

void JumpingRightState::update(float dt, Pawn& pawn) {
    rect->update(dt);
    rect->rect.setPosition(pawn.pos);
    if (pressLeft()) {
        nextState = new JumpingLeftState(pawn);
    }
    else if (pressRight()) {
        pawn.velocityX = pawn.speed;
        pawn.direction = 0;
    }
    else {
        pawn.velocityX = 0;
	}
	if (pressRight()) {
		pawn.velocityX = pawn.speed;
		pawn.direction = 0;
	}
	else {
		pawn.velocityX = 0;
	}

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}
    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume && pawn.canDB) {
        pawn.Gravity = 4000;
        pawn.velocityY = -pawn.power_jump;
        pawn.isDoubleJumping = true;
		if (pawn.isGrounded) {
			pawn.isJumping = false;
			pawn.isDoubleJumping = false;
		}
		pawn.isInpuConsume = true;
	}

	if (pressShift()) {
		nextState = new DashingRight(pawn);
		return;
	}

	if (pawn.velocityY >= 0) {
		nextState = new FallingRight(pawn);
		return;
	}

	if (pawn.isGrounded) {
		pawn.isJumping = false;
		pawn.isDoubleJumping = false;
		nextState = new IdleStateRight(pawn);
		return;
	}
}

void JumpingRightState::render(sf::RenderWindow& window) {
    rect->render(window);
}

FallingLeft::FallingLeft(Pawn& pawn) {}

void FallingLeft::update(float dt, Pawn& pawn) {
	pawn.isJumping = true;

	if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
        pawn.direction = 1;
    }
    else if (pressRight()) {
		nextState = new FallingRight(pawn);
    }
    else {
        pawn.velocityX = 0;
    }

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume && pawn.canDB) {
        pawn.velocityY = -pawn.power_jump;
        pawn.Gravity = 4000;
        pawn.isDoubleJumping = true;
        if (pawn.isGrounded) {
            pawn.isJumping = false;
            pawn.isDoubleJumping = false;
        }
        pawn.isInpuConsume = true;
        nextState = new JumpingLeftState(pawn);
        return;
    }
    
    if (pressShift()) {
        nextState = new DashingLeft(pawn);
        return;
    }

    if (pressJump() && pawn.canFloat) {
        nextState = new FlottingLeft(pawn);
        return;
    }

    if (pawn.isGrounded) {
        pawn.isJumping = false;
        pawn.isDoubleJumping = false;
        nextState = new IdleStateLeft(pawn);
        return;
    }
}

void FallingLeft::render(sf::RenderWindow& window) {
}

FallingRight::FallingRight(Pawn& pawn) {}

void FallingRight::update(float dt, Pawn& pawn) {
	pawn.isJumping = true;

    if (pressLeft()) {
        nextState = new FallingLeft(pawn);
    }
    else if (pressRight()) {
        pawn.velocityX = pawn.speed;
        pawn.direction = 0;
    }
    else {
        pawn.velocityX = 0;
    }

    if (!pressJump()) {
        pawn.isInpuConsume = false;
    }

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume && pawn.canDB) {
        pawn.velocityY = -pawn.power_jump;
        pawn.Gravity = 4000;
        pawn.isDoubleJumping = true;
        if (pawn.isGrounded) {
            pawn.isJumping = false;
            pawn.isDoubleJumping = false;
        }
        pawn.isInpuConsume = true;
        nextState = new JumpingRightState(pawn);
        return;
    }
    if (pressShift()) {
        nextState = new DashingRight(pawn);
        return;
	}

    if (pressJump() && pawn.canFloat) {
         nextState = new FlottingRight(pawn);
        return;
    }

    if (pawn.isGrounded) {
        pawn.isJumping = false;
        pawn.isDoubleJumping = false;
        nextState = new IdleStateRight(pawn);
        return;
    }
}

void FallingRight::render(sf::RenderWindow& window) {
}

DashingLeft::DashingLeft(Pawn& pawn) {
    rect = new TXanimated();
    rect->load("sprite/SpriteSheet/dashLeft.txt", 84, 23, pawn.pos.x, (pawn.pos.y + pawn.pos.y/2));
}

void DashingLeft::update(float dt, Pawn& pawn){

	if (pressLeft() && pawn.cooldownTimer <= 0.0f){
		pawn.dashTimer -= dt;
		if (pawn.dashTimer <= 0.0f){
			pawn.dashTimer = pawn.dashDuration;
			pawn.cooldownTimer = pawn.cooldownDuration;
		}
		else{
			pawn.velocityX = -pawn.speed * 2.0f;
			pawn.direction = 1;
            rect->update(dt);
            rect->rect.setPosition(pawn.pos);
		}

	}
	else{
		nextState = new MovingLeftState(pawn);
		return;
	}
}

void DashingLeft::render(sf::RenderWindow& window) {
	rect->render(window);
}

DashingRight::DashingRight(Pawn& pawn) {
    rect = new TXanimated();
	rect->load("sprite/SpriteSheet/dashRight.txt", 84, 23, pawn.pos.x, pawn.pos.y/2);
}

void DashingRight::update(float dt, Pawn& pawn){

	if (pressRight() && pawn.cooldownTimer <= 0.0f){
		pawn.dashTimer -= dt;

		if (pawn.dashTimer <= 0.0f){
			pawn.dashTimer = pawn.dashDuration;
			pawn.cooldownTimer = pawn.cooldownDuration;
		}
		else{
			pawn.velocityX = pawn.speed * 2.0f;
			pawn.direction = 0;
            rect->update(dt);
            rect->rect.setPosition(pawn.pos);
		}

	}
	else
	{
		nextState = new MovingRightState(pawn);
		return;
	}
}

void DashingRight::render(sf::RenderWindow& window) {
	rect->render(window);
}

void IState::setState(IState* state) {
	if (nextState != nullptr)
	{
		delete nextState;
	}
	nextState = state;
}

FlottingLeft::FlottingLeft(Pawn& pawn) {}

void FlottingLeft::update(float dt, Pawn& pawn)
{
    if (pressRight()) {
        nextState = new FlottingRight(pawn);
    }
    else if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
        pawn.direction = 1;
    }
    if (!pressJump()) {
        pawn.isInpuConsume = false;
        pawn.Gravity = 4000;
        nextState = new FallingLeft(pawn);
    }

    if (pressJump && !pawn.isGrounded) {
        pawn.Gravity = 1000;
    }
    if (pressShift()) {
        nextState = new DashingLeft(pawn);
        return;
    }

    if (pawn.isGrounded) {
        pawn.isJumping = false;
        pawn.Gravity = 4000;
        pawn.isDoubleJumping = false;
        nextState = new IdleStateLeft(pawn);
        return;
    }

}

void FlottingLeft::render(sf::RenderWindow& window)
{
}

FlottingRight::FlottingRight(Pawn& pawn) {}

void FlottingRight::update(float dt, Pawn& pawn)
{
    if (pressLeft()) {
        nextState = new FlottingLeft(pawn);
    }
    else if (pressRight()) {
        pawn.velocityX = pawn.speed;
        pawn.direction = 0;
    }
    else {
        pawn.velocityX = 0;
    }

    if (!pressJump()) {
        pawn.isInpuConsume = false;
        pawn.Gravity = 4000;
        nextState = new FallingRight(pawn);
    }

    if (pressJump && !pawn.isGrounded) {
        pawn.Gravity = 1000;
    }

    if (pressShift()) {
        nextState = new DashingRight(pawn);
        return;
    }

    if (pawn.isGrounded) {
        pawn.isJumping = false;
        pawn.Gravity = 4000;
        pawn.isDoubleJumping = false;
        nextState = new IdleStateRight(pawn);
        return;
    }
}

void FlottingRight::render(sf::RenderWindow& window)
{
}
