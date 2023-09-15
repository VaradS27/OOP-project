#include "playerOne.h"

#include <iostream>
using namespace sf;

PlayerOne::PlayerOne() {
  // Set the size and color of the player's tank (blue rectangle)
  tankRect.setSize(Vector2f(50.0f, 30.0f));  // adjust the size as needed
  tankRect.setFillColor(Color::Blue);
  // Sets the origin of the tank to its center - so it wont rotate from the
  // corner
  tankRect.setOrigin(tankRect.getSize().x / 2.0f, tankRect.getSize().y / 2.0f);

  // * Note: To adjust the starting position, it must be done in the
  // movement.cpp file in the default constructor *
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

  // Draw the tank to the window
  window.draw(tankRect);
}