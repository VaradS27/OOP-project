#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
using namespace sf;

// The `Background` class in your code is used to manage the background of your
// game window. Here's a brief explanation of its functionality:

// - RectangleShape backgroundRect: This is a private member that represents
// the shape of the background. It's a rectangle that will cover the entire game
// window.

// - Texture backgroundTexture: This is a private member that holds the
// texture of the background.

// - Background(): This is the default constructor for the `Background`
// class. It's used to initialize a new instance of the class.

// - void draw(RenderWindow& window): This is a public member function that
// draws the background on the game window. It takes a reference to a
// `RenderWindow` object.

class Background {
 private:
  RectangleShape backgroundRect;  // Rectangular background
  Texture backgroundTexture;      // Bacground Texture
 public:
  Background();  // default constructor for background
  void draw(
      RenderWindow& window);  // draw() to draw background in 'game' window
};

#endif