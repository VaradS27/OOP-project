#include "playerOne.h"

#include <iostream>

#include "Shooting.h"
#include "cmath"
#include "math.h"
#include "movement.h"
using namespace sf;
// Tank Game Texture supplied by Credit "Kenney.nl" and "www.kenney.nl"
// https://opengameart.org/content/topdown-tanks
PlayerOne::PlayerOne() {
  // Set the size and color of the player's tank (blue rectangle)
  tankRect.setSize(Vector2f(50.0f, 50.0f));  // adjust the size as needed
  tankRect.setOrigin(tankRect.getSize().x / 2.0f, tankRect.getSize().y / 2.0f);

  // Set the size and color of the barrel (black rectangle)
  barrelRect.setSize(Vector2f(45.0f, 10.0f));  // adjust the size as needed
  barrelRect.setOrigin(barrelRect.getSize().x / 2.0f,
                       barrelRect.getSize().y / 2.0f);
  // Adjust the length of the barrel as needed
  barrelLength = 20.0f;

  if (!tankTexture.loadFromFile("tankBlue.png")) {
    // handle error...
  }
  if (!tankBarrelTexture.loadFromFile("tankBarrelBlue.png")) {
    // handle error...
  }

  tankTexture.setRepeated(true);
  tankRect.setTexture(&tankTexture);
  tankBarrelTexture.setRepeated(true);
  barrelRect.setTexture(&tankBarrelTexture);

  ammo = new Shooting[ammo_count];  // 1 bullet
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
  if (sf::Keyboard::isKeyPressed(Keyboard::E)) {
    p1.reload();  // reloads the ammo
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
      ammo[i].draw(&window);

      // Check if the bullet is off-screen
      Vector2f bulletPosition = ammo[i].getPosition();
      if (bulletPosition.x < 0 || bulletPosition.x > 1920 ||
          bulletPosition.y < 0 || bulletPosition.y > 1080) {
        ammo[i].reload();  // Reload the bullet if it's off-screen
      }
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
      float offset = barrelLength + 5;
      Vector2f bulletOffset(
          offset * cos(movement.getRotation() * M_PI / 180.f) * 1.8,
          offset * sin(movement.getRotation() * M_PI / 180.f) * 1.8);
      bulletPosition += bulletOffset;
      // Set the position and angle for the bullet
      ammo[i].useShot(bulletPosition, movement.getRotation());
      break;
    }
  }
}

// reload the ammo
void PlayerOne::reload() {
  for (int i = 0; i < ammo_count; i++) {
    if (ammo[i].isShot()) {
      // Check if the bullet is off-screen
      Vector2f bulletPosition = ammo[i].getPosition();
      if (bulletPosition.x < 0 || bulletPosition.x > 1920 ||
          bulletPosition.y < 0 || bulletPosition.y > 1080) {
        ammo[i].reload();  // Reload the bullet if it's off-screen
      }
    }
  }
}

// collison detection
void PlayerOne::health(PlayerOne p1) {
  if (p1.isHit()) {
    p_health--;
    std::cout << "Player 1 has health : " << p_health << std::endl;
  }
}

bool PlayerOne::isHit() {
  bool hit = false;
  int target_x = movement.getX();
  int target_y = movement.getY();

  Vector2f bulletPosition = ammo[0].getPosition();
  int x = bulletPosition.x;
  int y = bulletPosition.y;

  float distance =
      sqrt((x - target_x) * (x - target_x) + (y - target_y) * (y - target_y));
  if (distance < (t_depth + b_depth)) {
    hit = true;
  }
  return hit;
}