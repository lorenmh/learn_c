#include "randomf.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis(0,1);

// returns a double between 0 and 1
float randomf() {
  return dis(gen);
}
