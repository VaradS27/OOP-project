#include <cassert>
#include <iostream>

#include "Shooting.h"

// Test Cases were inspired by this website:
// https://cunit.sourceforge.net/doc/writing_tests.html

int main() {
  // RenderWindow
  sf::RenderWindow window(sf::VideoMode(800, 600), "Shooting Test");

  // Create an instance of the Shooting class
  Shooting shooting;

  // Test the constructor
  assert(shooting.isShot() == false);

  // Set the position and test the set_position method
  sf::Vector2f position(100.0f, 100.0f);
  shooting.set_position(position);
  assert(shooting.isShot() == false);

  // Test the draw method
  shooting.draw(&window);

  // Test the useShot method
  float tankRotation = 45.0f;  // Example tank rotation angle
  shooting.useShot(position, tankRotation);
  assert(shooting.isShot() == true);

  // Test the move method (you may need to adapt this part)
  shooting.move();
  sf::Vector2f newPosition = shooting.getBody()->getPosition();
  assert(newPosition != position);  // Bullet position should have changed

  // Test the reload method
  shooting.reload();
  assert(shooting.isShot() == false);

  // Clean up
  window.close();

  std::cout << "All tests passed!" << std::endl;

  return 0;
}