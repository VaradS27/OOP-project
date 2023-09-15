#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <SFML/Graphics.hpp>

#include "movement.h"
using namespace sf;

class PlayerOne {
 private:
  RectangleShape tankRect;
  Movement movement;

 public:
  PlayerOne();         // default constructor
  void handleInput();  // wasd inputs
  void draw(RenderWindow& window);
};

#endif