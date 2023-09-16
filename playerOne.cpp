#include "playerOne.h"

#include <iostream>

#include "movement.h"
using namespace sf;

PlayerOne::PlayerOne() {
  // Set the size and color of the player's tank (blue rectangle)
  tankRect.setSize(Vector2f(50.0f, 30.0f));  // adjust the size as needed
  tankRect.setFillColor(Color::Blue);
  // Sets the origin of the tank to its center - so it wont rotate from the
  // corner
  tankRect.setOrigin(tankRect.getSize().x / 2.0f, tankRect.getSize().y / 2.0f);
  // shooting ammo
  ammo = new Shooting[ammo_count];  // 100 bullets
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

void PlayerOne::ShootingInput(PlayerOne p1) {
  // Handles the player's input for shooting
  if (sf::Keyboard::isKeyPressed(Keyboard::Space)) {
    p1.fire();  // fire the bullet
  }
}
void PlayerOne::draw(RenderWindow& window) {
  // Update the tank's position and rotation
  tankRect.setPosition(movement.getX(), movement.getY());
  tankRect.setRotation(movement.getRotation());

  // Draw the tank to the window
  window.draw(tankRect);

  // Draw the bullets
  for (int i = 0; i < ammo_count; ++i) {
    if (ammo[i].isShot()) {
      ammo[i].move();
      ammo[i].draw(&window);  // could be an issue *check*
    }
  }
}

// shooting for player 1
void PlayerOne::fire() {
  for (int i = 0; i < ammo_count; ++i) {
    if (!ammo[i].isShot()) {
      ammo[i].useShot(tankRect.getPosition(), movement.getRotation());
      break;
    }
  }
}