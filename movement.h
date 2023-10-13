#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <random>

class Movement {
 public:
  Movement();  // default constructor
  virtual ~Movement() {};
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

 private:
  float x;
  float y;
  float rotation;
  float speed;
  float minX;  // Minimum X boundary
  float minY;  // Minimum Y boundary
  float maxX;  // Maximum X boundary
  float maxY;  // Maximum Y boundary
};

#endif