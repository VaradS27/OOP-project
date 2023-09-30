#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
using namespace sf;

#define MAX_NUMBER_OF_OPTIONS 3
class Menu {
    private:
        int itemIndex;
        sf::Font font;
        sf::Text text[MAX_NUMBER_OF_OPTIONS];
    public:
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow &window);
        void Moveup();
        void Movedown();
        int GetPressedItem() {return itemIndex;}

};

#endif