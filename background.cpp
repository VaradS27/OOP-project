#include "background.h"
using namespace sf;
// Background image from :
// https://www.freepik.com/free-photo/green-clay-textured-background-colorful-handmade-creative-art-abstract-style_18141576.htm#page=2&query=low%20poly%20grass%20texture&position=1&from_view=search&track=ais
// by rawpixel.com on Freepik
Background::Background() {
  // Set the size of the background
  backgroundRect.setSize(Vector2f(1200.0f, 1000.0f));
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