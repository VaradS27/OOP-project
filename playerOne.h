#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <SFML/Graphics.hpp>

#include "Shooting.h"
#include "Tank.h"

class PlayerTwo;

using namespace sf;

class PlayerOne : public Tank {
 private:
  RectangleShape tankRect;
  float barrelLength;
  RectangleShape barrelRect;
  Shooting* ammo;
  int ammo_count = 1;
  Texture tankTexture;
  Texture tankBarrelTexture;

 public:
  PlayerOne();  // default constructor
  // ~PlayerOne();
  void handleInput();  // wasd inputs
  void draw(RenderWindow& window);
  // shooting mechs for player 1
  void fire();
  void ShootingInput(PlayerOne p1);
  void reload();
  // collision for player 1
  void health(PlayerOne p1, PlayerTwo p2);
  bool isHit(PlayerOne& p1, PlayerTwo& p2);
  Shooting* getAmmo() { return ammo; };
  int getHealth() {
    return this->p_health;  // Inherited from Tank
  }
  // For Unit Tests:
  RectangleShape& get_tankRect() { return tankRect; };
  RectangleShape& get_barrelRect() { return barrelRect; };
};

#endif