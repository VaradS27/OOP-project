#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include <SFML/Graphics.hpp>

#include "Shooting.h"
#include "movement.h"
using namespace sf;

class PlayerTwo {
 private:
  RectangleShape tank2Rect;
  Movement movement;
  float barrel2Length;
  RectangleShape barrel2Rect;
  Shooting* ammo;
  int ammo_count = 1;
  Texture tankTexture;
  Texture tankBarrelTexture;
 public:
  PlayerTwo();         // default constructor
  void handleInput();  // wasd inputs
  void draw(RenderWindow& window);
  void reload();
  // shooting mechs for player 1
  void fire();
  void ShootingInput(PlayerTwo p2);
};

#endif