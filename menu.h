#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
using namespace sf;

// The Menu class is like the main menu you see when you start a game. It’s got
// a background (menuBackground) that’s a rectangle covering the whole screen,
// and a texture (menuBack) that’s the design or picture on the background.
// There are some options (text) displayed on the screen, like “Start Game” or
// “Exit”, and they use a specific font (font). You can move up and down the
// options with Moveup() and Movedown(), and GetPressedItem() tells you which
// option is currently selected. The draw function is what puts the menu on your
// game window.

#define MAX_NUMBER_OF_OPTIONS 3
class Menu {
 private:
  RectangleShape menuBackground;         // Menu rectangular shape
  int itemIndex;                         // index
  sf::Font font;                         // Text font
  sf::Text text[MAX_NUMBER_OF_OPTIONS];  // text on buttons for the menu
  Texture menuBack;                      // menu texture

 public:
  Menu(float width, float height);  // default constructor
  ~Menu();                          // destructor

  void draw(sf::RenderWindow &window);        // draw the menu window
  void Moveup();                              // moveup() on the menu
  void Movedown();                            // movedown() on the menu
  int GetPressedItem() { return itemIndex; }  // get what button was pressed
};

#endif