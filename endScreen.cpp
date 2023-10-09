#include "endScreen.h"

EndScreen::EndScreen(int width, int height) {
  // Load font (you can replace "arial.ttf" with your font file)
  font.loadFromFile("arial.ttf");

  // Set up end text
  endText.setFont(font);
  endText.setCharacterSize(48);
  endText.setFillColor(sf::Color::Red);
  endText.setString("Game Over");
  endText.setPosition(width / 2 - 150, height / 2 - 100);

  // Set up exit button
  exitButton.setFont(font);
  exitButton.setCharacterSize(24);
  exitButton.setFillColor(sf::Color::White);
  exitButton.setString(" Press ""Enter"" to Exit");
  exitButton.setPosition(width / 2 - 50,
                         height / 2);  // Adjust position as needed
}

void EndScreen::draw(sf::RenderWindow &window) {
  window.draw(endText);
  window.draw(exitButton);  // Draw the exit button
}
EndScreen::~EndScreen() {
  // Destructor (if needed)
}
