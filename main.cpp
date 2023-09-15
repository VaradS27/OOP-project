#include <SFML/Graphics.hpp>
#include <iostream>

#include "background.h"
#include "playerOne.h"
using namespace sf;  // Use the sf namespace for SFML classes

// g++ -Wall main.cpp background.cpp movement.cpp playerOne.cpp -lsfml-graphics -lsfml-window -lsfml-system

int main() {
  // Currently the window is on a 4:3 ratio
  // ****can be changed later****
  RenderWindow window(VideoMode(800, 600), "Tank v1 Game");
  Background background;  // Background object
  PlayerOne player;       // This is the playerOne Object
  Movement movement;
  // Set boundaries to match the game window size
  movement.setBounds(0, 0, 800, 600);

  while (window.isOpen()) {  // while the window is open
    Event event;
    while (window.pollEvent(event)) {  // While there are events to process
      // If the close event is triggered, close the window
      if (event.type == Event::Closed) {
        window.close();
      }
    }

    // Handle player input here and update player position/rotation
    player.handleInput();  // Call the handleInput method of the player object
                           // to handle user input
    window.clear();        // Clear the window
    background.draw(window);  // Draw the background onto the window
    player.draw(window);      // Draw the player onto the window
    window.display();         // Display everything on the window
  }
  return 0;
}
