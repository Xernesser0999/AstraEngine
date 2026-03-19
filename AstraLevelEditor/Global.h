#pragma once
#include <SFML/Graphics.hpp>

#include <fstream>
#include <string>

#include "Scene.h"

// Classe qui sert a garder des varaible entre les scene. (utile pour le changement de lvl)

class Pawn;

class Global
{
public:
	bool Boot;
	sf::Vector2f pos;
	int actualLevel;
	sf::Vector2f RezPos;

	bool DBUnlock;
	bool FloatUnlock;
	int hp;

public:
	Global();
	~Global();

	void load();
	void save(Pawn& pawn, int z);
	void reset();
};

