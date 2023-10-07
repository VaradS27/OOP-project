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

  // Set up buttons
  buttons[0].setFont(font);
  buttons[0].setCharacterSize(24);
  buttons[0].setFillColor(sf::Color::White);
  buttons[0].setString("Try Again");
  buttons[0].setPosition(width / 2 - 50, height / 2);

  buttons[1].setFont(font);
  buttons[1].setCharacterSize(24);
  buttons[1].setFillColor(sf::Color::White);
  buttons[1].setString("Exit");
  buttons[1].setPosition(width / 2 - 50, height / 2 + 50);

  selectedItemIndex = 0;
}

EndScreen::~EndScreen() {
  // Destructor (if needed)
}

void EndScreen::Moveup() {
  if (selectedItemIndex - 1 >= 0) {
    buttons[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex--;
    buttons[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void EndScreen::Movedown() {
  if (selectedItemIndex + 1 < 2) {
    buttons[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex++;
    buttons[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void EndScreen::draw(sf::RenderWindow &window) {
  window.draw(endText);
  for (int i = 0; i < 2; i++) {
    window.draw(buttons[i]);
  }
}