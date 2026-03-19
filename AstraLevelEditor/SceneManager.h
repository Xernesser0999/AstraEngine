#pragma once
#include "Scene.h"
#include "Global.h"

#include "EngineLevel.h"
#include "Level0.h"
#include "Level1.h"
#include "Level2.h"
#include "Menu.h"

class SceneManager {
public:
	Global var;

	SceneState currentState;
	SceneState previousState;

	Scene* MyLevel;
	Scene* MyLevel0;
	Scene* MyLevel1;
	Scene* MyLevel2;
	Scene* MyMenu;

	sf::Vector2f playerpos;

	int actualLevel;

public:
	SceneManager(sf::RenderWindow& window);
	~SceneManager();

	void manageState(keys* _myKeys, sf::RenderWindow& window);
	void displayState(sf::RenderWindow& window);
	void updateState(const bool* keys, float dt, sf::RenderWindow& window);
	SceneState getState() const;

	static SceneManager* GetSceneManager();
	static SceneManager* Instance;
};