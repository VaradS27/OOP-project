#include "Shooting.h"
#include "math.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Shooting::Shooting() {
  body = new sf::RectangleShape(Vector2f(5, 5));
  body->setFillColor(sf::Color(255, 0, 0));  // color 'RED' for the bullet
  shot = false;
  bulletSpeed = 2.0f;
}

void Shooting::draw(RenderWindow* win) {
  win->draw(*body);  // draws the bullet
}

void Shooting::set_position(Vector2f position) {
  body->setPosition(position);
}

void Shooting::move() {
  float angleRad = angle * M_PI / 180.f;
  float moveX = bulletSpeed * cos(angleRad);
  float moveY = bulletSpeed * sin(angleRad);
  body->move(moveX, moveY);
}

bool Shooting::isShot() { return shot; }

void Shooting::useShot(Vector2f position, float tankRotation) {
  body->setPosition(position);
  shot = true;
  angle = tankRotation;
}

Shooting::~Shooting() {}