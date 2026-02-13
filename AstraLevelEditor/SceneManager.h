#pragma once
#include "Scene.h"
#include "EngineLevel.h"

class SceneManager {
public:

	SceneState currentState;
	SceneState previousState;

	Scene* MyLevel;

	SceneManager(sf::RenderWindow& window);
	~SceneManager();

	void manageState(keys* _myKeys, sf::RenderWindow& window);
	void displayState(sf::RenderWindow& window);
	void updateState(const bool* keys, float dt, sf::RenderWindow& window);
	SceneState getState() const;

	static SceneManager* GetSceneManager();
	static SceneManager* Instance;
};