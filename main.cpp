#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "background.h"
#include "menu.h"
#include "playerOne.h"
#include "playerTwo.h"
using namespace sf;  // Use the sf namespace for SFML classes

// g++ -Wall main.cpp background.cpp menu.cpp Shooting.cpp movement.cpp
// playerOne.cpp playerTwo.cpp -lsfml-graphics -lsfml-window -lsfml-system

int main() {
  RenderWindow window(VideoMode(1920, 1080), "No Tank You");
  RenderWindow window1(VideoMode(1920, 1080), "No Tank You");
  Background background;  // Background object
  PlayerOne player;       // This is the playerOne Object
  PlayerTwo player_2;
  Movement movement;
  Menu menu(1920, 1080);  // size of the menu

  // Set boundaries to match the game window size
  movement.setBounds(0, 0, 1920, 1080);

  while (window1.isOpen()) {  // while the window is open
    Event event1;
    while (window1.pollEvent(event1)) {  // While there are events to process
      // If the close event is triggered, close the window
                  if (event1.type == Event::Closed) {
              window1.close();
            }
      if (event1.type == Event::KeyReleased) {
        switch (event1.key.code) {
          case sf::Keyboard::Up:
            menu.Moveup();
            break;

          case sf::Keyboard::Down:
            menu.Movedown();
            break;

          case sf::Keyboard::Return:
            switch (menu.GetPressedItem()) {
              case 0:
                std::cout << "Pressed Play" << std::endl;
                window1.close();
                while (window.isOpen()) {  // while the window is open
                  Event event;
                  while (window.pollEvent(event)) {
                    
                    // While there are events to process
                    // If the close event is triggered, close the window
                    if (event1.type == Event::KeyReleased){window.close();}



                    player.handleInput();  // Call the handleInput method of the
                                           // player object to handle user input
                    player_2.handleInput();

                    player.ShootingInput(player);
                    player_2.ShootingInput(player_2);

                    window.clear();

                    player.health(player, player_2);
                    player_2.health(player_2, player);

                    background.draw(window);          // Draw the background onto the window
                    player.draw(window);  // Draw the player onto the window

                    player_2.draw(window);  // Draw the player 2 onto the window

                    window.display();

                    break;

                    case 1:
                      std::cout << "Pressed Rules" << std::endl;
                      break;

                    case 2:
                      std::cout << "Pressed About" << std::endl;
                      break;

                    
                  }
                }
            }
            default:
            break;
        }
      }

        // Handle player input here and update player position/rotation
        // player.handleInput();  // Call the handleInput method of the player
        // object
        //                        // to handle user input
        // player_2.handleInput();

        // player.ShootingInput(player);
        // player_2.ShootingInput(player_2);

        window.clear();  // Clear the window
        window1.clear();
        // draw the menu
        menu.draw(window1);

        // health display for the players
        //  player.health(player, player_2);
        //  player_2.health(player_2, player);

        // background.draw(window);  // Draw the background onto the window
        // player.draw(window);      // Draw the player onto the window
        // player_2.draw(window);    // Draw the player 2 onto the window
        window.display();  // Display everything on the window
        window1.display();
      }
      return 0;
    }
}
