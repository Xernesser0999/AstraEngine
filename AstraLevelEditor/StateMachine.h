#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include "TXanimated.h"

struct Pawn;

struct IState {
    virtual ~IState() = default;
    virtual void update(float dt, Pawn& pawn) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    void setState(IState* state);
    IState* nextState = nullptr;
    TXanimated* rect = nullptr;
    sf::Texture texture;
};

struct StateMachine {
    IState* currentState;
    StateMachine(IState* startState);
    virtual void update(float dt, Pawn& pawn);
    ~StateMachine();
};

struct DummyState : IState {
    void update(float dt, Pawn& pawn) override {}
    void render(sf::RenderWindow& window) override {}
};

struct IdleStateRight : IState {
    IdleStateRight(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct IdleStateLeft : IState {
    IdleStateLeft(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct MovingLeftState : IState {
    MovingLeftState(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct MovingRightState : IState {
    MovingRightState(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct JumpingLeftState : IState {
    JumpingLeftState(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct JumpingRightState : IState {
    JumpingRightState(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct FallingLeft : IState {
    FallingLeft(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct FallingRight : IState {
    FallingRight(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct DashingLeft : IState {
    DashingLeft(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct DashingRight : IState {
    DashingRight(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct FlottingLeft : IState {
    FlottingLeft(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};

struct FlottingRight : IState {
    FlottingRight(Pawn& pawn);
    void update(float dt, Pawn& pawn) override;
    void render(sf::RenderWindow& window) override;
};