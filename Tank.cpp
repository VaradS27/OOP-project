#include "Tank.h"

// Set playerOne's and playerTwo's default health, tdepth (hitbox of tank),
// bdepth (hitbox of bullet)
Tank::Tank() {
  set_health();
  set_tdepth();
  set_bdepth();
}