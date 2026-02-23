#pragma once

//Basic include
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>

// Include everything we want to add in the level
// Not the player or thing that can move. It is not supported yet just collider or thing like spike (environment)
#include "Collider.h"
#include "BGstatic.h"
#include <iostream>

#include "PlayerEX.h"   // trust (i dont know why it there)

class Camera;

class LevelLoader {
public:
    std::vector<Collider*> colliders;

    LevelLoader() : actualX(0), actualY(0) {}
    ~LevelLoader();

    void load(const std::string& collider_path, const std::string& render_path, sf::RenderWindow& window, float tileX, float tileY);
    void oldload(const std::string& path, sf::RenderWindow& window);

    void update(float dt, PlayerEX& player);
    void render(sf::RenderWindow& window, Camera* cam);

private:
    float actualX;
    float actualY;

    BGstatic* back;
};

// Final objective. Load a level in two part :
// - Collision and trigger
// - Appearence of the level