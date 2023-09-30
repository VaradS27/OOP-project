#include "menu.h"
using namespace sf;

Menu::Menu(float width, float height) {
  if (!font.loadFromFile("arial.ttf")) {
    // handling error
  }
  // play button for the game
  text[0].setFont(font);
  text[0].setFillColor(sf::Color::Red);
  text[0].setString("PLAY");
  text[0].setPosition(
      sf::Vector2f((width / 2), (height / (MAX_NUMBER_OF_OPTIONS + 1) * 1)));

  // rules of the game
  text[1].setFont(font);
  text[1].setFillColor(sf::Color::White);
  text[1].setString("RULES");
  text[1].setPosition(
      sf::Vector2f((width / 2), (height / (MAX_NUMBER_OF_OPTIONS + 1) * 2)));

  // about the game
  text[2].setFont(font);
  text[2].setFillColor(sf::Color::White);
  text[2].setString("ABOUT");
  text[2].setPosition(
      sf::Vector2f((width / 2), (height / (MAX_NUMBER_OF_OPTIONS + 1) * 3)));

  itemIndex = 0;
}
Menu::~Menu() {}
void Menu::draw(sf::RenderWindow &window) {
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