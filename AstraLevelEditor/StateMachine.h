#pragma once
#include <iostream>	
#include <SFML/Graphics.hpp>
#include <thread>

//STATE MACHINE
struct IState {
	virtual ~IState() = default;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	IState* nextState = nullptr;
};

struct StateMachine {
	IState* currentState;
	StateMachine(IState* startState);
	virtual void update(float dt);
	~StateMachine();
};

//ETAT
struct IdleState : IState {
	IdleState();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

struct MovingLeftState : IState {
	MovingLeftState();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

struct MovingRightState : IState {
	MovingRightState();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};	

struct JumpingLeftState : IState {
	JumpingLeftState();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

struct JumpingRightState : IState {
	JumpingRightState();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};	

struct FallingLeft : IState {
	FallingLeft();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

struct FallingRight : IState {
	FallingRight();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

