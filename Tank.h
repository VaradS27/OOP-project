#ifndef TANK_H
#define TANK_H

#include "movement.h"

class Tank : public Movement {
 protected:
  int p_health; // player health - will be set to 10
  int t_depth; // tank hitbox - will be set to 35
  int b_depth; // bullet hitbox - will be set to 5

 public:
  Tank();  // Default constructor for Tank
  // Getters and setters for tank abstract class:
  virtual int getHealth() { return 0; }
  virtual void set_tdepth() { t_depth = 35; };
  virtual void set_bdepth() { b_depth = 5; };
  virtual void set_health() { p_health = 10; };
  virtual void set_playerHealth(int health) { p_health = health; };
  // Virtual destructor for tank
  virtual ~Tank(){};
};

#endif