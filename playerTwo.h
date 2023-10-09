#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include <SFML/Graphics.hpp>

#include "Shooting.h"
#include "Tank.h"

class PlayerOne;  // Forward declaration of PlayerOne class.

using namespace sf;

class PlayerTwo : public Tank {
 private:
  RectangleShape tankRect;
  float barrelLength;
  RectangleShape barrelRect;
  Shooting* ammo;
  int ammo_count = 1;
  Texture tankTexture;
  Texture tankBarrelTexture;

 public:
  PlayerTwo();         // Default constructor
  void handleInput();  // Arrow key inputs
  void draw(RenderWindow& window);
  void reload();
  // Shooting mechanisms for player 2
  void fire();
  void ShootingInput(PlayerTwo p2);
  // Collision for player 2
  void health(PlayerTwo p2, PlayerOne p1);
  bool isHit(PlayerTwo& p2, PlayerOne& p1);
  Shooting* getAmmo() { return ammo; };
  float clamp(float value, float minn, float maxx);
  int collision(PlayerTwo& R1);
  void collideHealth(PlayerTwo& R1);
  int getHealth() {
    return this->p_health;  // Inherited from Tank
  }
};

#endif