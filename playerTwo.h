#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include <SFML/Graphics.hpp>

#include "Shooting.h"
#include "Tank.h"

class PlayerOne;  // Forward declaration of PlayerOne class.

using namespace sf;

// The PlayerTwo class is like the control center for the second player’s tank in
// the game. It keeps track of the tank’s shape, barrel length, ammo, and
// textures. It also handles user inputs for moving and shooting, and it can
// draw the tank on the game window. The class also has methods for firing and
// reloading ammo, checking if the tank has been hit, and updating the tank’s
// health. Plus, it makes sure the tank doesn’t go outside the game map.

class PlayerTwo : public Tank {
 private:
  RectangleShape tankRect;    // tank rectangular shape
  float barrelLength;         // barrel length
  RectangleShape barrelRect;  // tank barrel rectnagular shape
  Shooting* ammo;
  int ammo_count = 1;         // set ammo to 1
  Texture tankTexture;        // tank texture
  Texture tankBarrelTexture;  // barrel texture

 public:
  PlayerTwo();  // Default constructor
  // ~PlayerTwo(); // destructor
  void handleInput();               // Arrow key inputs
  void draw(RenderWindow& window);  // draw playerTwo to game window

  // Shooting mechanisms for player 2
  void reload();
  void fire();
  void ShootingInput(PlayerTwo p2);

  // Collision for player 2
  void health(PlayerTwo p2, PlayerOne p1);
  bool isHit(PlayerTwo& p2, PlayerOne& p1);
  Shooting* getAmmo() { return ammo; };
  int getHealth() {
    return this->p_health;  // Inherited from Tank
  }

  // For Unit Tests:
  RectangleShape& get_tankRect() { return tankRect; };
  RectangleShape& get_barrelRect() { return barrelRect; };
};

#endif