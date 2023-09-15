#ifndef MOVEMENT_H
#define MOVEMENT_H

class Movement {
 public:
  Movement(); // default constructor for movement
  void moveForward();
  void moveBackward();
  void rotateLeft();
  void rotateRight();
  float getX();
  float getY();
  float getRotation();

 private:
  float x;
  float y;
  float rotation;
  float speed;
};

#endif