#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <SFML/Graphics.hpp>
#include "Shooting.h"
#include "movement.h"
using namespace sf;

class PlayerOne{
 private:
  RectangleShape tankRect;
  Movement movement;
  Shooting* ammo;
  int ammo_count = 1000;

 public:
  PlayerOne();         // default constructor
  void handleInput();  // wasd inputs
  void draw(RenderWindow& window);
  // shooting mechs for player 1
  void fire();
  void ShootingInput(PlayerOne p1);
};

#endif