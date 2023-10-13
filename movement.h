#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <random>

class Movement {
 private:
  float x;
  float y;
  float rotation;
  float speed;
  float minX;  // Minimum X boundary
  float minY;  // Minimum Y boundary
  float maxX;  // Maximum X boundary
  float maxY;  // Maximum Y boundary
 public:
  Movement();  // default constructor
  virtual ~Movement(){};
  void moveForward();
  void moveBackward();
  void rotateLeft();
  void rotateRight();
  void setBounds(float minX, float minY, float maxX, float maxY);
  void updateBounds();
  float getX();
  float getY();
  float getRotation();
  float randomFloat(float min, float max);
  // Setter functions for position and rotation
  void set_playerPosition(float x, float y) {
    // Set the tank's position to (x, y)
    this->x = x;
    this->y = y;
  }
  void set_playerRotation(float rotation) {
    // Set the tank's rotation to the specified angle (in degrees)
    this->rotation = rotation;
  }
};

#endif