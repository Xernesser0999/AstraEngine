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
static bool pressJump() { 
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}

static bool pressShift()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift);
}

IdleState::IdleState() {}

void IdleState::update(float dt, Pawn& pawn) {
    pawn.velocityX = 0;
    pawn.Gravity = 4000;
	pawn.cooldownTimer -= dt;

    if (!pawn.isGrounded) {
        if (pawn.direction == 0) {
            nextState = new FallingRight();
        }
        else {
            nextState = new FallingLeft();
        }
        return;
    }
    if (pressLeft()) {
        nextState = new MovingLeftState();
        return;
    }
    if (pressRight()) {
        nextState = new MovingRightState();
        return;
    }
    if (pressJump() && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.isGrounded = false;
        pawn.isJumping = true;
        pawn.isInpuConsume = true;
        nextState = new JumpingRightState();  
        return;
    }
    if (!pressJump()) {
        pawn.isInpuConsume = false;
    }
}

void IdleState::render(sf::RenderWindow& window)
{
}

MovingLeftState::MovingLeftState() {}

void MovingLeftState::update(float dt, Pawn& pawn)
{
	pawn.velocityX = -pawn.speed;
	pawn.direction = 1;
	pawn.cooldownTimer -= dt;

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}

	if (!pawn.isGrounded) {
		nextState = new FallingLeft();
		return;
	}
	if (pressJump() && !pawn.isInpuConsume)
	{
		pawn.velocityY = -pawn.power_jump;
		pawn.isGrounded = false;
		pawn.isJumping = true;
		pawn.isInpuConsume = true;
		nextState = new JumpingLeftState();
		return;
	}
	if (!pressLeft() && !pressRight()) {
		nextState = new IdleState();
		return;
	}
	if (pressRight()) {
		nextState = new MovingRightState();
		return;
	}
	if (pressShift()) {
		nextState = new DashingLeft();
		return;
	}
}

void MovingLeftState::render(sf::RenderWindow& window) {
}

MovingRightState::MovingRightState() {}

void MovingRightState::update(float dt, Pawn& pawn) {
	pawn.velocityX = pawn.speed;
	pawn.direction = 0;
	pawn.cooldownTimer -= dt;

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}

	if (!pawn.isGrounded) {
		nextState = new FallingRight();
		return;
	}
	if (pressJump() && !pawn.isInpuConsume) {
		pawn.velocityY = -pawn.power_jump;
		pawn.isGrounded = false;
		pawn.isJumping = true;
		pawn.isInpuConsume = true;
		nextState = new JumpingRightState();
		return;
	}
	if (!pressLeft() && !pressRight()) {
		nextState = new IdleState();
		return;
	}
	if (pressLeft()) {
		nextState = new MovingLeftState();
		return;
	}
	if (pressShift()) {
		nextState = new DashingRight();
		return;
	}
}

void MovingRightState::render(sf::RenderWindow& window) {}

JumpingLeftState::JumpingLeftState() {}

void JumpingLeftState::update(float dt, Pawn& pawn) {
    if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
        pawn.direction = 1;
    }
    else if (pressRight()) {
        nextState = new JumpingRightState();
    }
    else {
        pawn.velocityX = 0;
    }

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume) {
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
		nextState = new DashingLeft();
		return;
	}

	if (pawn.velocityY >= 0) {
		nextState = new FallingLeft();
		return;
	}

	if (pawn.isGrounded) {
		pawn.isJumping = false;
		pawn.isDoubleJumping = false;
		nextState = new IdleState();
		return;
	}
}

void JumpingLeftState::render(sf::RenderWindow& window) {
}

JumpingRightState::JumpingRightState() {}

void JumpingRightState::update(float dt, Pawn& pawn) {

	if (pressLeft()) {
		nextState = new JumpingLeftState();
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
    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume) {
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
		nextState = new DashingRight();
		return;
	}

	if (pawn.velocityY >= 0) {
		nextState = new FallingRight();
		return;
	}

	if (pawn.isGrounded) {
		pawn.isJumping = false;
		pawn.isDoubleJumping = false;
		nextState = new IdleState();
		return;
	}
}

void JumpingRightState::render(sf::RenderWindow& window) {
}

FallingLeft::FallingLeft() {}

void FallingLeft::update(float dt, Pawn& pawn) {
	pawn.isJumping = true;

	if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
        pawn.direction = 1;
    }
    else if (pressRight()) {
		nextState = new FallingRight();
    }
    else {
        pawn.velocityX = 0;
    }

	if (!pressJump()) {
		pawn.isInpuConsume = false;
	}

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.Gravity = 4000;
        pawn.isDoubleJumping = true;
        if (pawn.isGrounded) {
            pawn.isJumping = false;
            pawn.isDoubleJumping = false;
        }
        pawn.isInpuConsume = true;
        nextState = new JumpingLeftState();
        return;
    }
    
    if (pressShift()) {
        nextState = new DashingLeft();
        return;
    }

    if (pressJump()) {
        nextState = new FlottingLeft();
        return;
    }

    if (pawn.isGrounded) {
        pawn.isJumping = false;
        pawn.isDoubleJumping = false;
        nextState = new IdleState();
        return;
    }
}

void FallingLeft::render(sf::RenderWindow& window) {
}

FallingRight::FallingRight() {}

void FallingRight::update(float dt, Pawn& pawn) {
	pawn.isJumping = true;

    if (pressLeft()) {
        nextState = new FallingLeft;
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

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.Gravity = 4000;
        pawn.isDoubleJumping = true;
        if (pawn.isGrounded) {
            pawn.isJumping = false;
            pawn.isDoubleJumping = false;
        }
        pawn.isInpuConsume = true;
        nextState = new JumpingRightState();
        return;
    }
    if (pressShift()) {
        nextState = new DashingRight();
        return;
	}

    if (pressJump()) {
         nextState = new FlottingRight();
        return;
    }

    if (pawn.isGrounded) {
        pawn.isJumping = false;
        pawn.isDoubleJumping = false;
        nextState = new IdleState();
        return;
    }
}

void FallingRight::render(sf::RenderWindow& window) {
}

DashingLeft::DashingLeft() {}

void DashingLeft::update(float dt, Pawn& pawn)
{
	if (pressLeft() && pawn.cooldownTimer <= 0.0f)
	{
		pawn.dashTimer -= dt;
		if (pawn.dashTimer <= 0.0f)
		{
			pawn.dashTimer = pawn.dashDuration;
			pawn.cooldownTimer = pawn.cooldownDuration;
		}
		else
		{
			pawn.velocityX = -pawn.speed * 2.0f;
			pawn.direction = 1;
		}

	}
	else
	{
		nextState = new MovingLeftState();
		return;
	}
}

void DashingLeft::render(sf::RenderWindow& window) {}

DashingRight::DashingRight() {}

void DashingRight::update(float dt, Pawn& pawn)
{
	if (pressRight() && pawn.cooldownTimer <= 0.0f)
	{
		pawn.dashTimer -= dt;

		if (pawn.dashTimer <= 0.0f)
		{
			pawn.dashTimer = pawn.dashDuration;
			pawn.cooldownTimer = pawn.cooldownDuration;
		}
		else
		{
			pawn.velocityX = pawn.speed * 2.0f;
			pawn.direction = 0;
		}

	}
	else
	{
		nextState = new MovingRightState();
		return;
	}
}

void DashingRight::render(sf::RenderWindow& window) {
}

void IState::setState(IState* state) {
	if (nextState != nullptr)
	{
		delete nextState;
	}
	nextState = state;
}

FlottingLeft::FlottingLeft() {}

void FlottingLeft::update(float dt, Pawn& pawn)
{
    if (pressRight()) {
        nextState = new FlottingRight();
    }
    else if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
        pawn.direction = 1;
    }
    if (!pressJump()) {
        pawn.isInpuConsume = false;
        pawn.Gravity = 4000;
        nextState = new FallingLeft();
    }

    if (pressJump && !pawn.isGrounded) {
        pawn.Gravity = 1000;
    }
    if (pressShift()) {
        nextState = new DashingLeft();
        return;
    }

    if (pawn.isGrounded) {
        pawn.isJumping = false;
        pawn.Gravity = 4000;
        pawn.isDoubleJumping = false;
        nextState = new IdleState();
        return;
    }

}

void FlottingLeft::render(sf::RenderWindow& window)
{
}

FlottingRight::FlottingRight() {}

void FlottingRight::update(float dt, Pawn& pawn)
{

    if (pressLeft()) {
        nextState = new FlottingLeft;
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
        nextState = new FallingRight();
    }

    if (pressJump && !pawn.isGrounded) {
        pawn.Gravity = 1000;
    }

    if (pressShift()) {
        nextState = new DashingRight();
        return;
    }

    if (pawn.isGrounded) {
        pawn.isJumping = false;
        pawn.Gravity = 4000;
        pawn.isDoubleJumping = false;
        nextState = new IdleState();
        return;
    }
}

void FlottingRight::render(sf::RenderWindow& window)
{
}
