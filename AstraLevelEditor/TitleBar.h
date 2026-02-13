#pragma once
#include <optional>
#include <SFML/Graphics.hpp>

#include "GUI_Button.h"

class TitleBar {
public :
	TitleBar();
	~TitleBar();

	void update(float dt);
	void render(sf::RenderWindow& window);

public :
	sf::RectangleShape Bar;
	GUI_button Quit_button;
};

