#include "Tank.h"

// Set playerOne's and playerTwo's default health, tdepth (hitbox of tank),
// bdepth (hitbox of bullet)
Tank::Tank() {
  set_tankHealth();
  set_tankDepth();
  set_bulletDepth();
}