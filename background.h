#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
using namespace sf;
#include <random>

#include "barrel.h"
class Background {
 private:
  RectangleShape backgroundRect;  // 16:9 ratio for it will be a rectangle
  Texture backgroundTexture;
  std::vector<Barrel> barrels;

  float* cords_X; // stores the x cords of the mines
  float* cords_Y; // stores the y cords of the mines

 public:
  Background();  // default constructor for background
  void draw(RenderWindow& window);

  float* get_cordsX();
  float* get_cordsY();
};

#endif