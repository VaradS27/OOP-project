#include "background.h"

#include <iostream>
using namespace sf;
// Background image from :
// https://www.freepik.com/free-photo/green-clay-textured-background-colorful-handmade-creative-art-abstract-style_18141576.htm#page=2&query=low%20poly%20grass%20texture&position=1&from_view=search&track=ais
// by rawpixel.com on Freepik
Background::Background() {
  // Set the size of the background
  backgroundRect.setSize(Vector2f(900.0f, 1000.0f));
  // Set the position of the background
  backgroundRect.setPosition(0.0f, 0.0f);
  // Check if textures have not loaded
  if (!backgroundTexture.loadFromFile("GameBackground.png")) {
    // Send error message if not loaded in terminal
    std::cout << "Error: Game Background did not load" << std::endl;
  }
  // Set background texture
  backgroundRect.setTexture(&backgroundTexture);
  backgroundTexture.setRepeated(true);
}

void Background::draw(RenderWindow& window) {
  // Draw the background to the window
  window.draw(backgroundRect);
}