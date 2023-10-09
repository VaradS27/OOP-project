#ifndef TANK_H
#define TANK_H

#include "movement.h"

class Tank : public Movement {
 protected:
  int p_health;
  int t_depth;
  int b_depth;

 public:
  Tank();  // Default constructor for Tank
  int getHealth();
};

#endif