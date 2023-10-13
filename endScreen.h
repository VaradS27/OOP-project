#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <SFML/Graphics.hpp>
using namespace sf;

// The `EndScreen` class is like the "Game Over" screen you see when you finish
// a game. When you create an `EndScreen`, you give it the size of your game
// window. It's got a background (`endBackground`) that's a rectangle covering
// the whole screen, and a texture (`endBack`) that's like the design or picture
// on the background. There's some text (`endText`) that gets displayed on the
// screen and it uses a specific font (`font`).
// There's also an `exitButton` that lets you close the game. The `draw`
// function is what puts the end screen on your game window.

class EndScreen {
 public:
  EndScreen(int width, int height);  // default constructor
  ~EndScreen();                      // destructor

  // draw() method for the end screen
  void draw(sf::RenderWindow &window);

 private:
  sf::Font font;        // font for text on the end screen
  sf::Text endText;     // text that will be displayed on the end screen
  sf::Text exitButton;  // Only one button needed
  RectangleShape endBackground;  // End Screen will be a rectangular shape
  Texture endBack;               // Texture for end screen
};

#endif