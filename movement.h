#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "barrel.h"
class Movement {
public:
    Movement(); // default constructor
    void moveForward();
    void moveBackward();
    void rotateLeft();
    void rotateRight();
    void setBounds(float minX, float minY, float maxX, float maxY);
    void updateBounds();
    float getX();
    float getY();
    float getRotation();

private:
    float x;
    float y;
    float rotation;
    float speed;
    float minX; // Minimum X boundary
    float minY; // Minimum Y boundary
    float maxX; // Maximum X boundary
    float maxY; // Maximum Y boundary
};

#endif