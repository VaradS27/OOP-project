#include <SFML/Graphics.hpp>
#include <iostream>

#include "background.h"
#include "playerOne.h"
#include "playerTwo.h"
using namespace sf;  // Use the sf namespace for SFML classes

// g++ -Wall main.cpp background.cpp Shooting.cpp movement.cpp playerOne.cpp playerTwo.cpp -lsfml-graphics -lsfml-window -lsfml-system

int main() {
  RenderWindow window(VideoMode(1920, 1080), "Tank v2 Game");
  Background background;  // Background object
  PlayerOne player;       // This is the playerOne Object
  PlayerTwo player_2;
  Movement movement;
  // Set boundaries to match the game window size
  movement.setBounds(0, 0, 1920, 1080);

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
    player_2.handleInput();

    player.ShootingInput(player);
    player_2.ShootingInput(player_2);

    window.clear();        // Clear the window

    // health display for the players
    player.health(player);
    player_2.health(player_2);

    background.draw(window);  // Draw the background onto the window
    player.draw(window);      // Draw the player onto the window
    player_2.draw(window);    // Draw the player 2 onto the window
    window.display();         // Display everything on the window
  }
  return 0;
}
