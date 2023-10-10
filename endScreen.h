#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <SFML/Graphics.hpp>
using namespace sf;

class EndScreen {
 public:
  EndScreen(int width, int height);
  ~EndScreen();

  // Add a method to draw the end screen
  void draw(sf::RenderWindow &window);

 private:
  sf::Font font;
  sf::Text endText;
  sf::Text exitButton;  // Only one button needed
  RectangleShape endBackground;
  Texture endBack;
};

#endif