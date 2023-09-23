#include "background.h"
using namespace sf;
// Background image from :
// Tank Game Texture supplied by Credit "Kenney.nl" and "www.kenney.nl"
// https://opengameart.org/content/topdown-tanks
Background::Background() {
  // Set the size of the background
  backgroundRect.setSize(Vector2f(1920.0f, 1080.0f));
  backgroundRect.setPosition(0.0f, 0.0f);
  if (!backgroundTexture.loadFromFile("grassBackground.png")) {
    // handle error...
  }
  backgroundRect.setTexture(&backgroundTexture);
  backgroundTexture.setRepeated(true);
}

void Background::draw(RenderWindow& window) {
  // Draw the background to the window
  window.draw(backgroundRect);
}