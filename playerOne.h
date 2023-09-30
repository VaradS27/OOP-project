#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Shooting.h"
#include "barrel.h"
#include "movement.h"
#include "background.h"
class PlayerTwo;  // issue with forward declaration of PlayerTwo class.

using namespace sf;

class PlayerOne {
 private:
  Background background;
  RectangleShape tankRect;
  Movement movement;
  float barrelLength;
  RectangleShape barrelRect;
  Shooting* ammo;
  int ammo_count = 1;
  Texture tankTexture;
  Texture tankBarrelTexture;
  int p_health = 10;
  int t_depth = 30;
  int b_depth = 5;
  int m_depth = 30;

 public:
  PlayerOne();         // default constructor
  void handleInput();  // wasd inputs
  void draw(RenderWindow& window);
  // shooting mechs for player 1
  void fire();
  void ShootingInput(PlayerOne p1);
  void reload();
  // collision for player 1
  void health(PlayerOne p1, PlayerTwo p2);
  bool isHit(PlayerOne& p1, PlayerTwo& p2);
  bool isHit_mine(PlayerOne& p1, PlayerTwo& p2);
  Shooting* getAmmo() { return ammo; };

};

#endif