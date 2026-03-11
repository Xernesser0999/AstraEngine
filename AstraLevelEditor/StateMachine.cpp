#include "StateMachine.h"
#include "Pawn.h"  


StateMachine::StateMachine(IState* startState) : currentState(startState) {}

void StateMachine::update(float dt, Pawn& pawn) {
    currentState->update(dt, pawn);
    IState* next = currentState->nextState;
    if (next != nullptr && next != currentState) {
        delete currentState;
        currentState = next;
        currentState->nextState = nullptr;
    }
}

StateMachine::~StateMachine() {
    delete currentState;
    currentState = nullptr;
}

static bool pressLeft() { 
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q); 
}
static bool pressRight() { 
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D); 
}
static bool pressJump() { 
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space); 
}

static IState* transitionOnLand(Pawn& pawn) {
    pawn.isJumping = false;
    pawn.isDoubleJumping = false;
    if (pressLeft()) {
        return new MovingLeftState();
    }
    else if (pressRight()) {
        return new MovingRightState();
    }
    else {
        return new IdleState();
    }
}

IdleState::IdleState() {}

void IdleState::update(float dt, Pawn& pawn) {
    pawn.velocityX = 0;

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

void IdleState::render(sf::RenderWindow& window) {
}

MovingLeftState::MovingLeftState() {}

void MovingLeftState::update(float dt, Pawn& pawn) {
    pawn.velocityX = -pawn.speed;
    pawn.direction = 1;

    if (!pressJump()) pawn.isInpuConsume = false;

    if (!pawn.isGrounded) {
        nextState = new FallingLeft();
        return;
    }
    if (pressJump() && !pawn.isInpuConsume) {
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
}

void MovingLeftState::render(sf::RenderWindow& window) {
}

MovingRightState::MovingRightState() {}

void MovingRightState::update(float dt, Pawn& pawn) {
    pawn.velocityX = pawn.speed;
    pawn.direction = 0;

    if (!pressJump()) pawn.isInpuConsume = false;

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
}

void MovingRightState::render(sf::RenderWindow& window) {
}

JumpingLeftState::JumpingLeftState() {}

void JumpingLeftState::update(float dt, Pawn& pawn) {
    if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
    }
    else if (pressRight()) {
        pawn.velocityX = pawn.speed;
    }
    else {
        pawn.velocityX = 0;
    }

    if (!pressJump()){
        pawn.isInpuConsume = false;
    }

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.isDoubleJumping = true;
        pawn.isInpuConsume = true;
    }

    if (pawn.velocityY >= 0) {
        nextState = new FallingLeft();
        return;
    }

    if (pawn.isGrounded) {
        nextState = transitionOnLand(pawn);
        return;
    }
}

void JumpingLeftState::render(sf::RenderWindow& window) {
}

JumpingRightState::JumpingRightState() {}

void JumpingRightState::update(float dt, Pawn& pawn) {
    if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
    }
    else if (pressRight()) {
        pawn.velocityX = pawn.speed;
    }
    else {
        pawn.velocityX = 0;
    }

    if (!pressJump()) pawn.isInpuConsume = false;

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.isDoubleJumping = true;
        pawn.isInpuConsume = true;
    }

    if (pawn.velocityY >= 0) {
        nextState = new FallingRight();
        return;
    }

    if (pawn.isGrounded) {
        nextState = transitionOnLand(pawn);
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
    }
    else if (pressRight()) {
        pawn.velocityX = pawn.speed;
    }
    else {
        pawn.velocityX = 0;
    }

    if (!pressJump()) {
        pawn.isInpuConsume = false;
    }

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.isDoubleJumping = true;
        pawn.isInpuConsume = true;
        nextState = new JumpingLeftState();
        return;
    }

    if (pawn.isGrounded) {
        nextState = transitionOnLand(pawn);
        return;
    }
}

void FallingLeft::render(sf::RenderWindow& window) {
}

FallingRight::FallingRight() {}

void FallingRight::update(float dt, Pawn& pawn) {
    pawn.isJumping = true;

    if (pressLeft()) {
        pawn.velocityX = -pawn.speed;
    }
    else if (pressRight()) {
        pawn.velocityX = pawn.speed;
    }
    else {
        pawn.velocityX = 0;
    }

    if (!pressJump()) {
        pawn.isInpuConsume = false;
    }

    if (pressJump() && pawn.isJumping && !pawn.isDoubleJumping && !pawn.isInpuConsume) {
        pawn.velocityY = -pawn.power_jump;
        pawn.isDoubleJumping = true;
        pawn.isInpuConsume = true;
        nextState = new JumpingRightState();
        return;
    }

    if (pawn.isGrounded) {
        nextState = transitionOnLand(pawn);
        return;
    }
}

void FallingRight::render(sf::RenderWindow& window) {
}