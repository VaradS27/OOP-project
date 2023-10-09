#ifndef MINE_H
#define MINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Mine {
    private:
        sf::CircleShape mine;
        int numberMines = 7;
        int mineCordX = 0;
        int mineCordY = 0;
    public:
        Mine();
        void draw(RenderWindow& window);
        // int collision(PlayerOne &R1, CircleShape &C1);
        // float clamp(float value, float minn, float maxx);
};

#endif