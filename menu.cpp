#include "menu.h"

#include <iostream>
using namespace sf;

Menu::Menu(float width, float height) {
  // Set size of menu screen
  menuBackground.setSize(Vector2f(900.0f, 1000.0f));
  // Set position of menu screen
  menuBackground.setPosition(0.0f, 0.0f);
  // Checks if menu screen texture has not loaded
  if (!menuBack.loadFromFile("IntroBackground.png")) {
    std::cout << "Error: Menu Screen Texture has not loaded" << std::endl;
  }
  // Set menu screen texture
  menuBackground.setTexture(&menuBack);
  menuBack.setRepeated(true);

  // Load in the font
  if (!font.loadFromFile("MarsBold.ttf")) {
    std::cout << "Error: Font has not loaded" << std::endl;
  }

  // <~~~~~~~~~FOR PLAY BUTTON~~~~~~~~~>
  // Set font for 1st text
  text[0].setFont(font);
  // Set colour for 1st text
  text[0].setFillColor(sf::Color::Red);
  // Set font size for 1st text
  text[0].setCharacterSize(55);
  // Set 1st text displayed on the menu screen
  text[0].setString("PLAY");
  // Set 1st text position
  text[0].setPosition(sf::Vector2f(
      (width / 2) - 150, (height / (MAX_NUMBER_OF_OPTIONS + 1) * 1) + 125));

  // <~~~~~~~~~FOR RULES BUTTON~~~~~~~~~>
  // Set font for 2nd text
  text[1].setFont(font);
  // Set colour for 2nd text
  text[1].setFillColor(sf::Color::White);
  // Set font size for 2nd text
  text[1].setCharacterSize(55);
  // Set 2nd text displayed on the menu screen
  text[1].setString("RULES");
  // Set 2nd text position
  text[1].setPosition(sf::Vector2f(
      (width / 2) - 150, (height / (MAX_NUMBER_OF_OPTIONS + 1) * 2) + 25));

  // <~~~~~~~~~FOR ABOUT BUTTON~~~~~~~~~>
  // Set font for 3rd text
  text[2].setFont(font);
  // Set colour for 3rd text
  text[2].setFillColor(sf::Color::White);
  // Set font size for 3rd text
  text[2].setCharacterSize(55);
  // Set 3rd text displayed on the menu screen
  text[2].setString("EXIT");
  // Set 3rd text position
  text[2].setPosition(sf::Vector2f(
      (width / 2) - 150, (height / (MAX_NUMBER_OF_OPTIONS + 1) * 3) - 90));

  // Set index to 0
  itemIndex = 0;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow &window) {
  // Draw menu buttons
  window.draw(menuBackground);
  for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; i++) {
    window.draw(text[i]);
  }
}

void Menu::Moveup() {
  // Colour change when user moves up on the menu
  if (itemIndex - 1 >= 0) {
    text[itemIndex].setFillColor(sf::Color::White);
    itemIndex--;
    text[itemIndex].setFillColor(sf::Color::Red);
  }
}

void Menu::Movedown() {
  // Colour change when user moves down on the menu
  if (itemIndex + 1 < MAX_NUMBER_OF_OPTIONS) {
    text[itemIndex].setFillColor(sf::Color::White);
    itemIndex++;
    text[itemIndex].setFillColor(sf::Color::Red);
  }
}
