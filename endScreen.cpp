#include "endScreen.h"

#include <iostream>
using namespace sf;

EndScreen::EndScreen(int width, int height) {
  // Set Background size for the end screen
  endBackground.setSize(Vector2f(900.0f, 1000.0f));
  // Set background position for end screen
  endBackground.setPosition(0.0f, 0.0f);
  // Checks if theres an error when loading the texture for the end screen
  if (!endBack.loadFromFile("EndBackground.png")) {
    std::cout << "Error: Failed to load End Screen Background" << std::endl;
  }
  // <~~~~~~~~~FOR GAME OVER TEXT~~~~~~~~~>
  // Set end screen background texture
  endBackground.setTexture(&endBack);
  endBack.setRepeated(true);
  // Load font
  font.loadFromFile("MarsBold.ttf");
  // Set up end text
  endText.setFont(font);
  // Set font size
  endText.setCharacterSize(64);
  // Set font colour
  endText.setFillColor(sf::Color::Red);
  // Text that will be displayed on the end screen
  endText.setString("Game Over");
  // Position of the text on the end screen
  endText.setPosition(width / 2 - 375, height / 2 - 200);

  // <~~~~~~~~~FOR EXIT TEXT~~~~~~~~~>
  // Set up exit button
  exitButton.setFont(font);
  // Size of second text 
  exitButton.setCharacterSize(30);
  // Set colour for exit text
  exitButton.setFillColor(sf::Color::Red);
  // Text that will be displayed on the end screen
  exitButton.setString(
      " Press "
      "Enter"
      " to Exit");
  // Position of the text above
  exitButton.setPosition(width / 2 - 350, height / 2 - 100);
}

void EndScreen::draw(sf::RenderWindow &window) {
  window.draw(endBackground); // Draw the end screen background
  window.draw(endText); // Draw end screen text
  window.draw(exitButton);  // Draw the exit button
}
EndScreen::~EndScreen() {
  // Destructor (if needed)
}
