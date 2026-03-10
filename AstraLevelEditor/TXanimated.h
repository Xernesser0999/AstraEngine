#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>

class TXanimated
{
public:

	int TotalFrame;
	int ActualFrame;

	float FrameRate;

	sf::Vector2i Frameloc;
	sf::Vector2i FrameSize;

	std::string filename;

	sf::IntRect offset;
	sf::Texture TX;
	sf::RectangleShape rect;

public:
	TXanimated();
	~TXanimated();

	void load(std::string file, std::string image, float sizeX, float sizeY, float posX, float posY);

	void update(float dt);
	void render(sf::RenderWindow& window);
};

