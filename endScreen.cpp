#include "endScreen.h"
using namespace sf;

EndScreen::EndScreen(int width, int height) {

  // Background for the end screen
  endBackground.setSize(Vector2f(900.0f, 1000.0f));
  endBackground.setPosition(0.0f, 0.0f);
  if (!endBack.loadFromFile("EndBackground.png")) {
    // handle error...
  }
  endBackground.setTexture(&endBack);
  endBack.setRepeated(true);
  // Load font
  font.loadFromFile("MarsBold.ttf");


  // Set up end text
  endText.setFont(font);
  endText.setCharacterSize(64);
  endText.setFillColor(sf::Color::Red);
  endText.setString("Game Over");
  endText.setPosition(width / 2 - 375, height / 2 - 200);

  // Set up exit button
  exitButton.setFont(font);
  exitButton.setCharacterSize(30);
  exitButton.setFillColor(sf::Color::Red);
  exitButton.setString(" Press ""Enter"" to Exit");
  exitButton.setPosition(width / 2 - 350, height / 2 - 100);  // Adjust position as needed
}

void EndScreen::draw(sf::RenderWindow &window) {
  window.draw(endBackground);
  window.draw(endText);
  window.draw(exitButton);  // Draw the exit button
}
EndScreen::~EndScreen() {
  // Destructor (if needed)
}
