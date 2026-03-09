#pragma once
#include <SFML/Graphics.hpp>

// Classe qui sert a garder des varaible entre les scene. (utile pour le changement de lvl)

class Global
{
public:
	bool Boot;
	sf::Vector2f pos;

public:
	Global();
	~Global();
};

