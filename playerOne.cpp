#include "playerOne.h"

#include <iostream>

#include "Shooting.h"
#include "cmath"
#include "math.h"
#include "movement.h"
#include "playerTwo.h"
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

  // Check if the following textures loaded:
  if (!tankTexture.loadFromFile("tankBlue.png")) {
    std::cout << "Error: Blue tank texture did not load" << std::endl;
  }
  if (!tankBarrelTexture.loadFromFile("tankBarrelBlue.png")) {
    std::cout << "Error: Blue tank barrel texture did not load" << std::endl;
  }
  // Set tank and barrel textures
  tankTexture.setRepeated(true);
  tankRect.setTexture(&tankTexture);
  tankBarrelTexture.setRepeated(true);
  barrelRect.setTexture(&tankBarrelTexture);
  // add an ammo array
  ammo = new Shooting[ammo_count];  // 1 bullet
  // Set colour for bullet to blue (as it is a blue tank)
  ammo[0].setBulletColor(Color::Blue);
}

void PlayerOne::handleInput() {
  // Handles the player's input for movement and rotation
  if (sf::Keyboard::isKeyPressed(Keyboard::W)) {
    moveForward();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::S)) {
    moveBackward();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::A)) {
    rotateLeft();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::D)) {
    rotateRight();
  }
}

void PlayerOne::ShootingInput(PlayerOne p1) {
  // Handles the player's input for shooting
  if (sf::Keyboard::isKeyPressed(Keyboard::Space)) {
    fire();  // fire the bullet
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::E)) {
    reload();  // reloads the ammo
  }
}

void PlayerOne::draw(RenderWindow& window) {
  // Update the tank's position and rotation
  tankRect.setPosition(getX(), getY());
  tankRect.setRotation(getRotation());

  // Calculate the position and rotation of the barrel
  float barrelX = getX() + barrelLength * cos(getRotation() * M_PI / 180.f);
  float barrelY = getY() + barrelLength * sin(getRotation() * M_PI / 180.f);
  barrelRect.setPosition(barrelX, barrelY);
  barrelRect.setRotation(getRotation());

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
      if (bulletPosition.x < 0 || bulletPosition.x > 900 ||
          bulletPosition.y < 0 || bulletPosition.y > 1000) {
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
      Vector2f bulletOffset(offset * cos(getRotation() * M_PI / 180.f),
                            offset * sin(getRotation() * M_PI / 180.f));
      bulletPosition += bulletOffset;
      // Set the position and angle for the bullet
      ammo[i].useShot(bulletPosition, getRotation());
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
      if (bulletPosition.x < 0 || bulletPosition.x > 900 ||
          bulletPosition.y < 0 || bulletPosition.y > 1000) {
        ammo[i].reload();  // Reload the bullet if it's off-screen
      }
    }
  }
}

// collison detection
void PlayerOne::health(PlayerOne p1, PlayerTwo p2) {
  // If blue tank is hit by red bullet, then blue tank will take one damage of
  // health
  if (isHit(p1, p2)) {
    p_health--;
    std::cout << "Blue Tank has " << p_health << " health!" << std::endl;
  }
}

bool PlayerOne::isHit(PlayerOne& p1, PlayerTwo& p2) {
  bool hit = false;
  int target_x = getX();
  int target_y = getY();

  // Check for collisions with PlayerTwo's bullets
  if (!hit) {
    for (int i = 0; i < ammo_count; i++) {
      if (p2.getAmmo()[i].isShot()) {
        // Get bullet position
        Vector2f bulletPosition = p2.getAmmo()[i].getPosition();
        int x = bulletPosition.x;
        int y = bulletPosition.y;
        float distance = sqrt((x - target_x) * (x - target_x) +
                              (y - target_y) * (y - target_y));
        // Red bullet has hit the blue tank, run the following code:
        if (distance < (t_depth + b_depth)) {
          hit = true;
          p2.getAmmo()[i].reload();  // Make the bullet disappear
          break;  // No need to check further if a collision is detected
        }
      }
    }
  }
  return hit;
}

// PlayerOne::~PlayerOne() {
//   if (ammo) {
//     delete[] ammo;
//     //ammo = nullptr;
//   }
// }
