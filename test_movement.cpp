#include <iostream>

#include "movement.h"

void testMovement() {
  Movement movement;

  // Initial position should be within the specified boundaries
  float initialX = movement.getX();
  float initialY = movement.getY();
  float initialRotation = movement.getRotation();

  if (initialX < 0 || initialX > 900 || initialY < 0 || initialY > 1000) {
    std::cerr << "Initial position is not within the specified boundaries."
              << std::endl;
  }

  // Test moveForward and moveBackward
  movement.moveForward();
  float newX = movement.getX();
  float newY = movement.getY();
  if (newX == initialX && newY == initialY) {
    std::cerr << "moveForward did not change position." << std::endl;
  }

  movement.moveBackward();
  float finalX = movement.getX();
  float finalY = movement.getY();
  if (finalX != initialX || finalY != initialY) {
    std::cerr << "moveBackward did not return to the initial position."
              << std::endl;
  }

  // Test rotateLeft and rotateRight
  movement.rotateLeft();
  float rotatedLeft = movement.getRotation();
  if (rotatedLeft != initialRotation - 3.0f) {
    std::cerr << "rotateLeft did not update the rotation correctly."
              << std::endl;
  }

  movement.rotateRight();
  float rotatedRight = movement.getRotation();
  if (rotatedRight != initialRotation) {
    std::cerr << "rotateRight did not update the rotation correctly."
              << std::endl;
  }

  // Output test results
  if (std::cerr.tellp() == 0) {
    std::cout << "All tests passed." << std::endl;
  } else {
    std::cerr << "Some tests failed." << std::endl;
  }
}

int main() {
  testMovement();
  return 0;
}