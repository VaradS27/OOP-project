#ifndef CHARACTER_H
#define CHARACTER_H
#include "Cell.h"
class Character : public Cell {
 public:
  Character(int x, int y) : Cell(x, y, 'C') {}

  void move(int dx, int dy) {
    int newX = std::get<0>(position) + dx;
    int newY = std::get<1>(position) + dy;
    setPos(newX, newY);
  }
};
#endif