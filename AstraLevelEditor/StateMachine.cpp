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
