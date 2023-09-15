#include "movement.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

// Constructor initializes the position, rotation and speed
Movement::Movement() : x(400), y(300), rotation(0), speed(5.0f) {}

// Moves the object forward in the direction it's facing
void Movement::moveForward() {
  float angle = rotation * 3.14159265f / 180.f; // Convert rotation from degrees to radians
  float moveX = speed * cos(angle); // Calculate movement in x direction
  float moveY = speed * sin(angle); // Calculate movement in y direction
  x = x + moveX; // Update x position
  y = y + moveY; // Update y position
}

// Moves the object backward in the direction it's facing
void Movement::moveBackward() {
  float angle = rotation * 3.14159265f / 180.f; // Convert rotation from degrees to radians
  float moveX = speed * cos(angle); //  movement in x direction
  float moveY = speed * sin(angle); // movement in y direction
  x = x - moveX; // Update x position
  y = y - moveY; // Update y position
}

// Rotates the object to the left
void Movement::rotateLeft() {
  float rotateAmount = 3.0f; // rotation amount
  rotation = rotation - rotateAmount; // Decrease rotation
  if (rotation < 0.0f) { // rotation is negative, make it positive by adding 360
    rotation = rotation + 360.0f;
  }
}

// Rotates the object to the right
void Movement::rotateRight() {
  float rotateAmount = 3.0f; // rotation amount
  rotation = rotation + rotateAmount; // Increase rotation
  if (rotation >= 360.0f) { // rotation is greater than or equal to 360, subtract 360 to keep it within [0,360)
    rotation = rotation - 360.0f;
  }
}

// Getter for x position
float Movement::getX() { return x; }

// Getter for y position
float Movement::getY() { return y; }

// Getter for rotation
float Movement::getRotation() { return rotation; }
