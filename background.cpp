#include "background.h"
using namespace sf;

Background::Background() {
  // Set the size and color of the background
  // Adjust the size in future as I currently have it set to 4:3 ratio
  // doubles btw
  backgroundRect.setSize(Vector2f(800.0f, 600.0f));
  backgroundRect.setFillColor(Color::Green);
  backgroundRect.setPosition(0.0f, 0.0f);
}

void Background::draw(sf::RenderWindow& window) {
  // Draw the background to the window
  window.draw(backgroundRect);
}