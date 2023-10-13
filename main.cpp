#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "GameData.h"
#include "background.h"
#include "endScreen.h"
#include "menu.h"
#include "playerOne.h"
#include "playerTwo.h"

using namespace sf;

// Compiler Command:
// g++ -Wall main.cpp background.cpp menu.cpp Shooting.cpp movement.cpp
// playerOne.cpp playerTwo.cpp GameData.cpp Tank.cpp mine.cpp endScreen.cpp
// -lsfml-graphics -lsfml-window -lsfml-system

int main() {
  // Create game window
  RenderWindow game(VideoMode(900, 1000), "No Tank You");
  // Set game variables
  Background background;
  PlayerOne player;
  PlayerTwo player_2;
  Movement movement;
  // Create menu window
  Menu menu(900, 1000);
  // Create end screen window
  EndScreen endScreen(900, 1000);
  // Set movement boundaries
  movement.setBounds(0, 0, 900, 1000);

  bool inMenu = true;     // Track if we are in the menu
  bool gameOver = false;  // Track if the game is over

  // While the game window is open do the following:
  while (game.isOpen()) {
    Event event;
    while (game.pollEvent(event)) {
      // If the game is closed do the following:
      if (event.type == Event::Closed) {
        // End the game
        game.close();
      }

      // If the game is not over and user is not in the menu screen, then run
      // the following code:
      if (!gameOver || !inMenu) {
        // Check for player health reaching 0
        if (player.getHealth() <= 0 || player_2.getHealth() <= 0) {
          gameOver = true;  // Set gameOver to true
          inMenu = true;    // Return to the menu when the game is over
          // Terminal messages:
          std::cout << "---------Game Over-----------" << std::endl;
          std::cout << "---------Thanks for playing---------" << std::endl;
        }
        // User can save the game by pressing (Left) Ctrl + S
        if (Keyboard::isKeyPressed(Keyboard::S) &&
            Keyboard::isKeyPressed(Keyboard::LControl)) {
          std::cout << "Game Saved" << std::endl;
          // Save data for both playerOne and playerTwo
          save_game(player, player_2);
        }
        // User can load the game by pressing (Left) Ctrl + L
        if (Keyboard::isKeyPressed(Keyboard::L) &&
            Keyboard::isKeyPressed(Keyboard::LControl)) {
          std::cout << "Game Loaded" << std::endl;
          // Load data for both playerOne and playerTwo
          load_game(player, player_2);
          // Redraw the players
          player.draw(game);
          player_2.draw(game);
        }
      }

      // If the player is in the menu screen
      if (inMenu) {
        if (event.type == Event::KeyReleased) {
          switch (event.key.code) {
            case Keyboard::Up:
              menu.Moveup();  // Move selection up
              break;

            case Keyboard::Down:
              menu.Movedown();  // Move selection down
              break;

            case Keyboard::Return:
              if (gameOver) {
                // If the game is over and Enter is pressed, exit the game
                game.close();
              } else {
                switch (menu.GetPressedItem()) {
                  // If PLAY is pressed, run the following:
                  case 0:
                    std::cout << "---------Pressed Play----------" << std::endl;
                    inMenu = false;  // Exit the menu
                    break;
                  // If RULES is pressed, run the following:
                  case 1:
                    std::cout << "---------Pressed Rules---------" << std::endl;
                    // logic for displaying rules
                    std::cout << "The objective of the game is to destroy the "
                                 "enemy tank whilst dodging the enemy bullets."
                              << std::endl;
                    std::cout << "Each tank has 10 health with the bullets "
                                 "dealing 1 damage point."
                              << std::endl;
                    std::cout
                        << "| Player 1's controls :- 'W','A','S','D','SPACE' |"
                        << std::endl;
                    std::cout << "| Player 2's controls :- "
                                 "'Up-Arrow','Left-Arrow','Down-Arrow','Right-"
                                 "Arrow','Left-Shift' |"
                              << std::endl;
                    std::cout << std::endl;
                    std::cout << "| TO SAVE THE GAME PRESS (LEFT) CTRL + S |"
                              << std::endl;
                    std::cout << "| TO LOAD THE GAME PRESS (LEFT) CTRL + L |"
                              << std::endl;

                    break;
                  // If EXIT is pressed, run the following:
                  case 2:
                    std::cout << "---------Pressed Exit---------" << std::endl;
                    std::cout << "---------Thanks for playing---------"
                              << std::endl;
                    game.close();
                    break;
                  // Else exit
                  default:
                    break;
                }
              }
              break;
            // Else exit
            default:
              break;
          }
        }

        // Draw the menu on the game window
        menu.draw(game);
      }
    }
    // Clear the game
    game.clear();
    // If the user is not in the menu screen
    if (!inMenu) {
      // The following handles the game events:
      // Movement inputs
      player.handleInput();
      player_2.handleInput();
      // Shooting inputs
      player.ShootingInput(player);
      player_2.ShootingInput(player_2);
      // Checks for health changes
      player.health(player, player_2);
      player_2.health(player_2, player);
      // Draws the background, playerOne and playerTwo on the game window
      background.draw(game);
      player.draw(game);
      player_2.draw(game);
    } else {
      // Else if the game is over run the following:
      if (gameOver) {
        // Display the end screen
        endScreen.draw(game);
      } else {
        // Draw the menu only if the game is not over
        menu.draw(game);
      }
    }
    // display the game window
    game.display();
  }

  return 0;
}