#include <SFML/Graphics.hpp>
using namespace sf;

class Shooting {
 private:
  RectangleShape* body;
  bool shot;
  float angle;
  float bulletSpeed;

 public:
  Shooting();                                // default constuctor
  void draw(RenderWindow* win);          // draws the bullets
  void set_position(Vector2f position);  // sets the position of the bullets
                                             // same as the tanks
  void move();                               // speed of the bullet
  bool isShot();                             // check if the bullet is fired
  // shoting the bullet
  void useShot(Vector2f position, float tankRotation);
  ~Shooting();
};