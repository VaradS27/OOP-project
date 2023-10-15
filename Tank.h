#ifndef TANK_H
#define TANK_H

#include "movement.h"

// The Tank class is like the blueprint for the tanks in the game. It inherits
// from the Movement class, so it includes all the movement functionality. On
// top of that, it has its own properties like health (p_health), and hitbox
// sizes for the tank (t_depth) and bullet (b_depth). The Tank class also has
// methods to get and set these properties. When you create a new tank, its
// health is set to 10, and the hitbox sizes are set to 35 for the tank and 5
// for the bullet. All tanks in the game are created based on this blueprint.

class Tank : public Movement {
 protected:
  int player_health;  // player health - will be set to 10
  int tank_depth;   // tank hitbox - will be set to 35
  int bullet_depth;   // bullet hitbox - will be set to 5

 public:
  Tank();  // Default constructor for Tank
  // Getters and setters for tank abstract class:
  virtual int getHealth() { return 0; }
  virtual void set_tankDepth() { tank_depth = 35; };
  virtual void set_bulletDepth() { bullet_depth = 5; };
  virtual void set_tankHealth() { player_health = 10; };
  virtual void set_playerHealth(int health) { player_health = health; };
  // Virtual destructor for tank
  virtual ~Tank(){};
};

#endif