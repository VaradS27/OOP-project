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
  virtual int getHealth(){return 0;}
  virtual void set_tdepth(){t_depth = 35;};
  virtual void set_bdepth(){b_depth = 5;};
  virtual void set_health(){p_health = 10;};
};

#endif