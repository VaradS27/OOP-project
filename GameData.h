#include <fstream>
#include <iostream>

#include "playerOne.h"
#include "playerTwo.h"

// Function to save the game state
void save_game(PlayerOne playerOne, PlayerTwo playerTwo);
// Function to load the game state
void load_game(PlayerOne &playerOne, PlayerTwo &playerTwo);