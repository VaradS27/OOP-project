#include "playerTwo.h"

#include <iostream>

#include "math.h"
#include "movement.h"
using namespace sf;
// Tank Game Texture supplied by Credit "Kenney.nl" and "www.kenney.nl"
// https://opengameart.org/content/topdown-tanks
PlayerTwo::PlayerTwo() {
  // Set the size and color of the player's tank (blue rectangle)
  tank2Rect.setSize(Vector2f(50.0f, 50.0f));  // adjust the size as needed
  tank2Rect.setOrigin(tank2Rect.getSize().x / 2.0f, tank2Rect.getSize().y / 2.0f);

  // Set the size and color of the barrel (black rectangle)
  barrel2Rect.setSize(Vector2f(45.0f, 10.0f));  // adjust the size as needed
  barrel2Rect.setOrigin(barrel2Rect.getSize().x / 2.0f, barrel2Rect.getSize().y / 2.0f);
  // Adjust the length of the barrel as needed
  barrel2Length = 20.0f;

  if (!tankTexture.loadFromFile("tankRed.png")) {
    // handle error...
  }
  if (!tankBarrelTexture.loadFromFile("tankBarrelRed.png")) {
    // handle error...
  }

  tankTexture.setRepeated(true);
  tank2Rect.setTexture(&tankTexture);
  tankBarrelTexture.setRepeated(true);
  barrel2Rect.setTexture(&tankBarrelTexture);

  ammo = new Shooting[ammo_count];  // 1000 bullets
}

void PlayerTwo::handleInput() {
  // Handles the player's input for movement and rotation
  if (Keyboard::isKeyPressed(Keyboard::Up)) {
    movement.moveForward();
  }
  if (Keyboard::isKeyPressed(Keyboard::Down)) {
    movement.moveBackward();
  }
  if (Keyboard::isKeyPressed(Keyboard::Left)) {
    movement.rotateLeft();
  }
  if (Keyboard::isKeyPressed(Keyboard::Right)) {
    movement.rotateRight();
  }
}

void PlayerTwo::ShootingInput(PlayerTwo p2) {
  // Handles the player's input for shooting
  if (Keyboard::isKeyPressed(Keyboard::LShift)) {
    p2.fire();  // fire the bullet
  }
}

void PlayerTwo::draw(RenderWindow& window) {
  // Update the tank's position and rotation
  tank2Rect.setPosition(movement.getX(), movement.getY());
  tank2Rect.setRotation(movement.getRotation());

  // Calculate the position and rotation of the barrel
  float barrelX = movement.getX() +
                  barrel2Length * cos(movement.getRotation() * M_PI / 180.f);
  float barrelY = movement.getY() +
                  barrel2Length * sin(movement.getRotation() * M_PI / 180.f);
  barrel2Rect.setPosition(barrelX, barrelY);
  barrel2Rect.setRotation(movement.getRotation());

  // Draw the tank to the window
  window.draw(tank2Rect);
  // Draw the barrel of the tank to the window
  window.draw(barrel2Rect);
  // Draw the bullets
  for (int i = 0; i < ammo_count; ++i) {
    if (ammo[i].isShot()) {
      ammo[i].move();
      ammo[i].draw(&window);  // could be an issue *check*
    }
  }
}

// shooting for player 1
void PlayerTwo::fire() {
  for (int i = 0; i < ammo_count; ++i) {
    if (!ammo[i].isShot()) {
      // Calculate the initial position of the bullet based on the barrel
      Vector2f bulletPosition = barrel2Rect.getPosition();

      // Calculate an offset based on the length of the barrel
      float offset = barrel2Length;
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