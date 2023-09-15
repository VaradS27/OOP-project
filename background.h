#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Background {
 public:
  Background(); // default constructor for background
  void draw(RenderWindow& window);

 private:
  RectangleShape backgroundRect; // 16:9 ratio for it will be a rectangle
};

#endif