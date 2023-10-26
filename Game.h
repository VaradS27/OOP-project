#ifndef GAME_H
#define GAME_H
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#include "Cell.h"
#include "Character.h"
#include "Effect.h"
#include "Trap.h"
#include "Utils.h"

class Game {
 private:
  std::vector<Cell*> grid;
  int gridWidth;
  int gridHeight;

 public:
  std::vector<Cell*>& getGrid() { return grid; }
  void initGame(int numCharacters, int numTraps, int width, int height) {
    gridWidth = width;
    gridHeight = height;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(0, gridWidth - 1);
    std::uniform_int_distribution<> distribY(0, gridHeight - 1);
    for (int i = 0; i < numCharacters; i++) {
      int x = distribX(gen);
      int y = distribY(gen);
      Character* character = new Character(x, y);
      grid.push_back(character);
    }
    for (int i = 0; i < numTraps; i++) {
      int x = distribX(gen);
      int y = distribY(gen);
      Trap* trap = new Trap(x, y);
      grid.push_back(trap);
    }
  }
  void gameLoop(int maxIterations, double trapActivationDistance) {
    for (int iteration = 1; iteration <= maxIterations; iteration++) {
      for (Cell* cell : grid) {
        if (cell->getType() == 'C') {
          Character* character = dynamic_cast<Character*>(cell);
          character->move(1, 0);
        }
      }
      for (Cell* cell : grid) {
        if (cell->getType() == 'C') {
          Character* character = dynamic_cast<Character*>(cell);
          for (Cell* otherCell : grid) {
            if (otherCell->getType() == 'T') {
              Trap* trap = dynamic_cast<Trap*>(otherCell);
              std::tuple<int, int> charPos = character->getPos();
              std::tuple<int, int> trapPos = trap->getPos();
              double distance = calculateDistance(charPos, trapPos);
              if (distance <= trapActivationDistance) {
                trap->apply(*character);
              }
            }
          }
        }
      }
      for (Cell* cell : grid) {
        if (cell->getType() == 'C') {
          Character* character = dynamic_cast<Character*>(cell);
          std::tuple<int, int> charPos = character->getPos();
          if (std::get<0>(charPos) < 0 || std::get<0>(charPos) >= gridWidth ||
              std::get<1>(charPos) < 0 || std::get<1>(charPos) >= gridHeight) {
            std::cout << "Character has won the game!" << std::endl;
            return;
          }
        }
      }
    }
    std::cout << "Maximum number of iterations reached. Game over." << std::endl;
  }
 private:
  double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
    double x1 = std::get<0>(pos1);
    double y1 = std::get<1>(pos1);
    double x2 = std::get<0>(pos2);
    double y2 = std::get<1>(pos2);
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
  }
};

#endif