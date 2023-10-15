#ifndef SHOOT_H
#define SHOOT_H

#include <SFML/Graphics.hpp>
using namespace sf;

// The Shooting class is all about managing the bullets in the game. It keeps
// track of the bullet’s shape (body), whether it’s been fired (shot), its angle
// (angle), and its speed (bulletSpeed). The draw method puts the bullet on the
// game window, and set_position sets the bullet’s starting position to match
// the tank’s position. The move method updates the bullet’s position based on
// its speed, and isShot checks if the bullet has been fired. The useShot method
// fires a bullet at a certain angle, and reload prepares the tank to fire
// again. There are also some methods for getting and setting properties of the
// bullet, which are useful for testing.

class Shooting {
 private:
  CircleShape* body_bullet;  // Changed from RectangleShape* to CircleShape*
  // CircleShape* body2;
  bool shot;          // checks if tank has already shot
  float bulletAngle;        // angle of bullet
  float bulletSpeed;  // bullet speed

 public:
  Shooting();                    // default constuctor
  void draw(RenderWindow* win);  // draws the bullets
  // sets the position of the bullets same as the tanks
  void set_position(Vector2f position);
  void move();    // speed of the bullet
  bool isShot();  // check if the bullet is fired
  // shoting the bullet
  void useShot(Vector2f position, float tankRotation);
  void reload();
  ~Shooting();

  // Used for unit testing (getters and setters):
  Vector2f getPosition() { return body_bullet->getPosition(); }
  void setBulletColor(const Color& color) { body_bullet->setFillColor(color); };
  CircleShape* getBody() { return body_bullet; };
};

#endif