#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <SFML/Graphics.hpp>

#include "Shooting.h"
#include "Tank.h"

class PlayerTwo;

using namespace sf;

// The PlayerOne class is like the control center for the first player’s tank in
// the game. It keeps track of the tank’s shape, barrel length, ammo, and
// textures. It also handles user inputs for moving and shooting, and it can
// draw the tank on the game window. The class also has methods for firing and
// reloading ammo, checking if the tank has been hit, and updating the tank’s
// health. Plus, it makes sure the tank doesn’t go outside the game map.

class PlayerOne : public Tank {
 private:
  RectangleShape tankRect;    // tank rectangular shape
  float barrelLength;         // barrel length
  RectangleShape barrelRect;  // tank barrel rectangular shape
  Shooting* ammo;
  int ammo_count = 1;         // tank can only shoot one time each time
  Texture tankTexture;        // tank texture
  Texture tankBarrelTexture;  // barrel texture

 public:
  PlayerOne();  // default constructor
  // ~PlayerOne();  // destructor
  void handleInput();               // wasd inputs
  void draw(RenderWindow& window);  // draw playerOne on the game window

  // shooting mechanics for player 1
  void fire();
  void ShootingInput(PlayerOne p1);
  void reload();

  // collision for player 1
  void health(PlayerOne p1, PlayerTwo p2);
  bool isHit(PlayerOne& p1, PlayerTwo& p2);
  Shooting* getAmmo() { return ammo; };
  int getHealth() {
    return this->p_health;  // Inherited from Tank
  };

  // For Unit Tests:
  RectangleShape& get_tankRect() { return tankRect; };
  RectangleShape& get_barrelRect() { return barrelRect; };
};

#endif