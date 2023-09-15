#include "playerOne.h"

#include <iostream>

#include "math.h"
using namespace sf;

PlayerOne::PlayerOne() {
  // Set the size and color of the player's tank (blue rectangle)
  tankRect.setSize(Vector2f(50.0f, 30.0f));  // adjust the size as needed
  tankRect.setFillColor(Color::Blue);
  tankRect.setOutlineThickness(5.0f);  // thickness of outline
  tankRect.setOutlineColor(Color::Black);
  tankRect.setOrigin(tankRect.getSize().x / 2.0f, tankRect.getSize().y / 2.0f);
  // * Note: To adjust the starting position, it must be done in the
  // movement.cpp file in the default constructor *

  // Set the size and color of the barrel (black rectangle)
  barrelRect.setSize(Vector2f(30.0f, 5.0f));  // adjust the size as needed
  barrelRect.setFillColor(Color::Black);
  barrelRect.setOrigin(0, barrelRect.getSize().y / 2.0f);

  barrelLength = 20.0f;  // Adjust the length of the barrel as needed
}

void PlayerOne::handleInput() {
  // Handles the player's input for movement and rotation
  if (sf::Keyboard::isKeyPressed(Keyboard::W)) {
    movement.moveForward();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::S)) {
    movement.moveBackward();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::A)) {
    movement.rotateLeft();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::D)) {
    movement.rotateRight();
  }
}

void PlayerOne::draw(RenderWindow& window) {
  // Update the tank's position and rotation
  tankRect.setPosition(movement.getX(), movement.getY());
  tankRect.setRotation(movement.getRotation());

  // Calculate the position and rotation of the barrel
  float barrelX = movement.getX() + barrelLength * cos(movement.getRotation() *
                                                       3.14159265f / 180.f);
  float barrelY = movement.getY() + barrelLength * sin(movement.getRotation() *
                                                       3.14159265f / 180.f);
  barrelRect.setPosition(barrelX, barrelY);
  barrelRect.setRotation(movement.getRotation());

  // Draw the tank to the window
  window.draw(tankRect);
  window.draw(barrelRect);
}