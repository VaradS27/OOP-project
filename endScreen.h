#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <SFML/Graphics.hpp>
using namespace sf;

class EndScreen {
 public:
  EndScreen(int width, int height); // default constructor
  ~EndScreen(); // destructor

  // draw() method for the end screen
  void draw(sf::RenderWindow &window);

 private:
  sf::Font font; // font for text on the end screen
  sf::Text endText; // text that will be displayed on the end screen
  sf::Text exitButton;  // Only one button needed
  RectangleShape endBackground; // End Screen will be a rectangular shape
  Texture endBack; // Texture for end screen
};

#endif