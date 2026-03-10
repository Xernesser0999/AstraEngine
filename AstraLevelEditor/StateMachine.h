#pragma once
#include <iostream>	
#include <SFML/Graphics.hpp>
#include <thread>

//STATE MACHINE
struct IState {
	virtual ~IState() = default;
	virtual void update(float dt);
	virtual void render(sf::RenderWindow& window);
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
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

struct MovingLeftState : IState {
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

struct MovingRightState : IState {
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};	

struct JumpingLeftState : IState {
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

struct JumpingRightState : IState {
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};	


