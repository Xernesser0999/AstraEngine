#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

class BGparralaxAuto
{
public:
    float scrollX4;
    float scrollX3;
    float scrollX2;
    float scrollX1;
    float scrollX0;

    float Speed_L4;
    float Speed_L3;
    float Speed_L2;
    float Speed_L1;
    float Speed_L0;

    BGparralaxAuto(sf::RenderWindow& window, std::string file1, std::string file2, std::string file3, std::string file4, std::string file5, float sizeX, float sizeY, float speed, float speedfactor);
    ~BGparralaxAuto();

    sf::Vector2f size;
    sf::RectangleShape rect1;
    sf::RectangleShape rect2;
    sf::RectangleShape rect3;
    sf::RectangleShape rect4;
    sf::RectangleShape rect5;

    sf::RectangleShape rect1bis;
    sf::RectangleShape rect2bis;
    sf::RectangleShape rect3bis;
    sf::RectangleShape rect4bis;
    sf::RectangleShape rect5bis;

    void update(float dt);
    void render(sf::RenderWindow& window);

    sf::Texture TX1;
    sf::Texture TX2;
    sf::Texture TX3;
    sf::Texture TX4;
    sf::Texture TX5;
};

