#include "StateMachine.h"

StateMachine::StateMachine(IState* startState) : currentState(startState) {
}

void StateMachine::update(float dt) {
    currentState->update(dt);
    auto next = currentState->nextState;
    if (next != currentState && next != nullptr)
    {
        delete currentState;
        currentState = next;
        currentState->nextState = nullptr;
    }
}

StateMachine::~StateMachine() {
    delete currentState;
    currentState = nullptr;
}

// IDLE
IdleState::IdleState() {}

void IdleState::update(float dt) {}
void IdleState::render(sf::RenderWindow& window) {}

// MOVE LEFT
MovingLeftState::MovingLeftState() {

}

void MovingLeftState::update(float dt) {}
void MovingLeftState::render(sf::RenderWindow& window) {}

// MOVE RIGHT
MovingRightState::MovingRightState() {

}

void MovingRightState::update(float dt) {}
void MovingRightState::render(sf::RenderWindow& window) {}

// JUMP LEFT
JumpingLeftState::JumpingLeftState() {

}

void JumpingLeftState::update(float dt) {}
void JumpingLeftState::render(sf::RenderWindow& window) {}

// JUMP RIGHT
JumpingRightState::JumpingRightState() {

}

void JumpingRightState::update(float dt) {}
void JumpingRightState::render(sf::RenderWindow& window) {}

// FALL LEFT
FallingLeft::FallingLeft() {

}

void FallingLeft::update(float dt) {}
void FallingLeft::render(sf::RenderWindow& window) {}

// FALL RIGHT
FallingRight::FallingRight() {

}

void FallingRight::update(float dt) {}
void FallingRight::render(sf::RenderWindow& window) {}
