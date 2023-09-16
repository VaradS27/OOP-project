#include "background.h"
using namespace sf;

Background::Background() {
  // Set the size and color of the background
  // Adjust the size in future as I currently have it set to 4:3 ratio
  // doubles btw
  backgroundRect.setSize(Vector2f(1920.0f, 1080.0f));
  backgroundRect.setFillColor(Color::Green);
  backgroundRect.setPosition(0.0f, 0.0f);
  backgroundRect.setOutlineThickness(5.0f);  // thickness of outline
  backgroundRect.setOutlineColor(Color::Black);
}

void Background::draw(RenderWindow& window) {
  // Draw the background to the window
  window.draw(backgroundRect);
}