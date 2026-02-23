#include "BGparralaxAuto.h"

BGparralaxAuto::BGparralaxAuto(sf::RenderWindow& window, std::string file1, std::string file2, std::string file3, std::string file4, std::string file5, float sizeX, float sizeY, float speed, float speedfactor)
{
    //  BG Layer 5
    rect5.setPosition({ 0, 0 });
    rect5.setSize({sizeX, sizeY});
    rect5bis.setPosition({ 0 + sizeX, 0 });
    rect5bis.setSize({ sizeX, sizeY });

    TX5.loadFromFile(file5.c_str());
    rect5.setTexture(&TX5);
    rect5bis.setTexture(&TX5);

    //  BG Layer 4
    rect4.setPosition({ 0, 0 });
    rect4.setSize({ sizeX, sizeY });
    rect4bis.setPosition({ 0 + sizeX, 0 });
    rect4bis.setSize({ sizeX, sizeY });

    TX4.loadFromFile(file4.c_str());
    rect4.setTexture(&TX4);
    rect4bis.setTexture(&TX4);

    //  BG Layer 3
    rect3.setPosition({ 0, 0 });
    rect5.setSize({ sizeX, sizeY });
    rect3bis.setPosition({ 0 + sizeX, 0 });
    rect3bis.setSize({ sizeX, sizeY });

    TX3.loadFromFile(file3.c_str());
    rect3.setTexture(&TX3);
    rect3bis.setTexture(&TX3);

    //  BG Layer 2
    rect2.setPosition({ 0, 0 });
    rect2.setSize({ sizeX, sizeY });
    rect2bis.setPosition({ 0 + sizeX, 0 });
    rect2bis.setSize({ sizeX, sizeY });

    TX2.loadFromFile(file2.c_str());
    rect2.setTexture(&TX2);
    rect2bis.setTexture(&TX2);

    //  BG Layer 1
    rect1.setPosition({ 0, 0 });
    rect1.setSize({ sizeX, sizeY });
    rect1bis.setPosition({ 0 + sizeX, 0 });
    rect1bis.setSize({ sizeX, sizeY });

    TX1.loadFromFile(file1.c_str());
    rect1.setTexture(&TX1);
    rect1bis.setTexture(&TX1);

    Speed_L4 = speed;
    Speed_L3 = speed * (speedfactor * 2);
    Speed_L2 = speed * (speedfactor * 3);
    Speed_L1 = speed * (speedfactor * 4);
    Speed_L0 = speed * (speedfactor * 5);
}


void BGparralaxAuto::update(float dt) {
    scrollX4 -= Speed_L4 * dt;        // Background scrolling
    scrollX3 -= Speed_L3 * dt;        // Background scrolling
    scrollX2 -= Speed_L2 * dt;        // Background scrolling
    scrollX1 -= Speed_L1 * dt;        // Background scrolling
    scrollX0 -= Speed_L0 * dt;        // Background scrolling

    if (scrollX4 <= -1920) {             // Give the illusion of an infinite scrolling background by repeating them
        scrollX4 = 0;
    }
    if (scrollX3 <= -1920) {             // Give the illusion of an infinite scrolling background by repeating them
        scrollX3 = 0;
    }
    if (scrollX2 <= -1920) {             // Give the illusion of an infinite scrolling background by repeating them
        scrollX2 = 0;
    }
    if (scrollX1 <= -1920) {             // Give the illusion of an infinite scrolling background by repeating them
        scrollX1 = 0;
    }
    if (scrollX0 <= -1920) {             // Give the illusion of an infinite scrolling background by repeating them
        scrollX0 = 0;
    }
}

void BGparralaxAuto::render(sf::RenderWindow& window) {

    rect5.setPosition({scrollX4, 0});
    rect5bis.setPosition({ scrollX4 + 1920, 0 });
    window.draw(rect5);
    window.draw(rect5bis);

    rect4.setPosition({ scrollX3, 0 });
    rect4bis.setPosition({ scrollX3 + 1920, 0 });
    window.draw(rect4);
    window.draw(rect4bis);

    rect3.setPosition({ scrollX2, 0 });
    rect3bis.setPosition({ scrollX2 + 1920, 0 });
    window.draw(rect3);
    window.draw(rect3bis);

    rect2.setPosition({ scrollX1, 0 });
    rect2bis.setPosition({ scrollX1 + 1920, 0 });
    window.draw(rect2);
    window.draw(rect2bis);

    rect1.setPosition({ scrollX0, 0 });
    rect1bis.setPosition({ scrollX0 + 1920, 0 });
    window.draw(rect1);
    window.draw(rect1bis);
}

BGparralaxAuto::~BGparralaxAuto() {
}