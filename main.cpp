#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "background.h"
#include "endScreen.h"
#include "menu.h"
#include "mine.h"
#include "playerOne.h"
#include "playerTwo.h"

using namespace sf;

// g++ -Wall main.cpp background.cpp menu.cpp Shooting.cpp movement.cpp
// playerOne.cpp playerTwo.cpp Tank.cpp mine.cpp endScreen.cpp -lsfml-graphics
// -lsfml-window -lsfml-system

int main() {
  RenderWindow game(VideoMode(1200, 1000), "No Tank You");
  Background background;
  PlayerOne player;
  PlayerTwo player_2;
  Menu menu(1200, 1000);
  Mine mine;
  EndScreen endScreen(1200, 1000);

  Movement movement;
  movement.setBounds(0, 0, 1200, 1000);

  bool inMenu = true;     // Track if we are in the menu
  bool gameOver = false;  // Track if the game is over

  while (game.isOpen()) {
    Event event;
    while (game.pollEvent(event)) {
      if (event.type == Event::Closed) {
        game.close();
      }

      if (!gameOver && !inMenu) {
        // Check for player health reaching 0
        if (player.getHealth() <= 0 || player_2.getHealth() <= 0) {
          gameOver = true;
          inMenu = true;  // Return to the menu when the game is over
          // Add any additional actions you want when the game is over
        }
      }

      if (inMenu) {
        if (event.type == Event::KeyReleased) {
          switch (event.key.code) {
            case sf::Keyboard::Up:
              menu.Moveup();  // Move selection up
              break;

            case sf::Keyboard::Down:
              menu.Movedown();  // Move selection down
              break;

            case sf::Keyboard::Return:
              if (gameOver) {
                // If the game is over and Enter is pressed, exit the game
                game.close();
              } else {
                switch (menu.GetPressedItem()) {
                  case 0:
                    std::cout << "Pressed Play" << std::endl;
                    inMenu = false;  // Exit the menu
                    break;

                  case 1:
                    std::cout << "Pressed Rules" << std::endl;
                    // Add logic for displaying rules
                    break;

                  case 2:
                    std::cout << "Pressed About" << std::endl;
                    // Add logic for displaying information about the game
                    break;

                  default:
                    break;
                }
              }
              break;

            default:
              break;
          }
        }

        // Draw the menu on the game window
        menu.draw(game);
      }
    }

    game.clear();

    if (!inMenu) {
      // Handle game events here
      player.handleInput();
      player_2.handleInput();

      player.ShootingInput(player);
      player_2.ShootingInput(player_2);

      player.health(player, player_2);
      player_2.health(player_2, player);

      background.draw(game);
      mine.draw(game);
      player.draw(game);
      player_2.draw(game);
      // check collision with the mine
      player.collideHealth(player);
      // player_2.collideHealth(player_2);
    } else {
      if (gameOver) {
        // Display the end screen
        endScreen.draw(game);
      } else {
        // Draw the menu only if the game is not over
        menu.draw(game);
      }
    }

    game.display();
  }

  return 0;
}