#include "GameData.h"

void save_game(PlayerOne playerOne, PlayerTwo playerTwo) {
  std::ofstream file("game_data.txt");

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

void load_game(PlayerOne &playerOne, PlayerTwo &playerTwo) {
  std::ifstream file("game_data.txt");

  if (file.is_open()) {
    int health;
    float positionX, positionY, rotation;

    file >> health;
    playerOne.set_playerHealth(health);
    file >> positionX >> positionY;
    playerOne.get_tankRect().setPosition(positionX, positionY);
    file >> rotation;
    playerOne.get_barrelRect().setRotation(rotation);

    file >> health;
    playerTwo.set_playerHealth(health);
    file >> positionX >> positionY;
    playerTwo.get_tankRect().setPosition(positionX, positionY);
    file >> rotation;
    playerTwo.get_barrelRect().setRotation(rotation);

    file.close();
  }
}
