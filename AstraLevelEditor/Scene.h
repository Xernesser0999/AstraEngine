#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "KeyStruct.h"

enum SceneState {

};

class Scene {
public:

	Scene();
	virtual ~Scene();
	virtual void displayScene(sf::RenderWindow& window);
	virtual void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) = 0;
};