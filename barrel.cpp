#include "barrel.h"
#include <iostream>

Texture Barrel::texture; // Define texture outside the class

Barrel::Barrel(float x, float y) {
  shape = RectangleShape(Vector2f(30, 25));

  // Load the texture from a file only if it hasn't been loaded yet
  if (texture.getSize().x == 0) { // texture not loaded yet
    if (!texture.loadFromFile("barrel.png")) {
      std::cout << "Error loading texture" << std::endl;
    }
  }

  // Set the shape's texture
  shape.setTexture(&texture);

  // Set the shape's position
  shape.setPosition(x, y);
}

void Barrel::draw(RenderWindow& window) {
  // Draw the shape to the window
  window.draw(shape);
}

FloatRect Barrel::getBounds() { return shape.getGlobalBounds(); }