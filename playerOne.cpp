#include "playerOne.h"

#include <iostream>

#include "math.h"
#include "movement.h"
using namespace sf;

PlayerOne::PlayerOne() {
  // Set the size and color of the player's tank (blue rectangle)
  tankRect.setSize(Vector2f(50.0f, 30.0f));  // adjust the size as needed
  tankRect.setFillColor(Color::Blue);
  tankRect.setOutlineThickness(5.0f);  // thickness of outline
  tankRect.setOutlineColor(Color::Black);
  tankRect.setOrigin(tankRect.getSize().x / 2.0f, tankRect.getSize().y / 2.0f);

  // Set the size and color of the barrel (black rectangle)
  barrelRect.setSize(Vector2f(30.0f, 5.0f));  // adjust the size as needed
  barrelRect.setFillColor(Color::Black);
  barrelRect.setOrigin(0, barrelRect.getSize().y / 2.0f);

  // Adjust the length of the barrel as needed
  barrelLength = 20.0f;

  ammo = new Shooting[ammo_count];  // 1000 bullets
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

  // Calculate the position and rotation of the barrel
  float barrelX = movement.getX() +
                  barrelLength * cos(movement.getRotation() * M_PI / 180.f);
  float barrelY = movement.getY() +
                  barrelLength * sin(movement.getRotation() * M_PI / 180.f);
  barrelRect.setPosition(barrelX, barrelY);
  barrelRect.setRotation(movement.getRotation());

  // Draw the tank to the window
  window.draw(tankRect);
  // Draw the barrel of the tank to the window
  window.draw(barrelRect);
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
      // Calculate the initial position of the bullet based on the barrel
      Vector2f bulletPosition = barrelRect.getPosition();

      // Calculate an offset based on the length of the barrel
      float offset = barrelLength;
      Vector2f bulletOffset(
          offset * cos(movement.getRotation() * M_PI / 180.f),
          offset * sin(movement.getRotation() * M_PI / 180.f));
      bulletPosition += bulletOffset;

      // Set the position and angle for the bullet
      ammo[i].useShot(bulletPosition, movement.getRotation());
      break;
    }
  }
}