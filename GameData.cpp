#include "GameData.h"

void save_game(PlayerOne playerOne, PlayerTwo playerTwo) {
  // Output: text file of the following values with name "game_data.txt"
  std::ofstream file("game_data.txt");
  // Variables that will be stored for both players: health, position and
  // rotation
  if (file.is_open()) {
    file << playerOne.getHealth() << "\n";
    file << playerOne.get_tankRect().getPosition().x << "\n";
    file << playerOne.get_tankRect().getPosition().y << "\n";
    file << playerOne.get_barrelRect().getRotation() << "\n";
    file << playerTwo.getHealth() << "\n";
    file << playerTwo.get_tankRect().getPosition().x << "\n";
    file << playerTwo.get_tankRect().getPosition().y << "\n";
    file << playerTwo.get_barrelRect().getRotation() << "\n";
    file.close();
  }
}

void load_game(PlayerOne& playerOne, PlayerTwo& playerTwo) {
  // Open the following file to input the variable such as health, position and
  // rotation for each player
  std::ifstream file("game_data.txt");

  if (file.is_open()) {
    // Initialisation of store varibles
    int health;
    float positionX, positionY, rotation;

    file >> health;
    playerOne.set_playerHealth(health);
    file >> positionX >> positionY;
    // set_playerPosition function to update tank's position
    playerOne.set_playerPosition(positionX, positionY);
    file >> rotation;
    // set_playerRotation function to update the barrel's rotation
    playerOne.set_playerRotation(rotation);

    file >> health;
    playerTwo.set_playerHealth(health);
    file >> positionX >> positionY;
    // set_playerPosition function to update tank's position
    playerTwo.set_playerPosition(positionX, positionY);
    file >> rotation;
    // set_playerRotation function to update the barrel's rotation
    playerTwo.set_playerRotation(rotation);

    file.close();
  }
}