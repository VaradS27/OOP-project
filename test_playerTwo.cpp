#include <iostream>
#include "playerTwo.h"

void testPlayerTwoInitialisation() {
  PlayerTwo p2;

  // Test tank size
  sf::Vector2f tankSize = p2.get_tankRect().getSize();
  if (tankSize.x != 50.0f || tankSize.y != 50.0f) {
    std::cout << "Tank size test failed!" << std::endl;
  }

  // Test barrel size
  sf::Vector2f barrelSize = p2.get_barrelRect().getSize();
  if (barrelSize.x != 45.0f || barrelSize.y != 10.0f) {
    std::cout << "Barrel size test failed!" << std::endl;
  }

  // Test ammo
  if (p2.getAmmo() == nullptr) {
    std::cout << "Ammo test failed!" << std::endl;
  }
}

int main() {
  testPlayerTwoInitialisation();
  return 0;
}
