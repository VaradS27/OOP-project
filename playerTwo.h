#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Shooting.h"
#include "barrel.h"
#include "movement.h"

class PlayerOne;  // issue with forward declaration of PlayerOne class.

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
  int p_health = 10;
  int t_depth = 30;
  int b_depth = 5;

 public:
  PlayerTwo();         // default constructor
  void handleInput();  // arrow key inputs
  void draw(RenderWindow& window);
  void reload();
  // shooting mechs for player 2
  void fire();
  void ShootingInput(PlayerTwo p2);
  // collision for player 2
  void health(PlayerTwo p2, PlayerOne p1);
  bool isHit(PlayerTwo& p2, PlayerOne& p1);
  Shooting* getAmmo() { return ammo; };
};

#endif