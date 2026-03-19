#pragma once
#include "Scene.h"

#include <SFML/Audio.hpp>

#include "Camera.h"
#include "BGstatic.h"
#include "GUI_Button.h"

class Global;

class Menu : public Scene {
public:

	Menu(sf::RenderWindow& window, Global& var_);
	~Menu();

	void displayScene(sf::RenderWindow& window) override;
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:
	BGstatic* Background;
	Camera* cam;

	sf::RectangleShape rect;
	sf::Texture TX;

	sf::Music music;

	GUI_button* play;
	GUI_button* quit;
	GUI_button* trash;

	

	Global& glob;
};
