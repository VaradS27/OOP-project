#include "Shooting.h"
#include "math.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Shooting::Shooting() {
  body = new CircleShape(5.0f);  // Changed from RectangleShape to CircleShape
  body->setFillColor(Color::White);  // Changed color to 'WHITE' for the bullet
  body->setOutlineThickness(5.0f);  // Set outline thickness
  body->setOutlineColor(Color::Black);  // Set outline color to 'BLACK'
  shot = false;
  bulletSpeed = 5.0f;
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

void Shooting::reload() {shot = false;}
bool Shooting::isShot() { return shot; }

void Shooting::useShot(Vector2f position, float tankRotation) {
  body->setPosition(position);
  shot = true;
  angle = tankRotation;
}

Shooting::~Shooting() {}