#include "menu.h"
using namespace sf;

Menu::Menu(float width, float height) {
  // Background for the menu
  menuBackground.setSize(Vector2f(900.0f, 1000.0f));
  menuBackground.setPosition(0.0f, 0.0f);
  if (!menuBack.loadFromFile("IntroBackground.png")) {
    // handle error...
  }
  menuBackground.setTexture(&menuBack);
  menuBack.setRepeated(true);

  // load in the font
  if (!font.loadFromFile("MarsBold.ttf")) {
    // handling error
  }
  // play button for the game
  text[0].setFont(font);
  text[0].setFillColor(sf::Color::Red);
  text[0].setCharacterSize(55);
  text[0].setString("PLAY");
  text[0].setPosition(
      sf::Vector2f((width / 2)-150, (height / (MAX_NUMBER_OF_OPTIONS + 1) * 1)+125));

  // rules of the game
  text[1].setFont(font);
  text[1].setFillColor(sf::Color::White);
  text[1].setCharacterSize(55);
  text[1].setString("RULES");
  text[1].setPosition(
      sf::Vector2f((width / 2)-150, (height / (MAX_NUMBER_OF_OPTIONS + 1) * 2)+25));

  // about the game
  text[2].setFont(font);
  text[2].setFillColor(sf::Color::White);
  text[2].setCharacterSize(55);
  text[2].setString("EXIT");
  text[2].setPosition(
      sf::Vector2f((width / 2)-150, (height / (MAX_NUMBER_OF_OPTIONS + 1) * 3)-90));

  itemIndex = 0;
}
Menu::~Menu() {}
void Menu::draw(sf::RenderWindow &window) {
  window.draw(menuBackground);
  for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; i++) {
    window.draw(text[i]);
  }
}
void Menu::Moveup() {
  if (itemIndex - 1 >= 0) {
    text[itemIndex].setFillColor(sf::Color::White);
    itemIndex--;
    text[itemIndex].setFillColor(sf::Color::Red);
  }
}
void Menu::Movedown() {
  if (itemIndex + 1 < MAX_NUMBER_OF_OPTIONS) {
    text[itemIndex].setFillColor(sf::Color::White);
    itemIndex++;
    text[itemIndex].setFillColor(sf::Color::Red);
  }
}
