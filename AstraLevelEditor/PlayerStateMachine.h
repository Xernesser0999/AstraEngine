#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class StateStruct;

class PlayerStateMachine
{
public:

	PlayerStateMachine();
	~PlayerStateMachine();

private:

	std::vector<StateStruct*> states;
};