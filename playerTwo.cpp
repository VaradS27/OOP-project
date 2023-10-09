#include "playerTwo.h"

#include <iostream>

#include "Shooting.h"
#include "cmath"
#include "math.h"
#include "movement.h"
#include "playerOne.h"
using namespace sf;
// Tank Game Texture supplied by Credit "Kenney.nl" and "www.kenney.nl"
// https://opengameart.org/content/topdown-tanks
PlayerTwo::PlayerTwo() {
  // Set the size and color of the player's tank (blue rectangle)
  tankRect.setSize(Vector2f(50.0f, 50.0f));  // adjust the size as needed
  tankRect.setOrigin(tankRect.getSize().x / 2.0f, tankRect.getSize().y / 2.0f);

  // Set the size and color of the barrel (black rectangle)
  barrelRect.setSize(Vector2f(45.0f, 10.0f));  // adjust the size as needed
  barrelRect.setOrigin(barrelRect.getSize().x / 2.0f,
                       barrelRect.getSize().y / 2.0f);
  // Adjust the length of the barrel as needed
  barrelLength = 20.0f;

  if (!tankTexture.loadFromFile("tankRed.png")) {
    // handle error...
  }
  if (!tankBarrelTexture.loadFromFile("tankBarrelRed.png")) {
    // handle error...
  }

  tankTexture.setRepeated(true);
  tankRect.setTexture(&tankTexture);
  tankBarrelTexture.setRepeated(true);
  barrelRect.setTexture(&tankBarrelTexture);

  ammo = new Shooting[ammo_count];  // 1 bullet
  ammo[0].setBulletColor(Color::Red);
}

void PlayerTwo::handleInput() {
  // Handles the player's input for movement and rotation
  if (sf::Keyboard::isKeyPressed(Keyboard::Up)) {
    moveForward();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::Down)) {
    moveBackward();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::Left)) {
    rotateLeft();
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::Right)) {
    rotateRight();
  }
}

void PlayerTwo::ShootingInput(PlayerTwo p2) {
  // Handles the player's input for shooting
  if (sf::Keyboard::isKeyPressed(Keyboard::RShift)) {
    fire();  // fire the bullet
  }
  if (sf::Keyboard::isKeyPressed(Keyboard::P)) {
    reload();  // reloads the ammo
  }
}

void PlayerTwo::draw(RenderWindow& window) {
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
      if (bulletPosition.x < 0 || bulletPosition.x > 1200 ||
          bulletPosition.y < 0 || bulletPosition.y > 1000) {
        ammo[i].reload();  // Reload the bullet if it's off-screen
      }
    }
  }
}

// shooting for player 2
void PlayerTwo::fire() {
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
void PlayerTwo::reload() {
  for (int i = 0; i < ammo_count; i++) {
    if (ammo[i].isShot()) {
      // Check if the bullet is off-screen
      Vector2f bulletPosition = ammo[i].getPosition();
      if (bulletPosition.x < 0 || bulletPosition.x > 1200 ||
          bulletPosition.y < 0 || bulletPosition.y > 1000) {
        ammo[i].reload();  // Reload the bullet if it's off-screen
      }
    }
  }
}

// collison detection
void PlayerTwo::health(PlayerTwo p2, PlayerOne p1) {
  if (isHit(p2, p1)) {
    p_health--;
    std::cout << "Red Tank has " << p_health << " health!" << std::endl;
  }
}

bool PlayerTwo::isHit(PlayerTwo& p2, PlayerOne& p1) {
  bool hit = false;
  int target_x = getX();
  int target_y = getY();

  // Check for collisions with PlayerOne's bullets
  for (int i = 0; i < ammo_count; i++) {
    if (p1.getAmmo()[i].isShot()) {
      Vector2f bulletPosition = p1.getAmmo()[i].getPosition();
      int x = bulletPosition.x;
      int y = bulletPosition.y;

      float distance = sqrt((x - target_x) * (x - target_x) +
                            (y - target_y) * (y - target_y));
      if (distance < (t_depth + b_depth)) {
        hit = true;
        p1.getAmmo()[i].reload();  // Make the bullet disappear
        break;  // No need to check further if a collision is detected
      }
    }
  }
  return hit;
}

float PlayerTwo::clamp(float value, float minn, float maxx) {
  if (value < minn) {
    return minn;
  } else if (value > maxx) {
    return maxx;
  } else {
    return value;
  }
}

int PlayerTwo::collision(PlayerTwo& R1) {
  // find the closest point of the circle to rectangle
  float closestX = clamp(600, getX(), getX() - 50);
  float closestY = clamp(500, getY(), getY() - 20);

  // get the distance between the two points
  float distanceX = 600 - closestX;
  float distanceY = 500 - closestY;

  // checking the conditions are met and collision occurs, return 1
  float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
  if (distanceSquared < 400 && closestX != 600 && closestY != 500) {
    return 3;
  } else if (distanceSquared < 400 && closestX == 600) {
    return 2;
  } else if (distanceSquared < 400 && closestY == 500) {
    return 1;
  } else {
    return 0;  // no collision hence return 0
  }
}

void PlayerTwo::collideHealth(PlayerTwo& R1) {
  if (collision(R1) == 3 || collision(R1) == 2 || collision(R1) == 1) {
    p_health--;
    std::cout << "Red Tank lost health, remaining health : " << p_health
              << std::endl;
  }
}