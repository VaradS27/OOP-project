#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
using namespace sf;

#define MAX_NUMBER_OF_OPTIONS 3
class Menu {
 private:
  RectangleShape menuBackground; // Menu rectangular shape
  int itemIndex; // index
  sf::Font font; // Text font
  sf::Text text[MAX_NUMBER_OF_OPTIONS]; // text on buttons for the menu
  Texture menuBack; // menu texture

 public:
  Menu(float width, float height); // default constructor
  ~Menu(); // destructor

  void draw(sf::RenderWindow &window); // draw the menu window
  void Moveup(); // moveup() on the menu
  void Movedown(); // movedown() on the menu
  int GetPressedItem() { return itemIndex; } // get what button was pressed
};

#endif