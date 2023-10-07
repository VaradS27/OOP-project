#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <SFML/Graphics.hpp>

#include "menu.h"  // Include the necessary menu header for button handling

class EndScreen {
 public:
  EndScreen(int width, int height);
  ~EndScreen();

  // Add methods to handle button movement and button press
  void Moveup();
  void Movedown();
  int GetPressedItem() { return selectedItemIndex; }

  // Add a method to draw the end screen
  void draw(sf::RenderWindow &window);

 private:
  int selectedItemIndex;
  sf::Font font;
  sf::Text endText;
  sf::Text buttons[2];  // You can adjust the number of buttons as needed
};

#endif