#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "background.h"
#include "menu.h"
#include "playerOne.h"
#include "playerTwo.h"
#include "mine.h"

using namespace sf;
// g++ -Wall main.cpp background.cpp Shooting.cpp movement.cpp playerOne.cpp playerTwo.cpp menu.cpp barrel.cpp -lsfml-graphics -lsfml-window -lsfml-system
int main() {
  RenderWindow window(VideoMode(1200, 1000), "No Tank You");
  Background background;
  PlayerOne player;
  PlayerTwo player_2;
  Menu menu(1200, 1000);
  Mine mine;

  Movement movement;
  movement.setBounds(0, 0, 1200, 1000);

  bool inMenu = true;  // Track if we are in the menu

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
    }

    window.clear();

    if (!inMenu) {
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
      // check collision with the mine
      player.collideHealth(player);

    } else {
      menu.draw(window);
    }

    window.display();
  }

  return 0;
}