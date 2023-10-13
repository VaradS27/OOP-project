#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <random>

// The Movement class is all about controlling how the tanks move around in the
// game. It keeps track of the tank’s position (x, y), rotation (rotation), and
// speed (speed). The moveForward(), moveBackward(), rotateLeft(), and
// rotateRight() methods are used to change the tank’s position and rotation
// based on user input. The class also makes sure the tanks don’t go outside the
// game map by setting boundaries (minX, minY, maxX, maxY) with setBounds() and
// updating them with updateBounds(). You can get the current position and
// rotation of the tank with getX(), getY(), and getRotation(). There’s also a
// cool feature where it can generate a random location for the tank with
// randomFloat().

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
  Movement();             // default constructor
  virtual ~Movement(){};  // virtual destructor
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