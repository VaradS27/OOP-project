#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <random>

class Movement {
 private:
  // x and y value of tanks
  float x;
  float y;
  // rotation of tank
  float rotation;
  // speed of tank
  float speed;
  float minX;  // Minimum X boundary
  float minY;  // Minimum Y boundary
  float maxX;  // Maximum X boundary
  float maxY;  // Maximum Y boundary
 public:
  Movement();  // default constructor
  virtual ~Movement(){}; // virtual destructor
  // movement inputs
  void moveForward();
  void moveBackward();
  void rotateLeft();
  void rotateRight();
  // boundaries for tanks - make sure they don't go outside the map
  void setBounds(float minX, float minY, float maxX, float maxY);
  // update boundaries if needed
  void updateBounds();
  // get x and y values of tank
  float getX();
  float getY();
  // get rotation of tank
  float getRotation();
  // generate a random location for tank
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