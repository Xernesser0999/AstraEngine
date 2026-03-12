#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>

struct Pawn;

struct IState {
    virtual ~IState() = default;
    virtual void update(float dt, Pawn& pawn) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    void setState(IState* state);
    IState* nextState = nullptr;
};

struct StateMachine {
    IState* currentState;
    StateMachine(IState* startState);
    virtual void update(float dt, Pawn& pawn);
    ~StateMachine();
};


struct IdleState : IState {
    IdleState();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct MovingLeftState : IState {
    MovingLeftState();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct MovingRightState : IState {
    MovingRightState();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct JumpingLeftState : IState {
    JumpingLeftState();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct JumpingRightState : IState {
    JumpingRightState();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct FallingLeft : IState {
    FallingLeft();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct FallingRight : IState {
    FallingRight();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct DashingLeft : IState {
    DashingLeft();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct DashingRight : IState {
    DashingRight();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct FlottingLeft : IState {
    FlottingLeft();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct FlottingRight : IState {
    FlottingRight();
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};