#include "movement.h"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <random>

#include "math.h"
using namespace std;
using namespace sf;

Movement::Movement()
    : x(400),
      y(300),
      rotation(0),
      speed(5.0f),
      minX(0),
      minY(0),
      maxX(800),
      maxY(800) {
  // Create a random device
  random_device rd;

  // Initialize a random number generator engine
  default_random_engine eng(rd());

  // Define the distribution
  uniform_real_distribution<float> distrX(0.0, 800.0);
  uniform_real_distribution<float> distrY(0.0, 800.0);

  // Generate random x and y coordinates within the boundaries
  x = distrX(eng);
  y = distrY(eng);
}
// change maxX and maxY if we change the size of the game

void Movement::moveForward() {
  // Calculate new position after moving forward
  float newX = x + speed * cos(rotation * M_PI / 180.f);
  float newY = y + speed * sin(rotation * M_PI / 180.f);

  // Check if the new position is within the boundaries
  if (newX >= minX && newX <= maxX && newY >= minY && newY <= maxY) {
    x = newX;
    y = newY;
  }
}

void Movement::moveBackward() {
  // Calculate new position after moving backward
  float newX = x - speed * cos(rotation * M_PI / 180.f);
  float newY = y - speed * sin(rotation * M_PI / 180.f);

  // Check if the new position is within the boundaries
  if (newX >= minX && newX <= maxX && newY >= minY && newY <= maxY) {
    x = newX;
    y = newY;
  }
}

void Movement::rotateLeft() {
  rotation -= 3.0f;
  if (rotation < 0.0f) {
    rotation += 360.0f;
  }
}

void Movement::rotateRight() {
  rotation += 3.0f;
  if (rotation >= 360.0f) {
    rotation -= 360.0f;
  }
}

void Movement::setBounds(float minX, float minY, float maxX, float maxY) {
  this->minX = minX;
  this->minY = minY;
  this->maxX = maxX;
  this->maxY = maxY;
}

void Movement::updateBounds() {}

// Getter for x position
float Movement::getX() { return x; }
// Getter for y position
float Movement::getY() { return y; }
// Getter for rotation
float Movement::getRotation() { return rotation; }