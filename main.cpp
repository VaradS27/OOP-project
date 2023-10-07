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

// Create function that resets the game, and creates it again.

// g++ -Wall main.cpp background.cpp menu.cpp Shooting.cpp movement.cpp
// playerOne.cpp playerTwo.cpp mine.cpp endScreen.cpp -lsfml-graphics
// -lsfml-window -lsfml-system

int main() {
  // Create an instance of EndScreen
  EndScreen endScreen(1200, 1000);
  RenderWindow window(VideoMode(1200, 1000), "No Tank You");
  Background background;
  PlayerOne player;
  PlayerTwo player_2;
  Menu menu(1200, 1000);
  Mine mine;

  Movement movement;
  movement.setBounds(0, 0, 1200, 1000);

  bool inMenu = true;        // Track if we are in the menu
  bool inEndScreen = false;  // Track if we are in the end screen

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }

      if (inMenu) {
        if (event.type == Event::KeyReleased) {
          switch (event.key.code) {
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
                  inMenu = false;  // Exit the menu
                  break;

                case 1:
                  std::cout << "Pressed Rules" << std::endl;
                  break;

                case 2:
                  std::cout << "Pressed About" << std::endl;
                  break;

                default:
                  break;
              }
              break;

            default:
              break;
          }
        }
      }

      if (!inMenu && !inEndScreen) {
        // Handle game events here
        player.handleInput();
        player_2.handleInput();

        player.ShootingInput(player);
        player_2.ShootingInput(player_2);

        player.health(player, player_2);
        player_2.health(player_2, player);

        background.draw(window);
        mine.draw(window);
        player.draw(window);
        player_2.draw(window);
        // Check collision with the mine
        player.collideHealth(player);

        if (player.getHealth() <= 0 || player_2.getHealth() <= 0) {
          inEndScreen = true;
        }
      }

      window.clear();

      if (!inMenu) {
        if (!inEndScreen) {
          // Clear the window
          window.clear();

          // Draw the background
          background.draw(window);

          // Draw game objects
          mine.draw(window);
          player.draw(window);
          player_2.draw(window);
        } else {
          // Handle end screen events here
          if (event.type == Event::KeyReleased) {
            switch (event.key.code) {
              case sf::Keyboard::Up:
                endScreen.Moveup();
                break;

              case sf::Keyboard::Down:
                endScreen.Movedown();
                break;

              case sf::Keyboard::Return:
                switch (endScreen.GetPressedItem()) {
                  case 0:
                    std::cout << "Pressed Try Again" << std::endl;
                    // Reset the game state here
                    player.reset();
                    player_2.reset();
                    inEndScreen = false;
                    break;

                  case 1:
                    std::cout << "Pressed Exit" << std::endl;
                    window.close();
                    break;

                  default:
                    break;
                }
                break;

              default:
                break;
            }
          }

          endScreen.draw(window);
        }
      } else {
        menu.draw(window);
      }

      window.display();
    }
  }

  return 0;
}