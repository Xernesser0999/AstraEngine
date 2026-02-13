#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager(sf::RenderWindow& window) {

	currentState = SceneState::Elevel;
	previousState = SceneState::Elevel;

	MyLevel = new EngineLevel(window);

}

SceneManager::~SceneManager() {


	delete MyLevel;
	MyLevel = nullptr;
}

void SceneManager::manageState(keys* _myKeys, sf::RenderWindow& window) {
	if (currentState == SceneState::Elevel) {
		MyLevel->nextScene(currentState, _myKeys, window);
	}
	//else if (currentState == SceneState::morning) {
	//	myMorning->nextScene(currentState, _myKeys, window);
	//}

}

void SceneManager::displayState(sf::RenderWindow& window) {
	switch (currentState)
	{
	case SceneState::Elevel:
		MyLevel->displayScene(window);
		break;
	//case SceneState::day:
	//	myDay->displayScene(window);
	//	break;
	}
}

void SceneManager::updateState(const bool* keys, float dt, sf::RenderWindow& window) {
	if (currentState == SceneState::Elevel) {
		static_cast<EngineLevel*>(MyLevel)->update(keys, dt);
	}
	//else if (currentState == SceneState::day) {
	//	static_cast<Day*>(myDay)->update(keys, dt);
	//}
}

SceneState SceneManager::getState() const {
	return currentState;
}

SceneManager* SceneManager::GetSceneManager()
{
	return Instance;
}