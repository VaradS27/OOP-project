#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Background {
 private:
  RectangleShape backgroundRect;  // Rectangular background
  Texture backgroundTexture;  // Bacground Texture
 public:
  Background();  // default constructor for background
  void draw(RenderWindow& window);  // draw() to draw background in 'game' window
};

#endif