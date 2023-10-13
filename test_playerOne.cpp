#include <iostream>

#include "playerOne.h"

void testPlayerOneInitialisation() {
  PlayerOne p1;

  // Test tank size
  sf::Vector2f tankSize = p1.get_tankRect().getSize();
  if (tankSize.x != 50.0f || tankSize.y != 50.0f) {
    std::cout << "Tank size test failed!" << std::endl;
  }

  // Test barrel size
  sf::Vector2f barrelSize = p1.get_barrelRect().getSize();
  if (barrelSize.x != 45.0f || barrelSize.y != 10.0f) {
    std::cout << "Barrel size test failed!" << std::endl;
  }

  // Test ammo
  if (p1.getAmmo() == nullptr) {
    std::cout << "Ammo test failed!" << std::endl;
  }
}

int main() {
  testPlayerOneInitialisation();
  return 0;
}
