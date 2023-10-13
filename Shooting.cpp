#include "Shooting.h"

#include <SFML/Graphics.hpp>

#include "math.h"
using namespace sf;

Shooting::Shooting() {
  // CircleShape for circle bullets - size is 5.0f
  body = new CircleShape(5.0f);
  // default colour of is white for testing - will be blue or red depending on
  // who shot the bullet
  body->setFillColor(Color::White);
  body->setOutlineThickness(5.0f);      // Set outline thickness
  body->setOutlineColor(Color::Black);  // Set outline color to 'BLACK'
  shot = false;
  // Bullet speed
  bulletSpeed = 10.0f;
}

void Shooting::draw(RenderWindow* win) {
  win->draw(*body);  // draws the bullet
}

// Set bullet position
void Shooting::set_position(Vector2f position) { body->setPosition(position); }

// move the bullet depending on the angle of the tank's direction
void Shooting::move() {
  float angleRad = angle * M_PI / 180.f;
  float moveX = bulletSpeed * cos(angleRad);
  float moveY = bulletSpeed * sin(angleRad);
  body->move(moveX, moveY);
}

void Shooting::reload() { shot = false; }

// Checks if tank has already shot
bool Shooting::isShot() { return shot; }
void Shooting::useShot(Vector2f position, float tankRotation) {
  body->setPosition(position);
  shot = true;
  angle = tankRotation;
}

Shooting::~Shooting() {}