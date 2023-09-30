#include "background.h"

#include <ctime>
#include <iostream>
#include <random>

#include "barrel.h"
#include "math.h"
using namespace sf;
using namespace std;
// Background image from :
// https://www.freepik.com/free-photo/green-clay-textured-background-colorful-handmade-creative-art-abstract-style_18141576.htm#page=2&query=low%20poly%20grass%20texture&position=1&from_view=search&track=ais
// by rawpixel.com on Freepik
Background::Background() {
  // Set the size of the background
  backgroundRect.setSize(Vector2f(800.0f, 800.0f));
  backgroundRect.setPosition(0.0f, 0.0f);
  if (!backgroundTexture.loadFromFile("grassBackground.png")) {
    // handle error...
  }
  backgroundRect.setTexture(&backgroundTexture);
  backgroundTexture.setRepeated(true);

  cords_X = new float[7]; // stores the x cords of the mines
  cords_Y = new float[7]; // stores the y cords of the mines
  for (int i = 0; i < 7; i++) {
    // Create a random device
    random_device rd;

    // Initialize a random number generator engine
    default_random_engine eng(rd());

    // Define the distribution
    uniform_real_distribution<float> distrX(0.0, 800.0);
    uniform_real_distribution<float> distrY(0.0, 800.0);

    // Generate random x and y coordinates within the boundaries
    float x = distrX(eng);
    cords_X[i] = x;
    float y = distrY(eng);
    cords_Y[i] = y;

    barrels.push_back(Barrel(x, y));
  }
}

void Background::draw(RenderWindow& window) {
  // Draw the background to the window
  window.draw(backgroundRect);
  for (auto& barrel : barrels) {
    barrel.draw(window);
    // std::cout << "Position: " << barrel.getPosition().x << std::endl;
  }
}

float* Background::get_cordsX(){
return cords_X;
}
float* Background::get_cordsY(){
return cords_Y;
}