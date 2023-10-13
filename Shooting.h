#ifndef SHOOT_H
#define SHOOT_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Shooting {
 private:
  CircleShape* body;  // Changed from RectangleShape* to CircleShape*
  // CircleShape* body2;
  bool shot;          // checks if tank has already shot
  float angle;        // angle of bullet
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
  Vector2f getPosition() { return body->getPosition(); }
  void setBulletColor(const Color& color) { body->setFillColor(color); };
  CircleShape* getBody() { return body; };
};

#endif