#ifndef UTILS_H
#define UTILS_H
#include <cmath>
#include <random>
#include <tuple>

class Utils {
 public:
  static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(0, gridWidth - 1);
    std::uniform_int_distribution<> distribY(0, gridHeight - 1);
    return std::make_tuple(distribX(gen), distribY(gen));
  }

  static double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
    double x1 = std::get<0>(pos1);
    double y1 = std::get<1>(pos1);
    double x2 = std::get<0>(pos2);
    double y2 = std::get<1>(pos2);
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
  }
};
#endif