#pragma once

//Basic include
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>

// Include everything we want to add in the level
// Not the player or thing that can move. It is not supported yet just collider or thing like spike (environment)
#include "Collider.h"

#include "PlayerEX.h"   // trust (i dont know why it there)

class Camera;

class LevelLoader {
public:
    std::vector<Collider*> colliders;

    LevelLoader() : actualX(0), actualY(0) {}

    void load(const std::string& path, sf::RenderWindow& window);

    void update(float dt, PlayerEX& player);
    void render(sf::RenderWindow& window, Camera* cam);

private:
    float actualX;
    float actualY;
};

// Final objective. Load a level in two part :
// - Collision and trigger
// - Appearence of the level