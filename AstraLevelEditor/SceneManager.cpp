#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager(sf::RenderWindow& window) {

	currentState = SceneState::MenuS;
	previousState = SceneState::MenuS;

	MyMenu = new Menu(window, var);
}

SceneManager::~SceneManager() {
	if (MyLevel) {
		delete MyLevel;
	}
	if (MyLevel0) {
		delete MyLevel0;
	}
	if (MyLevel1) {
		delete MyLevel1;
	}
	if (MyLevel2) {
		delete MyLevel2;
	}
	if (MyMenu) {
		delete MyMenu;
	}

	MyMenu = nullptr;
	MyLevel = nullptr;
	MyLevel0 = nullptr;
	MyLevel1 = nullptr;
	MyLevel2 = nullptr;
}

void SceneManager::manageState(keys* _myKeys, sf::RenderWindow& window) {

	previousState = currentState;

	if (currentState == SceneState::Elevel) {
		MyLevel->nextScene(currentState, _myKeys, window);
	}
	else if (currentState == SceneState::Map1) {
		MyLevel0->nextScene(currentState, _myKeys, window);
	}
	else if (currentState == SceneState::Map2) {
		MyLevel1->nextScene(currentState, _myKeys, window);
	}
	else if (currentState == SceneState::Map3) {
		MyLevel2->nextScene(currentState, _myKeys, window);
	}
	else if (currentState == SceneState::MenuS) {
		MyMenu->nextScene(currentState, _myKeys, window);
	}

	if (currentState != previousState)
	{
		if (previousState == SceneState::Map1) {
			delete MyLevel0;
			MyLevel0 = nullptr;
		}
		if (previousState == SceneState::Map2) {
			delete MyLevel1;
			MyLevel1 = nullptr;
		}
		if (previousState == SceneState::Map3) {
			delete MyLevel2;
			MyLevel2 = nullptr;
		}
		if (previousState == SceneState::MenuS) {
			delete MyMenu;
			MyMenu = nullptr;
		}

		if (currentState == SceneState::Map1)
			MyLevel0 = new Level0(window, var);

		else if (currentState == SceneState::Map2)
			MyLevel1 = new Level1(window, var);

		else if (currentState == SceneState::Map3)
			MyLevel2 = new Level2(window, var);

		else if (currentState == SceneState::MenuS)
			MyMenu = new Menu(window, var);
	}
}

void SceneManager::displayState(sf::RenderWindow& window) {
	switch (currentState)
	{
	case SceneState::Elevel:
		MyLevel->displayScene(window);
		break;
	case SceneState::Map1:
		MyLevel0->displayScene(window);
		break;
	case SceneState::Map2:
		MyLevel1->displayScene(window);
		break;
	case SceneState::Map3:
		MyLevel2->displayScene(window);
		break;
	case SceneState::MenuS:
		MyMenu->displayScene(window);
		break;
	}
}

void SceneManager::updateState(const bool* keys, float dt, sf::RenderWindow& window) {
	if (currentState == SceneState::Elevel) {
		static_cast<EngineLevel*>(MyLevel)->update(keys, dt);
	}
	else if (currentState == SceneState::Map1) {
		static_cast<Level0*>(MyLevel0)->update(keys, dt);
	}
	else if (currentState == SceneState::Map2) {
		static_cast<Level1*>(MyLevel1)->update(keys, dt);
	}
	else if (currentState == SceneState::Map3) {
		static_cast<Level2*>(MyLevel2)->update(keys, dt);
	}
	else if (currentState == SceneState::MenuS) {
		static_cast<Menu*>(MyMenu)->update(keys, dt);
	}
}

SceneState SceneManager::getState() const {
	return currentState;
}

SceneManager* SceneManager::GetSceneManager()
{
	return Instance;
}