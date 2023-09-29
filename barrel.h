#ifndef BARREL_H
#define BARREL_H
#include <SFML/Graphics.hpp>
using namespace sf;
class Barrel {
 public:
  Barrel(float x, float y);
  void draw(RenderWindow& window);
  FloatRect getBounds();

 private:
  RectangleShape shape;
  static Texture texture;
};
#endif